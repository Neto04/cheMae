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

const int N = 1e6+5;
vector<int> adj[N];
int ans[N], valor[N];
bool visited[N];

void dfs(int v, vector<int>& indices, vector<int>& valores) {
    if (visited[v]) return;

    visited[v] = true;
    indices.push_back(v);
    valores.push_back(valor[v]);

    for (int u : adj[v]) {
        if (!visited[u]) dfs(u, indices, valores);
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    for (int i = 1; i <= n; i++) cin>>valor[i];

    for (int i = 1; i <= m; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        vector<int> indices, valores;
        dfs(i, indices, valores);

        sort(indices.begin(), indices.end());
        sort(valores.begin(), valores.end(), greater<int>());
        for (int j = 0; j < indices.size(); j++) {
            ans[indices[j]] = valores[j];
        }
    }

    for (int i = 1; i <= n; i++) cout<<ans[i]<<" ";
    cout<<"\n";

    return 0;
}
