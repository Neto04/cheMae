// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
const int MAXN=100100;
const ll INF=1e9+7;


#define debug 0
#define ifd if (debug)

struct Mono {
    
	ll val;
    // return elemento neutro
	static Mono zero() { return {INF}; } // neutro de la min
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
};








int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    vector<Mono> v(m);
    Segtree st; st.init(v, m);
    // me dice cuanto suma en este momento en la casilla i
    vector<ll> curr(m);
    ll bestAns=0;
    forn(i, n) {
        ifd cout<<"fila "<<i<<endl;
        forn(j, m) {
            char c; cin>>c;
            if(c=='0') curr[j]=0;
            else curr[j]++;

            st.update(j, {curr[j]});
        }
        // sea j donde empieza el window
        forn(j, m) {
            // usted tiene un window de [j, k)
            for(int k=j+1; k<=m; k++) {
                ll dist = k-j;
                ll height = st.query(j, k).val;
                bestAns=max(bestAns, dist*height);
            }
        }
    }
    cout<<bestAns<<"\n";








}
