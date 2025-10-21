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

int n;
vector<vector<int>> adj;
vector<int> parent;
// dfs desde el nodo i
// asigna papas, marca nodos con targetNivel
int dfs1 (int i) {
    int niv1=-1, niv2=-1;
    for(auto u:adj[i]) {
        if (u==parent[i]) continue;
        parent[u]=i;
        if (niv1==-1) niv1 = dfs1(u);


    }

}



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n; adj.resize(n);
    forn(i, n-1) {
        int a,b; cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

}
