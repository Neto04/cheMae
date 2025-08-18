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

const int N = 2e5+5;
// Frecuencia de cada nivel
vector<int> freq;
// Nivel de cada nodo
vector<int> nivel;
// Grafo
vector<int> adj[N];
// Hijos y papa de cada nodo
vector<int> hijos[N];
int papa[N];

// Nodos guardados por nivel en el orden del recorrido
vector<int> niveles[N];
// Como se tienen que ver los niveles segun los papas
vector<int> papas_niveles[N];

void dfs(int v, int profundidad, int p) {
    nivel[v] = profundidad;
    freq[profundidad]++;
    papa[v] = p;
    for (int u : adj[v]) {
        if (u == p) continue;
        hijos[v].push_back(u);
        dfs(u, profundidad+1, v);
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    // Frecuencias por profundidad
    freq.assign(n+5, 0), nivel.assign(n+5,0);

    for (int i = 0; i < n-1; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 1);

    vector<int> v(n);
    for (int& x : v) cin>>x;

    // Revisar y construir niveles
    int i = 0, next = 0;
    while (i < freq.size() and freq[i] != 0) {
        for (int k = 1; k <= freq[i]; k++) {
            int nodo = v[next++];
            if (nivel[nodo] != i) {
                cout<<"No\n";
                return 0;
            }
            niveles[i].push_back(nodo);
        }
        i++;
    }
    
    ifd cout<<"Por ahora todo bien"<<endl;

    // Conveniencia
    papas_niveles[0].push_back(1);
    for (int i = 0; i < N; i++) {
        ifd {
            cout<<"Nivel "<<i<<endl;
            cout<<"Niveles normales"<<endl;
            for (auto x : niveles[i]) cout<<x<<" ";
            cout<<endl;
            cout<<"Niveles papas"<<endl;
            for (auto x : papas_niveles[i]) cout<<x<<" ";
            cout<<endl;
        }
        
        // Si ya se acabaron los niveles termino
        if (niveles[i].empty()) break;
        // Si no reviso que sea igual a lo que quiero
        if (papas_niveles[i].size() != niveles[i].size()) {
            cout<<"No\n";
            return 0;
        }

        ifd cout<<"Los niveles "<<i<<" coinciden en tamano"<<endl;

        for (int j = 0; j < niveles[i].size(); j++) {
            int nodo = niveles[i][j];
            ifd cout<<"El papa de "<<nodo<<" es "<<papa[nodo]
            <<" y yo quiero que sea "<<papas_niveles[i][j]<<endl;
            if (papa[nodo] != papas_niveles[i][j]) {
                cout<<"No\n";
                return 0;
            }
            if (i != N-1) {
                for (int k = 0; k < hijos[nodo].size(); k++) {
                    papas_niveles[i+1].push_back(nodo);
                }
            }
        }
    }

    cout<<"Yes\n";

    return 0;
}
