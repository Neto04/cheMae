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

const ll INF = 1e18;
const int N = 1e5+5;

// Puentes
ll T = 0;
ll vis[N], low[N];
ll subarbol[N];
ll dfs(ll x, vector<vector<ll>>& adj, vector<pair<ll,ll>>& puentes, ll r = 0) {
    subarbol[x] = 1LL;
    vis[x] = low[x] = ++T;
    for (ll y : adj[x]) {
        if (y == r) continue;
        if (!vis[y]) {
            subarbol[x] += dfs(y, adj, puentes, x);
            low[x] = min(low[x], low[y]);
            if (low[y] > vis[x]) {
                puentes.push_back({min(x,y),max(x,y)});
            }
        } else {
            low[x] = min(low[x], vis[y]);
        }
    }  
    return subarbol[x];
}

// UF

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll t; cin>>t;
    while (t--) {
        ll n, m; cin>>n>>m;
        vector<vector<ll>> adj(n+1);
        for (ll i = 0; i < m; i++) {
            ll a, b; cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // Encuentro los puentes
        for (ll i = 1; i <= n; i++) {
            vis[i] = low[i] = subarbol[i] = 0;
        }
        T = 0;
        vector<pair<ll,ll>> puentes;
        dfs(1, adj, puentes);

        // Busco el minimo puente
        ll ans = INF;
        for (auto e : puentes) {
            // u -> v
            ll u = e.first, v = e.second;
            if (vis[u] > vis[v]) swap(u,v);
            ll x = n - subarbol[v], y = subarbol[v];
            ans = min(ans, (x*(x-1LL))/2LL + (y*(y-1LL))/2LL);
        }
        if (ans == INF) ans = (n*(n-1))/2;
        cout<<ans<<"\n";
    }

    return 0;

}
