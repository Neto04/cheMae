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

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC; 
    while (tC--) {
        int n, m; cin>>n>>m;

        // Leo aristas y guardo el orden
        vector<int> adj[n+1];
        vector<int> grado(n+1, 0);
        map<pair<int,int>, int> idxArista;
        int siguiente = 0;
        for (int i = 0; i < m; i++) {
            int u, v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            // Aumenta grado de nodos
            grado[u]++;
            grado[v]++;
            // Guarda indice de arista
            if (u > v) swap(u, v);
            idxArista[{u,v}] = siguiente++;
        }

        vector<int> ans(m, 0);
        // Si el grafo no es completo
        if (m < n*(n-1)/2) {
            // Busco el nodo de menor grado
            int mini = 1e9, nodo = 0;
            for (int i = 1; i <= n; i++) {
                if (grado[i] < mini) {
                    mini = grado[i];
                    nodo = i;
                }
            }
            // Pinto todas las aristas de ese nodo
            for (int u : adj[nodo]) {
                ans[idxArista[{min(nodo,u), max(nodo,u)}]] = 1; 
            }
            // Respuesta
            cout<<2<<"\n";
            for (int i = 0; i < m; i++) {
                if (ans[i] == 0) cout<<2<<" ";
                else cout<<ans[i]<<" ";
            }
            cout<<"\n";
        } else { // Si es completo
            int a = 1, b = 2;
            // Pinto todas las aristas de a excepto la que va a b
            for (int u : adj[a]) {
                if (u == b) continue;
                ans[idxArista[{min(a,u), max(a,u)}]] = a; 
            }
            // Pinto todas las aristas de b excepto la que va a a
            for (int u : adj[b]) {
                if (u == a) continue;
                ans[idxArista[{min(b,u), max(b,u)}]] = b; 
            }
            // Pinto a-b de color 3 
            ans[idxArista[{a,b}]] = 3;
            // Respuesta
            cout<<3<<"\n";
            for (int i = 0; i < m; i++) {
                if (ans[i] == 0) cout<<1<<" ";
                else cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }

    }

    return 0;
}
