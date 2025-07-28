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

#define debug 1
#define ifd if (debug)

const int N = 1e5+5;
const ll INF = 1e18;

int n, m, s, t;

// Me dice si una arista es necesaria
bool yes[N];

int vis[N], low[N];
int T = 0;
void dfs(int x, vector<vector<pair<int,ll>>>& adj, int r = -1) {
    vis[x] = low[x] = ++T;
    for (auto e : adj[x]) {
        int y = e.first, i = e.second;
        if (i == r) continue;
        if (!vis[y]) {
            dfs(y, adj, i);
            low[x] = min(low[x], low[y]);
            if (low[y] > vis[x]) {
                yes[i] = true;
            }
        } else {
            low[x] = min(low[x], vis[y]);
        }
    }
}

void dijkstra(int x, vector<ll>& dist, vector<vector<pair<int,ll>>>& adj) {
    bool processed[n+1];
    priority_queue<pair<ll,int>> q;
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        processed[i] = false;
    }
    dist[x] = 0;
    q.push({0,x});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        for (auto u : adj[a]) {
            int b = u.first; ll w = u.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>s>>t;
    vector<vector<pair<int,ll>>> adj(n+1), adjInv(n+1);
    vector<tuple<int,int,ll>> edges;
    vector<ll> distS(n+1), distT(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; ll w; cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adjInv[b].push_back({a,w});
        edges.push_back({a,b,w});
    }

    // Encuentro las distancias de s a todos y de t a todos
    dijkstra(s, distS, adj);
    dijkstra(t, distT, adjInv);

    // Minima distania de s a t
    ll minima = distS[t];

    // Limpio las aristas para ahorrar memoria
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        adjInv[i].clear();
    }

    // Construyo un grafo bidireccional solo con las aristas buenas 
    for (int i = 0; i < edges.size(); i++) {
        int a, b; ll w;
        tie(a, b, w) = edges[i];
        if (distS[a] + w + distT[b] == minima) {
            // En vez del peso mando el indice del edge para dar la respuesta luego
            adj[a].push_back({b,i});
            adj[b].push_back({a,i});
        }
    }

    // Busco los puentes
    dfs(s, adj);

    for (int i = 0; i < edges.size(); i++) {
        if (yes[i]) {
            cout<<"YES\n";
            continue;
        }
        int a, b; ll w;
        tie(a, b, w) = edges[i];
        ll x = distS[a] + w + distT[b] - minima + 1LL;
        if (w - x > 0) cout<<"CAN "<<x<<"\n";
        else cout<<"NO\n";
    }

    return 0;
}
