#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 0
#define ifd if (debug)

// https://codeforces.com/gym/104875

vector<vector<int>> adj;
// nivel[v] es la profundidad maxima empezando en v
vector<int> nivel;
vector<bool> malo;

// Calculo niveles
void dfs1(int v, int p = 0) {
    // vea que una hoja tiene nivel cero
    nivel[v] = 1;
    // n1 el depth de uno de sus hijos, n2 el de otro
    int n1=-1, n2=-1;
    for (int& u : adj[v]) {
        if (u == p) continue;
        dfs1(u,v);
        if (n1==-1) n1=nivel[u];
        else n2=nivel[u];
        nivel[v] = max(nivel[v], nivel[u]+1);
        
    }
    // marque todos los nodos en los que sus hijos le generan un problema
    n1=max(n1,0), n2=max(n2,0);
    ifd cout<<"para v = "<<v<<", nivel de v = "<<nivel[v]<<" n1 = "<<n1<<", n2 = "<<n2<<endl;
    if (n1<n2) swap(n1, n2);
    if (n1>n2+1) {
        malo[v]=true;
        ifd cout<<v<<" es malo!"<<endl;
        // vea que si sus hijos le generaban un problema, usted "arregla ese problema" 
        // y su nivel va a quedar como el nivel cuando la vara esté arreglada
        // osea el nivel del mas grande (que arreglado sería n2+1) + 1
        nivel[v]=n2+2;
    }
}

// usted está en el nodo v, con parent p, seenMalo dice si ya vió o no a alguien malo, 
// y targetNiv es el nivel con el que tiene que quedar ese mae (importa sii seenMalo==true)
void dfs2(int v, int p = 0, bool seenMalo=0, int targetNiv=nivel[1]) {
    if (seenMalo) {
        nivel[v]=targetNiv;
        for(int&u : adj[v]) {
            if (u==p) continue;
            dfs2(u, v, seenMalo, min(nivel[u], nivel[v]-1));
        }
    }
    else {
        // si el mae no es malo, pase a los siguientes nodos como si nada
        if (!malo[v]) {
            for(int&u : adj[v]) {
                if (u==p) continue;
                dfs2(u, v, seenMalo, nivel[u]);
            }
        }
        // si usted es malo, ahora sí, tiene que actualizarle el nivel a sus hijos
        else {
            for(int&u : adj[v]) {
                if (u==p) continue;
                seenMalo=true;
                dfs2(u, v, seenMalo, min(nivel[u], nivel[v]-1));
            }
        }
    }

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    adj.resize(n+1), nivel.resize(n+1),  malo.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1);
    dfs2(1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ifd cout<<"nivel de "<<i<<" = "<<nivel[i]<<endl;
        if (nivel[i] <= 0) ans++;
    }
    cout<<ans<<"\n";

    return 0;
}