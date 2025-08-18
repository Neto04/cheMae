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

int n;
vector<ii> ans;
vector<int> adj[N], hojas[N];
int grado[N];

bool dfs(int v, int p = -1) {
    if (adj[v].empty()) return true;
    for (int u : adj[v]) {
        if (u == p) continue;
        bool esHoja = dfs(u, v);
        if (esHoja) hojas[v].push_back(u);
    }
    for (int i = hojas[v].size()-1; i > 0; i -= 2) {
        ans.push_back({hojas[v][i], hojas[v][i-1]});
        hojas[v].pop_back();
        hojas[v].pop_back();
    }
    if (hojas[v].empty()) return true;
    return false;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        cin>>n;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            hojas[i].clear();
            grado[i] = 0;
        }
        ans.clear();

        for (int i = 1; i <= n-1; i++) {
            int u, v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            grado[u]++;
            grado[v]++;
        }

        // Busco el primero nodo de grado par
        int primero = 0;
        for (int i = 1; i <= n; i++) {
            if (grado[i] % 2 == 0) {
                primero = i;
                break;
            }
        }

        // Si todos los nodos tienen grado impar no se puede
        if (primero == 0) {
            cout<<-1<<"\n";
            continue;
        }

        dfs(primero);

        for (int i = 1; i <= n; i++) {
            cout<<"Las hojas de "<<i<<" son :";
            for (int x : hojas[i]) cout<<x<<" ";
            cout<<endl;
        }
    }


    return 0;
}
