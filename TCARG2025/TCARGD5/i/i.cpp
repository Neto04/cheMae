#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)

typedef long long ll;
typedef pair<int, int> ii;
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
const int MAXN=100100;
const ll INF=1e9+7;

#define debug 1
#define ifd if (debug)

struct Mono {
    
	ll val;
    // return elemento neutro
	static Mono zero() { return {0}; } // neutro de la suma
};
Mono operator+ (Mono a, Mono b) {
	return {min(a.val, b.val)};
} // asociativo


struct Segtree {
	int len; vector<Mono> data;
    
	void init(vector<Mono>&a, int n) { assert(n>0); // O(n+len)
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
	void update(int i, Mono x) {
        // primero la hoja
		i += len; data[i] = x;
        // luego vaya de abajo a arriba
        while (i /= 2) data[i] = data[i*2] + data[i*2+1];
	}

	int ql, qr;
    // sabiendo que está en el nodo i, revise qué hay en [l, r)
	Mono q_(int i, int l, int r) {
        // si i está completamente disjunto, retorne el nulo
		if (r <= ql || qr <= l) return Mono::zero();
        // si está completamente contenido, retorne ese nodo
		if (ql <= l && r <= qr) return data[i];
		int m = (l+r)/2;
        // retorne la intersección de los dos maes
		return q_(i*2,l,m) + q_(i*2+1,m,r);
	}
    // preguntan por l, r, sepa que va a empezar desde el nodo 1 preguntando por (0, len)
	Mono query(int l, int r) { ql = l; qr = r; return q_(1, 0, len); }

    // sabiendo que está en el nodo i, que responde por [l, r) revise qué hay en [l, r)
    ll sQ_(int i, int l, int r, int x) {
        if (i>=len) return (data[i].val>=x);
        // si i está completamente disjunto, retorne el nulo
		if (r <= ql || qr <= l) return 0;
        if (data[i].val>=x) return r-l;

		int m = (l+r)/2;
        ll ans = sQ_(i*2, l, m, x) + sQ_(i*2+1,m,r, x);
        return ans;
	}
};




int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin>>n;
    vector<Mono> v(n);
    forn(i, n) {
        cin>>v[i].val;
        v[i].val=min(n, v[i].val);
    }
    Segtree st; st.init(v, n);
    ll ans =0;

    forn(i, n) {
        ll r =v[i].val;
        ll l = i+1;
        if (r<l) continue; 
        ifd cout<<" voy a buscar de "<<l<<" a "<<r<<" algo que tenga al menos "<<i+1<<" temporadas"<<endl;
        ans+=st.sQ_(0, l, r+1, i+1);
    }
    cout<<ans<<endl;
    
}
