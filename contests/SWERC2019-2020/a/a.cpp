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
ii pInicio; int nodoInicio=1001;
ii pFinal; int nodoFinal=1002;
int MAXDIST;
int c0;
// #means of transport
int t;
// #estaciones
int n;



vector<ll> cT;

vector<ii> pos(1005);
vector<ll> xDe(1005);
vector<ll> yDe(1005);


ll raizQ(ll a) {
    long long x = sqrt(a) + 2;
    while (x * x > a) x--;
    if (x*x<a) return x+1;
    return x;
}

ll calcDist(ll x1, ll y1,ll x2, ll y2) {
    ll v1 = (x1-x2);
    v1*=v1;
    
    ll v2 = (y1-y2);
    v2*=v2;

    return raizQ(v1+v2);

}
struct edge {
    ll fin=0;
    ll dist=0;
    ll costo=0;
    ll mT=0;
    edge() {
        
    }


    edge (ll fin, ll mT) {
        this->fin=fin;
        this->mT=mT;
    }
    void update(ll x1, ll y1) {
        ll x2=xDe[fin], y2 = yDe[fin];

        this->dist=calcDist(x1, y1, x2, y2);
        ifd cout<<"vea que la distancia de ("<<x1<<", "<<y1<<") a ("<<x2<<", "<<y2<<") = "<<this->dist<<endl;
        this->costo=cT[mT]*dist;
    }
};
vector<vector<edge>> edges(1005);

bitset<100> seen[1005];
vector<vector<ll>> dp(1005,vector<ll> (100));
bitset<1005> color;

ll solve (ll nodo, ll cDist) {
    ifd cout<<"estoy llentando solve nodo "<<nodo<<", con cDist "<<cDist<<endl;
    ifd cout<<"intentando llegar a "<<nodoFinal<<endl;
    if (seen[nodo][cDist]) return dp[nodo][cDist];
    seen[nodo][cDist]=true;
    if (nodo==nodoFinal) return dp[nodo][cDist]=0;
    ll& minCosto=dp[nodo][cDist];
    minCosto=1e18;

    for (edge u:edges[nodo]) {
        ifd cout<<"vea que "<<u.fin<<" es adyacente a "<<nodo<<" con distancia "<<u.dist<<" y costo "<<u.costo<<" usando el medio de transporte "<<u.mT<<endl;
        if (u.dist+cDist>MAXDIST||color[u.fin]) continue;
        color[u.fin]=1;
        minCosto=min(minCosto, u.costo+solve(u.fin, u.dist+cDist));
        color[u.fin]=0;
    }

    return minCosto;
}



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // eventualmente marca quién es el nodo inicial y el nodo final
    // aribtrariamente diga que inicio es el nodo 1001 y final es el nodo 1002
    cin>>pInicio.first>>pInicio.second;
    
    cin>>pFinal.first>>pFinal.second;
    
    ifd {
        cout<<"inicio = ("<<pInicio.first<<", "<<pInicio.second<<") "<<endl;
        cout<<"final = ("<<pFinal.first<<", "<<pFinal.second<<") "<<endl;

    }
    // la dist max
    cin>>MAXDIST;
    cin>>c0;
    cin>>t;
    cT.resize(t+1);
    cT[0]=c0;
    // usted tiene t+1 formas de transporte (t+ la 0)
    for(ll i=1; i<=t; i++) cin>>cT[i];

    ifd {
        cout<<"los medios de transporte i cuestan ci:"<<endl;
        forn(i, t+1) cout<<cT[i]<<" ";
        cout<<endl;
    }

    cin>>n;
    ifd cout<<"hay "<<n<<" estaciones"<<endl;
    nodoInicio=n;
    xDe[nodoInicio]=pInicio.first;
    yDe[nodoInicio]=pInicio.second;
    nodoFinal=n+1;
    xDe[nodoFinal]=pFinal.first;
    yDe[nodoFinal]=pFinal.second;

    forn(i,n) {
        ll xi, yi; cin>>xi>>yi;
        ifd cout<<"la estación "<<i<<" está en ("<<xi<<", "<<yi<<") "<<endl;

        ii cP={xi, yi};
        xDe[i]=xi; yDe[i]=yi;
        // esto para guardar cuál nodo es el start y end (por aquello de que start o end pueda ser una estación)
        if (cP==pInicio) nodoInicio=i;
        if (cP==pFinal) nodoFinal=i;
        // creo que ese pos ni importa, pero bueno
        pos[i]=cP;

        ll l; cin>>l;
        while (l--) {

            ll cJ, cMT;
            cin>>cJ>>cMT;
            ifd cout<<"vea que hay una arista de "<<i<<" a "<<cJ<<" con el medio de transporte "<<cMT<<endl;
            // guarde las dos direcciones de la arista
            edges[i].push_back(edge(cJ, cMT));
            edges[cJ].push_back(edge(i, cMT));
        }
        
        // meta el edge de usted al final con el mT =0;
        edges[i].push_back(edge(nodoFinal,0));
        
    }

    forn(i, n+2) {
        // ahora guarde que se puede mover de inicio a cualquier mae con el transporte 0
        if (i!=n) edges[nodoInicio].push_back(edge(i, 0));
        ifd cout<<"vea que hay una arista de "<<n<<" a "<<i<<" con el medio de transporte "<<0<<endl;
    }  

    for(int i=0; i<(max(n+1, nodoFinal+1)); i++) {
        for(int j=0; j<edges[i].size(); j++) {
            edges[i][j].update(xDe[i], yDe[i]);
        }
    }

    color[nodoInicio]=true;

    ll ans = solve(nodoInicio, 0);
    if (ans==1e18) ans = -1;
    cout<<ans<<endl;
}
