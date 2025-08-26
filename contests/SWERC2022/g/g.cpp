#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i =(b)-1;i>=int(a);--i)
#define debug 0
#define debug2 0
#define ifd2 if(debug2)
#define ifd if(debug)

// Lazy es el update pendiente en un nodo
struct Lazy {
    // lo que sea que hay que update
    ll x;
    // el neutro de esos updates
    static Lazy zero() {return {0};}
    // retorna si esa vara es igual al neutro del lazy
    bool is_zero() { return x == 0; } /// moralmente `*this == Lazy::zero()`
};

// lo que sí hay en cada nodo
struct Mono { 
    // el valor en ese nodo
    ll x;
    // el neutro de ese valor
	static Mono zero() {return {0};}
    // a este mono, métale el x de este lazy d
	void apply_lazy(Lazy d, int l, int r) { x += d.x*(r-l); }
};

// para mezclar dos lazies
Lazy operator+ (Lazy a, Lazy b) { return {a.x + b.x}; }
// para mezclar dos Monos
Mono operator+ (Mono a, Mono b) { return {a.x + b.x}; }


// ahora sí, de a de veritas
struct SegtreeLazy {
    // length de la vara
	int len; 
    // la data que hay en cada nodo
    vector<Mono> data; 
    // los updates pendientes que hay en cada nodo
    vector<Lazy> lazy;
    // dado un vector de Monos, cree la vara
	void init(vector<Mono>& a, int n) { assert(n>0); // O(n+len)
		len=1<<(31-__builtin_clz(2*n-1));
		data.assign(2*len, Mono::zero());
		lazy.assign(2*len, Lazy::zero());
		if (a.size()) forn(i, n) data[i+len] = a[i];
		dforr(i, 1, len) data[i] = data[i*2] + data[i*2+1];
	}
    int ql, qr;
    // propague lo que tenga en el nodo i, sabiendo que responde por el intervalo [l, r)
    void p_(int i, int l, int r) {
        // si el mae no tiene nada, no propague nada
		if (lazy[i].is_zero()) return;
        // si el mae no es hoja, propaguele a sus hijos lo que tenga que propagarles
		if (i < len) {
			lazy[2*i] = lazy[2*i] + lazy[i];
			lazy[2*i+1] = lazy[2*i+1] + lazy[i];
		}
        // actualice este mono con lo que tenga en el lazy
		data[i].apply_lazy(lazy[i], l, r);
        // guarde que ya ese mae no tiene nada que updatear
		lazy[i] = Lazy::zero();
	}
    // en este momento está actualizando el nodo i, que responde de l a r, 
    // sabiendo que el intervalo que le interesa ahorita es [ql, qr)
    void u_(int i, int l, int r, Lazy x) {
        // si la vara es hoja, no haga nada
		if (l == r) return;
        // propague lo que tenga en el nodo i, sabiendo que responde por el intervalo [l, r)
		p_(i,l,r);
        // si el mae está out of range, todo bien vdd
		if (r <= ql || qr <= l) return;
        // si está completamente contenido, entonces solo haga el update en su lazy, y ya
		if (ql <= l && r <= qr) {
			lazy[i] = lazy[i] + x;
			p_(i,l,r);
			return;
		}
        
		int m = (l+r)/2;
        // haga update a la izq y derecha
		u_(i*2,l,m,x); u_(i*2+1,m,r,x);
        // ahora actualice su mae
		data[i] = data[2*i] + data[2*i+1];
	}
    // haga un update de [l, r)
	void update(int l, int r, Lazy x) { ql = l; qr = r; u_(1, 0, len, x); }
	// hace un query estando en el nodo i, que responde por [l, r)
    // sabiendo que usted busca [ql, qr)
	Mono q_(int i, int l, int r) {
        // si el mae está afuera, no haga nada
		if (r <= ql || qr <= l) return Mono::zero();
        // propague por si las mosquis
		p_(i,l,r);
        // si el mae está completamente contenido, entonces 
		if (ql <= l && r <= qr) return data[i];
		int m = (l+r)/2;
        // sino, entonces haga query de izq y der
		return q_(i*2,l,m) + q_(i*2+1,m,r);
	}
	// haga un query de l a r
    Mono query(int l, int r) { ql = l; qr = r; return q_(1, 0, len); }


    int search(int n) {
        forn(i, 2*n-1) if (data[i+len].x>=n) return i;
        return -1;
    }
};


vector<ll> pSum;
// le dice cuánto suma la vara original de [l, r]
ll suma(int l, int r) {
    ifd cout<<"buscando suma desde "<<l<<" hasta "<<r<<endl;
    ll ans=pSum[r];
    ifd cout<<"suma hasta "<<r<<" = "<<pSum[r]<<endl;
    if (l>0) {
        ifd cout<<"suma antes de "<<l<<" = "<<pSum[l-1]<<endl;
        ans-=pSum[l-1];
    }
    ifd cout<<"de donde ans = "<<ans<<endl;
    return ans;
}
// me tira cuántas windows de tamaño al menos n hay tq suman cero 
ll ceros (vector<int>&v, int n) {
    ll ans=0;
    bool open=false;
    int i1=0, i2=0;
    forn(i, 2*n-1) {
        if (v[i]==0) {
            if (!open) { open=true; i1=i; }
            else i2=i;
        } else {
            if (open) {
                open=false;
                ans += max(0, (i2 - i1 + 1) - (n-1));
            }
        }
    }
    if(open) ans += max(0, ( (2*n-2) - i1 + 1 ) - (n-1)); 
    ifd2 cout<<"ceros = "<<ans<<endl;
    return ans;
}




int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    
    vector<int> v;
    pSum.resize(2*n-1);
    v.resize(2*n-1);
    forn(i,2*n-1) {
        char c; cin>>c;
        // 0 si es R, 1 si es W
        v[i]=(c=='W');
        pSum[i]=v[i];
        if (i>0) pSum[i]+=pSum[i-1];
    }
    ifd {
        cout<<"v se ve: "<<endl;
        for(auto u:v) cout<<u<<" ";
        cout<<endl;
        cout<<"pSum se ve: "<<endl;
        for(auto u:pSum) cout<<u<<" ";
        cout<<endl;
    }
    ll maxV=pSum[2*n-2];
    vector<Mono> a(maxV+5);
    SegtreeLazy st; st.init(a, maxV+5);

    // PRIMERO VEA A VER SI USTED PUEDE HACER LOS GRUPOS CON CERO
    if (ceros(v, n)>=n) {
        
        cout<<0<<endl;
        return 0;
    }

    // OK, AHORA SABEMOS QUE DE FIJO LA SUMA TIENE QUE SER POSITIVA
    // vea que de fijo nunca quiere un windo que empiece en un punto donde no pueda tener al menos n-1 maes al frente
    for(int i=0; i<2*n-1; i++) {
        ifd cout<<"me fijo en "<<i<<endl;

        if (i<n) {
            ifd cout<<"vea que aún forma window"<<endl;
            int l = suma(i, i+n-1);
            ifd cout<<"vea que la suma de su window de "<<n<<" maes es "<<l<<endl;
            int r = suma(i, 2*n-2);
            ifd cout<<"la suma de "<<i<<" al final es "<<r<<endl;
            st.update(l, r+1, {1});
        }

        if (v[i]==0 and i>=n) {
            ifd cout<<"vea que tiene un 0 y windows detrás suyo"<<endl;
            int l = suma(i-n, i-1);
            ifd cout<<"vea que la suma del window detrás suyo es "<<l<<endl;
            int r =suma(0, i-1);
            ifd cout<<"vea que la suma del window hasta el inicio es "<<r<<endl;
            st.update(l, r+1, {1});
        }

    }
    
    int ans=st.search(n);

    cout<<ans<<"\n";


}
