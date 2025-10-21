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
map<int,ll,greater<int>> d[N], d2[N];
// cant, turno
pair<ll,int> ans;

void dfs(int v, int p = 0) {
    if (maes[v] >= ans.first) ans = {maes[v], 1};
    d2[v][2] = maes[v]; 

    ll maxi = 0;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        if (d[v].size() < d2[u].size()) swap(d[v], d2[u]);
        for (const pair<int,ll>& x : d2[u]) {
            ifd cout<<"Sumarle "<<x.second<<" a lo que le llega a "<<v<<endl;
            ifd cout<<"Sumarle "<<x.second<<" a lo que le va a llegar a "<<p<<endl;
            d[v][x.first] += x.second;
            d2[v][x.first+1] += x.second;
            if (v != 1) {
                maxi = max(maxi, d[v][x.first]);
                if (maxi > ans.first) {
                    ans = {maxi, x.first};
                } else if (maxi == ans.first) {
                    ans = {maxi, min(x.first, ans.second)};
                }
            }
        }
    }

    ifd {
        for (auto x : d[v]) {
            cout<<"A "<<v<<" le llego "<<x.second<<" en "<<x.first<<" turnos"<<endl;
        }
        for (auto x : d2[v]) {
            cout<<"A "<<p<<" le van a llegar "<<x.second<<" en "<<x.first<<" turnos"<<endl;
        }
        cout<<endl;
    }
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
