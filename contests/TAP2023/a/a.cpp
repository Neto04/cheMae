// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)

typedef long long ll;
typedef pair<int, int> ii;
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
const int MAXN=100100;


#define debug 0
#define ifd if (debug)
const ll INF = 1e9;
struct Mono {
    
	ll val;
    // return elemento neutro
	static Mono zero() { return {INF}; } // neutro de la operación
};
Mono operator+ (Mono a, Mono b) {
	return {min(a.val, b.val)};
} // asociativo


struct Segtree {
	ll len; vector<Mono> data;
    
	void init(vector<Mono>&a, ll n) { assert(n>0); // O(n+len)
		// len =  min k tq 2^k>=n
		len=1<<(31-__builtin_clz(2*n-1));
		// y usted mete len*2
		data.assign(len*2, Mono::zero());
        // revise que la vara exista, y en las hojas usted mete a[i]
		if (!a.empty()) forn(i, n) data[i+len] = a[i];
        // ahora, de las hojas patrás retorne la combinación de las dos
		dforr(i, 1, len) data[i] = data[i*2] + data[i*2+1];
	}

    // actualice el mae en i a x
	void update(ll i, Mono x) {
        // primero la hoja
		i += len; data[i] = x;
        // luego vaya de abajo a arriba
        while (i /= 2) data[i] = data[i*2] + data[i*2+1];
	}

	ll ql, qr;
    // sabiendo que está en el nodo i, revise qué hay en [l, r)
	Mono q_(ll i, ll l, ll r) {
        // si i está completamente disjunto, retorne el nulo
		if (r <= ql || qr <= l) return Mono::zero();
        // si está completamente contenido, retorne ese nodo
		if (ql <= l && r <= qr) return data[i];
		ll m = (l+r)/2;
        // retorne la llersección de los dos maes
		return q_(i*2,l,m) + q_(i*2+1,m,r);
	}
    // sabiendo que está en el nodo i, el primer valor en l a r tq es <x
    ll querysota(ll i, ll l, ll r, ll x) {
        // si i está completamente disjunto o es mayor a x, retorne el nulo
		if (r <= ql || qr <= l||data[i].val>x) return Mono::zero().val;

        if (i>=len) return i-len;
        ll m = (l+r)/2;
        if (data[2*i].val<=x) return querysota(2*i, l, m, x);
        return querysota(2*i+1, m, r, x);
    }


    // preguntan por l, r, sepa que va a empezar desde el nodo 1 preguntando por (0, len)
	ll query(ll l, ll r, ll x) { ql = l; qr = r; return querysota(1, 0, len, x); }
};




int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);


    int n, m; cin>>n>>m;
    vector<ll> pedidos(n);
    vector<Mono> gente(m);
    forn(i, n) cin>>pedidos[i];
    forn(i, m) cin>>gente[i].val;

    Segtree st; st.init(gente, m);

    ll ans=0;

    forn(i, n) {
        ll x = pedidos[i];
        ll start=0;
        while (start<m) {
            ifd cout<<"ahorita x = "<<x<<endl;
            ll indx = st.query(start, m, x);
            ifd cout<<"el primer mae de izq a der < x está en la pos "<<indx<<endl;
            if (indx>m) break;
            x = (x%gente[indx].val);
            ifd cout<<"de donde ahora x = "<<x<<endl;
            start = indx+1;
            ifd cout<<"y por lo tanto start = "<<start<<endl;
        }
        cout<<x<<((i<n-1)?" ":"\n");


    }


    
    
}
