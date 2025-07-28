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

#define debug 1
#define ifd if (debug)

///
ll n, m, a, b;
vector<vector<int>> adj;

int arista_a_nodo[MAX], nodo_a_arista[MAX];

// ---------------------------------------------------------------------------

// edges are added twice so MAX *= 2
// const ll MAX = 205;
// src + dest + 5000 nodos + 5000 aristas
const ll MAX = 10000+1;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

struct Edge {
    ll to, rev;
    ll f, cap;
    Edge(ll to, ll rev, ll f, ll cap): to(to), rev(rev), f(f), cap(cap) {}
};

ll dist[MAX], q[MAX], work[MAX];
vector<Edge> ady[MAX];

ll src, dst;
void reset() {
    for(ll i = 0; i < MAX; i++) {
        ady[i].clear();
    }
}

void AddEdge(ll s, ll t, ll cap, ll rcap = 0) {
    ady[s].push_back(Edge(t, ady[t].size(), 0, cap));
    ady[t].push_back(Edge(s, ady[s].size() - 1, 0, rcap));
}

bool dinic_bfs() {
    memset(dist, -1, sizeof dist);
    dist[src] = 0;
    ll qt = 0;
    q[ qt++ ] = src;
    for(ll qh = 0; qh < qt; qh++) {
        ll u = q[qh];
        for(auto e : ady[u]) {
            ll v = e.to;
            if(dist[v] < 0 && e.f < e.cap) {
                dist[v] = dist[u] + 1;
                q[qt++] = v;
            }
        }
    }
    return dist[dst] >= 0;
}

ll dinic_dfs(ll u, ll f) {
    if(u == dst) return f;
    for(ll& i = work[u]; i < ady[u].size(); i++) {
        Edge &e = ady[u][i];
        if(e.cap <= e.f)continue;
        ll v = e.to;
        if(dist[v] == dist[u] + 1) {
            ll df = dinic_dfs(v, min(f, e.cap - e.f));
            if(df > 0) {
                e.f += df;
                ady[v][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

ll maxFlow(ll _src, ll _dst) {
    src = _src;
    dst = _dst;
    ll result = 0;
    while(dinic_bfs()) {
        memset(work, 0, sizeof work);
        while(ll delta = dinic_dfs(src, INF)) {
            result += delta;
        }
    }
    return result;
}

// ---------------------------------------------------------------------------

vector<ii> aristas;

bool check(ll k, bool guardar) {
    // Reiniciar el grafo de flujo
    reset();
    // Arista del sink a cada nodo
    for (int v = 1; v <= n; v++) {
        AddEdge(0, v, k);
    }
    // Arista de cada nodo a sus aristas
}

// busca min max cantidad de regalos que puede dar c/u
ll search() {
    // l es el max mae que de fijo no sirve, r el min que de fijo sí 
    ll l=0, r=n;
    while (r-l>1) {
        ll c=(r-l)/2+l;
        if (check(c,false)) r=c;
        else l=c;
    }
    return r;
}

int main() {
    //    freopen("asd.in", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    adj.assign(n+1, vector<int>(n+1));

    while(m--) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll ans = search();
    for (ii& x : aristas) cout<<x.first<<" "<<x.second<<"\n";

    return 0;
}