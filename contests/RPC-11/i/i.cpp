// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 0
#define ifd if (debug)

int n, m, s, p, q;

// Num de paginas
int P;
// Primera y ultima pagina que me interesa ver
int l = -1, r = -1;

// Cuantos p y q hay en cada pagina
vector<ll> paginasP, paginasQ;
// Si cada numero esta o no como p o como q en cada pagina (para las intersecciones)
vector<vector<bool>> freqP, freqQ;

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // Leer
    cin>>n>>m>>s>>p>>q;

    P = n/m + ((n % m) != 0);

    paginasP.assign(P+1, 0), paginasQ.assign(P+1, 0);
    freqP.assign(P+1, vector<bool>(1e3+1, false)), freqQ.assign(P+1, vector<bool>(1e3+1, false));
    
    forn(i,p) {
        int x; cin>>x;
        // Numero de pagina
        int pag = x/m + ((x % m) != 0);
        // Aumento los p de esa pagina
        paginasP[pag]++;
        // Marco que ese item esta como p en pag
        freqP[pag][x] = true;
    }

    forn(i,q) {
        int x; cin>>x;
        // Numero de pagina
        int pag = x/m + ((x % m) != 0);
        // Aumento los q de esa pagina
        paginasQ[pag]++;
        // Marco que ese item esta como q en pag
        freqQ[pag][x] = true;
    }

    ll ans = 0;
    for (int i = 1; i <= P; i++) {
        // Tamano de la interseccion de p y q en esa pag
        ll inter = 0;
        for (int item = 1; item <= 1e3; item++) {
            if (freqP[i][item] and freqQ[i][item]) inter++;
        }
        ifd {
            cout<<"En la pagina "<<i<<": "<<endl;
            cout<<"La interseccion es de tamano "<<inter<<endl;
            cout<<"paginasP = "<<paginasP[i]<<", paginasQ = "<<paginasQ[i]<<endl; 
        }
        // Clicks nuevos
        int m2 = m;
        if (i == P) m2 = n-(P-1)*m;
        ll clicks = min(min(1+paginasQ[i], 1+m2-paginasQ[i]), paginasP[i]+paginasQ[i]-2*inter); 
        // Si hay clicks y no hay primera pagina, esta es la primera pagina
        if (l == -1 and clicks > 0) l = i;
        // Si hay clicks, esta es la ultima
        if (clicks > 0) r = i;

        ifd cout<<"Hay "<<clicks<<" clicks"<<endl;
        ans += clicks;
    }

    ifd cout<<"l = "<<l<<", r = "<<r<<endl;
    // Sumar movimientos de pagina
    ll clicks = 0;
    if (l != -1) {
        if (s <= l) clicks = r-s;
        else if (s >= r) clicks = s-l;
        else clicks = (min(s-l, r-s) + r - l);
    }
    ifd cout<<clicks<<" clicks al final"<<endl;
    ans += clicks;

    cout<<ans<<"\n";

    return 0;
}
