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

int n, m;
ll L, U;

vector<pair<int,ll>> adj[N];
vector<tuple<int,int,ll>> edges;
ll dist[N];
bool processed[N];

void dijkstra() {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        processed[i] = false;
    }
    priority_queue<pair<ll,int>> q;
    q.push({0,0});
    dist[0] = 0;
    
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first; ll w = u.second;
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }

    for (int i = 0; i < n; i++) dist[i] *= 2;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>L>>U;
    for (int i = 0; i < n; i++) {
        int a, b; ll w; cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        edges.push_back({a,b,w});
    }

    dijkstra();

    ll ans = 0;
    for (auto& e : edges) {
        int a, b; ll w;
        tie(a,b,w) = e;
    
        if (dist[a]+w >= L and dist[a] < U) {
            ans++;
            continue;
        }
        if (dist[b]+w >= L and dist[b] < U) {
            ans++;
            continue;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
