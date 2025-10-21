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
vector<int> adj[N];
ll val[N];
int deg[N];

int n;
vector<int> orden;

bool dfs(int v, int p = 0) {
    // Cuando llego me pusheo
    orden.push_back(v);
    // y le resto a mi valor
    val[v]--;

    bool posible = true;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (val[v] < 0) return false;

        posible = dfs(u, v);
        // Si mi hijo ya no puede matar a su subarbol, f para todos
        if (not posible) return false;

        // Cuando regreso de mi hijo me pusheo de nuevo
        orden.push_back(v);
        val[v]--;
        if (val[v] < 0) return false;

        // Val de mi hijo tiene lo que le queda, entonces vuelvo a bajar y subir esas veces
        forn(i, val[u]) {
            if (val[v] < 0) return false;
            orden.push_back(u);
            orden.push_back(v);
            val[v]--;
        }
        val[u] = 0;
    }

    return true;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>val[i];
    }
    // Exhibit dummy para poder agarrar uno desde el inicio
    val[1]++;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    bool posible = dfs(1);
    if (not posible) cout<<0<<"\n";
    else {
        for (int i = 1; i <= n and posible; i++) {
            if (val[i] != 0) posible = false;
        }
        if (not posible) cout<<0<<"\n";
        else {
            for (int x : orden) cout<<x<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
