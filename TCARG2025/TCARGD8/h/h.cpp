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

const int N = 3e5+5;
vector<int> adj[N];
vector<int> hojas, papas;
int grado[N];
bool vis[N];
int n;

int bfs(int x) {
    queue<int> q; q.push(x);
    int ult = x;
    q.push(x);
    vis[x] = true;
    while(!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : adj[s]) {
            if (vis[u] or grado[u] > 1) continue;
            vis[u] = true;
            ult = u;
            q.push(u);
        }
    }
    return ult;
}

void hacerPapas(int v, int p = -1) {
    papas.push_back(v);
    for (int u : adj[v]) {
        if (u == p) continue;
        hacerPapas(u, v);
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        cin>>n;      

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            grado[i] = 0;
            vis[i] = false;
            hojas.clear();
            papas.clear();
        }
        
        for (int i = 1; i <= n-1; i++) {
            int a, b; cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            grado[a]++;
            grado[b]++;
        }

        // Si solo hay dos nodos no se puede
        if (n == 2) {
            cout<<-1<<"\n";
            continue;
        }

        // Primero encuentro el "diametro" sin hojas
        int a = 0;
        for (int i = 1; i <= n; i++) {
            if (grado[i] > 1) {
                a = i;
                break;
            }
        }
        int b = bfs(a);
        int c = bfs(b);
        
        // Despues encuentro la columna de papas
        hacerPapas(b);
        ifd {
            cout<<"Los papas son :";
            for (auto x : papas) cout<<x<<" ";
        }
        // Podo las hojas

        // Trabajo sobre el arbol podado
        // Meto la primera y ultima hoja a los papas


    }
    return 0;
}
