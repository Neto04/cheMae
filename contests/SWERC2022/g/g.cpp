#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i =(b)-1;i>=int(a);--i)
#define debug 1
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
	void apply_lazy(Lazy d, int l, int r) { x += d.x; }
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
};
vector<ll> pSum;
// le dice cuánto suma la vara original de [l, r)
ll suma(int l, int r) {
    ll ans=pSum[r];
    if (l>0) ans-=pSum[l-1];
    return ans;
}



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;

    vector<int> v(2*n-1);
    pSum.resize(2*n-1);
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
    ll maxV=pSum[2*n];
    vector<Mono> a(maxV+5);
    SegtreeLazy st; st.init(a, maxV+5);
    // cree la primera ventana de tamaño n
    // vea que de fijo no le interesa nada con ella
    // al principio guarde que la suma de los primeros n se puede una vez
    for(int i1=0, i2=n-1; i2<2*n-1; i1++, i2++) {
        ifd cout<<"ahorita i1 = "<<i1<<", e i2 = "<<i2<<endl;
        int cL=suma(i1, i2);
        int cR=suma(0, i2)+1;
        ifd cout<<"cL= "<<cL<<", cR = "<<cR<<endl;
        // [l, r)
        st.update(cL, cR, {1});
    }
    int ans=-1;
    for(int i=0; i<=2*n-1; i++) {
        ll cQ=st.query(i, i+1).x;
        ifd cout<<"la suma "<<i<<" aparece "<<cQ<<" veces"<<endl;
        if (cQ>=n) {
            ans=i;
            break;
        }
    }

    cout<<ans<<"\n";


}
