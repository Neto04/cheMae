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
int color[N];
vector<int> adj[N];

int n, m;

int dfs(int v, int p, int gatos) {

    if (color[v]) gatos++;
    else gatos = 0;

    if (gatos > m) return 0;

    if ((adj[v].size() == 1) and (v != 1)) return 1;

    int count = 0;
    for (int u : adj[v]) {
        if (u != p) count += dfs(u, v, gatos);
    }

    return count;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for (int i = 1; i <= n; i++) cin>>color[i];
    for (int i = 1; i <= n-1; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = dfs(1, 0, 0);
    cout<<ans<<"\n";

    return 0;
}
