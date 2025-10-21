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

#define debil 0
#define fuerte 1

int n;
vector<ll> val, conRe, sinRe;
vector<vector<pair<int,int>>> adj;

void dfs(int v, int p = 0) {
    ifd cout<<"estoy en el nodo "<<v<<" con papá "<<p<<endl;
    for (const pair<int,int>& e : adj[v]) {
        int u = e.first, w = e.second;
        if (u == p) continue;
        dfs(u,v);
    }
    ifd cout<<"ok, como iba diciendo, estoy en "<<v<<" con papá"<<p<<endl;
    conRe[v] = val[v];
    ifd cout<<"recuerde que v tiene valor "<<val[v]<<endl;
    ll conReTodos = 0LL;
    for (const pair<int,int>& e : adj[v]) {
        int u = e.first, w = e.second;

        if (u == p ) continue;
        if (w==debil) continue;
        conReTodos += conRe[u];
        ifd cout<<"me como conRe de "<<u<<" que vale "<<conRe[u]<<endl;
        conRe[v] += conRe[u];
    }
    
    conRe[v] = max(0LL, conRe[v]);
    ifd cout<<"de donde al final conRe["<<v<<"] vale "<<conRe[v]<<endl;
    ifd cout<<"y conReTodos = "<<conReTodos<<endl;
    sinRe[v] = 0LL;
    for (const pair<int,int>& e : adj[v]) {
        int u = e.first, w = e.second;
        if (u==p) continue;
        ll sobra = conReTodos;
        if (w !=debil) sobra -=conRe[u];
        ifd cout<<"ahora sí, me fijo en el sinRe de "<<u<<",  que vale "<<sinRe[u]<<endl;
        sinRe[v] = max(sinRe[v], sobra+sinRe[u]);
        ifd cout<<"con lo que sinRe"<<v<<" ahorita = "<<sinRe[v]<<endl;
    }

    sinRe[v] = max(0LL, sinRe[v] + val[v]);
    ifd cout<<"entonces al final sinRe["<<v<<"] = "<<sinRe[v]<<endl;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        cin>>n;
        val.resize(n+1), conRe.resize(n+1), sinRe.resize(n+1), 
            adj.assign(n+1, vector<pair<int,int>>());
        for (int i = 1; i <= n; i++) cin>>val[i];
        for (int i = 1; i <= n-1; i++) {
            int u, v, w; cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(1);
        





        // AHORA A CALCULAR LO DE 1
        ll conReTodos=0;
        conRe[1]=val[1];
        for (const pair<int,int>& e : adj[1]) {
            int u = e.first, w = e.second;
            if (w==debil) continue;
            conReTodos += conRe[u];
            conRe[1] += conRe[u];
        }
        sinRe[1]=0;

        for (const pair<int,int>& e : adj[1]) {
            int u = e.first, w = e.second;
            
            ll sobra = conReTodos;
            if (w !=debil) sobra -=conRe[u];
            ifd cout<<"ahora sí, me fijo en el sinRe de "<<u<<",  que vale "<<sinRe[u]<<endl;
            sinRe[1] = max(sinRe[1], sobra+sinRe[u]);
            ifd cout<<"con lo que sinRe"<<1<<" ahorita = "<<sinRe[1]<<endl;
        }
        sinRe[1]+=val[1];

        cout<<max(conRe[1], sinRe[1])<<"\n";
    }

    return 0;
}
