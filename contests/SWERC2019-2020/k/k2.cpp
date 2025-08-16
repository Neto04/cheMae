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
const int INF = 1e6;

int n, m, t;

vector<int> colores[N];
bool candidatos[N];
vector<int> adj[N], adjInverso[N];


// Si v esta pintado de x (v puede llegar a T'_x)
bool pertenece(int x, int v) {
    if (colores[v].size()) {
        if (x == colores[v][0]) return true;
        if (colores[v].size() > 1 and x == colores[v][1]) return true; 
    }
    return false;
}

// Dfs para colorear cada nodo maximo dos veces
void dfs(int u, int colorActual) {
    colores[u].push_back(colorActual);
    for (int v : adjInverso[u]) {
        if (v != t and !pertenece(colorActual, v) and colores[v].size() < 2)
            dfs(v, colorActual);
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>t;

    // Preparar arreglos
    for (int i = 0; i < n; i++) { 
        candidatos[i] = false;
    }

    // Leer
    int count = 0;
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;

        if (b == t) {
            candidatos[a] = true;
            count++;
        }

        adj[a].push_back(b);
        adjInverso[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (candidatos[i]) dfs(i, i+1);
    }

    for (int i = 0; i < n; i++) {
        if (!candidatos[i]) continue;
        if (colores[i].size() > 1) {
            candidatos[i] = false;
            count--;
        } 
    }

    cout<<count<<"\n";
    for (int i = 0; i < n; i++) {
        if (candidatos[i]) cout<<i<<"\n";
    }

    return 0;
}
