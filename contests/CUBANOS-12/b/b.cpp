// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
#define debug 0
#define ifd if (debug)
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
const int MAXN=100100;
const ll INF=1e18;

struct Mono {
    
	ll val;
    // return elemento neutro
	static Mono zero() { return {INF};}
}; // neutro de la suma

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
		i += len; data[i].val += x.val;
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
int n;
Segtree st;

// me retorna el indx del mae l mas grande tq query([l,...n)) <=x
ll search(int x) {
	// si no hay nadie, pare
	if (st.query(0, n).val>x) {
		ifd cout<<"vea que de 0 a n el min es "<<st.query(0, n).val<<endl;;
		return -1;
	}
	// a es el min l tq query([l, ..., n)) <=x 
	// b el max tq query([b, ..., n)) >x
	int a =-1, b = n;
	while (b-a>1) {
		int c = (b+a)/2;
		ifd cout<<"checking "<<c<<endl;
		ll ans = st.query(0, c+1).val;
		ifd cout<<"de ["<<c<<" a "<<n<<") el min es "<<ans<<endl;
		if (ans>x) a=c;
		else b=c;
	}
	return b;
}




int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
	freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);


	ll h, w;
	cin>>h>>w>>n;
	// al inicio todos tienen campo
	// cada mae va a guardar cuál es el primer campo libre en el que se puede poner a alguien
	vector<Mono> a(n);
	forn(i, n) a[i]={0};
	st.init(a, n);
	
	forn(i, n) {
		ll k; cin>>k;
		ifd cout<<"leo un log de length "<<k<<", busco a alguien cuyo primer campo libre sea (al menos) "<<w-k<<endl;
		ll indx = search(w-k);
		ifd cout<<"el primer mae de izq a der con "<<w-k<<" libre es "<<indx<<endl;
		if (indx>=h or indx ==-1) cout<<"-1\n";
		else {
			cout<<indx+1<<"\n";
			st.update(indx, {k});
		}
	}

}
