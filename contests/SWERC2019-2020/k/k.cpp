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

int colores[N];
bool candidatos[N];
vector<int> adj[N], adjInverso[N];

void dfs(int u, int colorActual) {
    if (colores[u]) {
        if (colores[u] != colorActual) colores[u] = INF;
        return;
    }
    colores[u] = colorActual;
    for (int v : adjInverso[u]) {
        dfs(v, colorActual);
    }
}

void bfs() {
    queue<int> q;
    bool visited[n];
    for (int i = 0; i < n; i++) {
        if (colores[i] == INF) {
            q.push(i);
            visited[i] = true;
        } else {
            visited[i] = false;
        }
    }
    visited[t] = true;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            colores[u] = INF;
            visited[u] = true;
            q.push(u);
        }
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>t;

    // Preparar arreglos
    for (int i = 0; i < n; i++) {
        colores[i] = 0; 
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

    // Marcar t como coloreado por todos)
    colores[t] = INF;
    for (int i = 0; i < n; i++) {
        if (candidatos[i]) dfs(i, i+1);
    }
    colores[t] = 0;

    // BFS desde todos los infinitos
    bfs();

    for (int i = 0; i < n; i++) {
        if (!candidatos[i]) continue;
        if (colores[i] == INF) {
            candidatos[i] = false;
            count--;
            break;
        }
    }

    cout<<count<<"\n";
    for (int i = 0; i < n; i++) {
        if (candidatos[i]) cout<<i<<"\n";
    }

    return 0;
}
