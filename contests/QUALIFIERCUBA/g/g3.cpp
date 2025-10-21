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

int n, m, s, e;
int t;
vector<int> vis, low, tin, tout;
vector<bool> AP;
vector<vector<int>> adj, adj2;

vector<int> path;
vector<bool> seen;
// me genera un camino válido de inicio a fin
// OJO QUE LO DEVUELVE AL REVÉS
bool dfsPath(int x, int r=-1) {
    ifd cout<<"estoy en "<<x<<endl;
    if (x==e) {
        ifd cout<<"ESA VARA ES EL FINAL!!"<<endl;
        path.push_back(x);
        return true;
    }
    seen[x]=true;
    for(int u:adj[x]) {
        if (u==r or seen[u]) continue;
        if (dfsPath(u, x)) {
            path.push_back(x);
            return true;
        }
    }
    return false;
}

// me genera lo de low, high
void dfsLo(int x, int r = 0) {
    int hijos = 0;
    vis[x] = low[x] = ++t;
    for (int y : adj[x]) {
        if (y == r) continue;
        if (not vis[y]) {
            dfsLo(y,x);
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



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;int tN =1;
    while (tC--) {
        ifd cout<<"CASO "<<tN++<<endl;
        cin>>n>>m>>s>>e;
        ifd cout<<"s = "<<s<<", e = "<<e<<endl;
        t = 0;
        
        vis.clear(), low.clear(), AP.clear(), seen.clear(), path.clear(); adj.clear();
        vis.resize(n+1), seen.resize(n+1), low.resize(n+1), AP.assign(n+1, false);
        adj.assign(n+1, vector<int>()), adj2.assign(n+1, vector<int>());
        for (int i = 0; i < m; i++) {
            int u, v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // genere un path
        dfsPath(s, 0);

        reverse(path.begin(), path.end());
        ifd {
            cout<<"path de "<<s<<" a "<<e<<endl;
            for(int&u: path) cout<<u<<" ";
            cout<<endl;
        }
        // genere los lo, y vis
        dfsLo(s, 0);
        vector<int> ans;
        forn(i, path.size()){
            if (path[i]==s or path[i]==e) {
                ans.push_back(path[i]); 
                continue;
            }
            
            // el mae es punto de articulacion en un camino de s a e, 
            // ergo en todos los caminos de s a e
            if (vis[path[i]]<=low[path[i+1]]) {
                ans.push_back(path[i]);
            }

        }

        sort(ans.begin(), ans.end());
        cout<<ans.size()<<"\n";
        for (int x : ans) cout<<x<<"\n";    
    }

    return 0;
}
