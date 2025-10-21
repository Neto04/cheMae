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

int n, m, s, e;
int t;
vector<int> vis, low, tin, tout;
vector<bool> AP;
vector<vector<int>> adj, adj2;

void dfs(int x, int r = 0) {
    int hijos = 0;
    vis[x] = low[x] = ++t;
    for (int y : adj[x]) {
        if (y == r) continue;
        if (not vis[y]) {
            // Construyo el arbol
            adj2[x].push_back(y);
            adj2[y].push_back(x);
            hijos++;
            dfs(y,x);
            low[x] = min(low[x], low[y]);
            if (vis[x] <= low[y] and r != 0) {
                AP[x] = true;
            }
        } else {
            low[x] = min(low[x], vis[y]);
        }
    }
    if (r == 0 and hijos > 1) {
        AP[x] = true;
    }
}

void dfs2(int v, int p = 0) {
    tin[v] = ++t;
    for (int u : adj2[v]) {
        if (u != p) dfs2(u, v);
    }
    tout[v] = ++t;
}

// u de v
bool is_ancestor(int u, int v) {
    return (tin[u] <= tin[v] and tout[u] >= tout[v]);
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        cin>>n>>m>>s>>e;
        t = 0;
        vis.clear(), low.clear(), AP.clear(); adj.clear();
        vis.resize(n+1), low.resize(n+1), AP.assign(n+1, false);
        adj.assign(n+1, vector<int>()), adj2.assign(n+1, vector<int>());
        for (int i = 0; i < m; i++) {
            int u, v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(s);

        t = 0;
        tin.assign(n+1, 0), tout.assign(n+1, 0);
        dfs2(s);

        vector<int> ans;
        ans.push_back(s), ans.push_back(e);

        for (int i = 1; i <= n; i++) {
            if (AP[i] and is_ancestor(i, e) and low[e] >= vis[i] and i != e and i != s) ans.push_back(i);
        }

        sort(ans.begin(), ans.end());
        cout<<ans.size()<<"\n";
        for (int x : ans) cout<<x<<"\n";    
    }

    return 0;
}
