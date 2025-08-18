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

const int N = 2e5+5;

int n, m, k;
bool vis[N];
int baneado[N];
vector<int> adj[N];
// Respuesta
int t = 0;
vector<int> invitados[N];

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = true;
    if (baneado[v]) return; // Los baneados no invitan
    bool invito = false;
    for (int u : adj[v]) {
        if (!vis[u]) {
            invito = true;
            invitados[v].push_back(u);
            dfs(u);
        }
    }
    if (invito) t++;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>k;
    for (int i = 0; i < k; i++) {
        int x; cin>>x;
        baneado[x] = true;
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }   

    // Busco el primero no baneado
    int primero = 0;
    for (int i = 1; i <= n; i++) {
        if (!baneado[i]) {
            primero = i;
            break;
        }
    }

    // Si todos estan baneados nadie puede empezar
    if (primero == 0) {
        cout<<"No\n";
        return 0;
    }

    dfs(primero);

    // Si alguien no esta invitado entones no se puede
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout<<"No\n";
            return 0;
        }
    }

    queue<int> q; q.push(primero);
    cout<<"Yes\n";
    cout<<t<<"\n";
    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (invitados[v].empty()) continue;
        cout<<v<<" "<<invitados[v].size()<<" ";
        for (int u : invitados[v]) {
            q.push(u);
            cout<<u<<" ";
        }
        cout<<"\n";
    }


    return 0;
}
