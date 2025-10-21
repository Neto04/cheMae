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
vector<int> adj[N];
ll maes[N];
// turnos, cant
map<int,ll> d[N], d2[N];
// cant, turno
pair<ll,int> ans;

void dfs(int v, int p = 0) {
    // turnos, cant
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        if (d[v].size() < d2[u].size()) swap(d[v], d2[u]);
        for (const pair<int,ll>& x : d2[u]) d[v][x.first] += d2[u][x.first];
    }

    // El nodo 1 no actualiza la respuesta
    if (v == 1) return;

    // Actualizo la respuesta
    int maxTurno = 0;
    d[v][1] += maes[v];
    for (const pair<int,ll>& x : d[v]) {
        int turno = x.first; ll count = x.second;
        maxTurno = max(turno, maxTurno);

        if (count > ans.first) {
            ans = {count, turno};
        } else if (count == ans.first) {
            ans = {count, min(turno, ans.second)};
        }

        d2[v][x.first+1] = d[v][x.first];
    }

    // // Aumento el turno de todos para mi papa
    // for (int i = maxTurno; i >= 1; i--) {
    //     //ifd cout<<"En "<<i<<" turnos hay "<<d[v][i]<<" maes en el nodo "<<v<<endl;
    //     d[v][i+1] = d[v][i];
    //     d[v].erase(i);
    // }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    for (int i = 2; i <= n; i++) {
        cin>>maes[i];
    }
    forn(i, n-1) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = {0, 1e9};

    dfs(1);
    cout<<ans.first<<" "<<ans.second<<"\n";

    return 0;
}
