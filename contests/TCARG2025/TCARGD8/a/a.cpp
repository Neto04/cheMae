#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)

typedef long long ll;
typedef pair<int, int> ii;
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
const int MAXN=100100;
const ll INF=1e9+7;

#define debug 0
#define ifd if (debug)
#define TYPE int
#define ELEMENTO_NEUTRO -1
#define oper(a, b) a+b
ll mulmod(ll b, ll a, ll m) {return __int128(a) * b % m;}

int n;

bool valid(int i) {
    return ((i>-1)&&(i<n));
}


ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}


// EL SEGTREE DE GCD
struct Mono1 {
	ll val;
    // return elemento neutro
	static Mono1 zero() { return {0}; } // neutro del gcd
};


// saque gcd de a, b
Mono1 operator+ (Mono1 a, Mono1 b) {
	return {gcd(a.val, b.val)};
} // asociativo


struct Segtree1 {
	int len; vector<Mono1> data;
    
	void init(vector<Mono1>&a) { assert(n>0); // O(n+len)
		// len =  min k tq 2^k>=n
		len=1<<(31-__builtin_clz(2*n-1));
		// y usted mete len*2
		data.assign(len*2, Mono1::zero());
        // revise que la vara exista, y en las hojas usted mete a[i]
		if (!a.empty()) forn(i, n) data[i+len] = a[i];
        // ahora, de las hojas patrás retorne la combinación de las dos
		dforr(i, 1, len) data[i] = data[i*2] + data[i*2+1];
	}

    // actualice el mae en i a x
	void update(int i, Mono1 x) {
        // primero la hoja
		i += len; data[i] = x;
        // luego vaya de abajo a arriba
        while (i /= 2) data[i] = data[i*2] + data[i*2+1];
	}

	int ql, qr;
    // sabiendo que está en el nodo i, revise qué hay en [l, r)
	Mono1 q_(int i, int l, int r) {
        // si i está completamente disjunto, retorne el nulo
		if (r <= ql || qr <= l) return Mono1::zero();
        // si está completamente contenido, retorne ese nodo
		if (ql <= l && r <= qr) return data[i];
		int m = (l+r)/2;
        // retorne la intersección de los dos maes
		return q_(i*2,l,m) + q_(i*2+1,m,r);
	}
    // preguntan por l, r, sepa que va a empezar desde el nodo 1 preguntando por (0, len)
	Mono1 query(int l, int r) { ql = l; qr = r; return q_(1, 0, len); }
};





int main() {
    const int N = 2*1e5;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<ll> numDiv(N+1);
    for(int i=1; i<=N; i++) {
        for(int j=i; j<=N; j+=i) numDiv[j]++;
    }

    int tC; cin>>tC;
    while (tC--) {
        int q; 
        cin>>n>>q;
        vector<ll> v(n);
        forn(i,n) cin>>v[i];
        ll last = -1;
        vector<Mono1> lengths(n);
        int lastEnd=-1;


        set<ll> finales;
        
        ll end;
        forn(i,n) {
            // si esta en creciente
            if (v[i]>=last) end =i;
            // si ese punto es decr con respecto al anterior
            else {
                // guardelo como uno de los finales
                finales.insert(end);
                lengths[end].val=end-lastEnd;
                lastEnd=end;
                end=i;
            }
            last=v[i];
        }
        lengths[n-1].val=n-1-lastEnd;
        finales.insert(n-1);
        
        ifd {
            cout<<"AL INICIO:"<<endl;
            ifd cout<<"v se ve:"<<endl;
            for(auto u:v) cout<<u<<" ";
            cout<<endl;

            ifd cout<<"lengths:"<<endl;
            forn(i, n) cout<<lengths[i].val<<" ";
            cout<<endl;

            ifd cout<<"finales:"<<endl;
            for(auto u:finales) cout<<u<<" ";
            cout<<endl;
        }
        
        // tiene en i la length de ese mae
        Segtree1 stGcd; stGcd.init(lengths); 
        ll resp=stGcd.query(0, n-1).val; resp=numDiv[resp];
        queue<ll> ans;     
        if (finales.size()==1) ans.push(n);
        else ans.push(numDiv[resp]);

        ifd cout<<"el primer gcd es "<<resp<<endl;
        
        
        while (q--) {
            int pos; ll nVal; cin>>pos>>nVal;
            pos--;
            v[pos]=nVal;
            // encuentre el paréntesis al que pertenece 
            auto u=finales.lower_bound(pos);
            
            // SI TIENE ALGUIEN A LA IZQ EN QUIEN FIJARSE
            if (pos>0) {
                auto uu=finales.lower_bound(pos-1);
                // si estaban en distintos
                if (*uu!=*u) {
                    // revise si ahora puede pegarlos
                    if (nVal>=v[pos-1]) {
                        // length del que termina en su final ahora es lenAnterior+lenSuya
                        lengths[*u].val=lengths[*uu].val+lengths[*u].val;
                        // lenAnterior ahora es 0
                        lengths[*uu].val=0;
                        stGcd.update(*uu, lengths[*uu]);
                        stGcd.update(*u,{lengths[*u]});
                        finales.erase(uu);
                    }
                }
                // si estaban en iguales, revise si ahora se separan
                else {
                    // si ahora se separan
                    if (v[pos-1]>nVal) {
                        // busque el paréntesis anterior (para sacar el len desde ese mae hasta)
                        int anterior=-1;
                        // si existe un paréntesis anterior
                        if (u!=finales.begin())  {
                            uu = u;
                            uu--;
                            anterior = *uu;
                        }
                        // el length de todo justo antes de pos
                        int pastLen=pos-1-anterior;
                        // meta pos-1 como un nuevo final
                        finales.insert(pos-1);
                        // meta length de pos-1 como lo que corresponde
                        lengths[pos-1].val=pastLen;
                        stGcd.update(pos-1, lengths[pos-1]);
                        // ahora su nueva length es la misma - length del anterior que acaba de crear
                        lengths[*u].val=lengths[*u].val-lengths[pos-1].val;
                        stGcd.update(*u, lengths[*u]);
                    }
                }
            }
            // SI TIENE ALGUIEN A LA DERECHA EN QUIEN FIJARSE
            if (pos<n-1) {
                auto uu = finales.lower_bound(pos+1);
                // si estaban en distintos 
                // (entonces de fijo usted era un final):
                if (*uu!=*u) {
                    // si ahora puede unirlos
                    if (nVal<=v[pos+1]){
                        // aumente la length del otro mae
                        lengths[*uu].val=lengths[*uu].val+lengths[pos].val;
                        lengths[pos].val=0;
                        stGcd.update(*uu, lengths[*uu]);
                        stGcd.update(pos,lengths[pos]);
                        // ponga la length del mae que terminaba en usted en 0
                        finales.erase(pos);
                    }
                }

                // si usted y el sig están en el mismo:
                else {
                    // revise si ahora se separan:
                    if (nVal>v[pos+1]) {
                        // busque el paréntesis anterior (para sacar el len desde ese mae hasta este punto)
                        int anterior=-1;
                        // si existe un paréntesis anterior
                        if (u!=finales.begin())  {
                            auto uuu = u;
                            uuu--;
                            anterior = *uuu;
                        }
                        // el length de todo <= pos
                        int pastLen=pos-anterior;
                        lengths[pos].val=pastLen;
                        lengths[*u].val=lengths[*u].val-lengths[pos].val;

                        stGcd.update(pos, lengths[pos]);
                        stGcd.update(*u, lengths[*u]);
                        finales.insert(pos);
                    }
                }
            }
            if (finales.size()==1) ans.push(n);
            else ans.push(numDiv[stGcd.query(0, n-1).val]);
        }

        while (!ans.empty()) {
            cout<<ans.front()<<"\n";
            ans.pop();
        }




    }



}
