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

const ll INF = 1e18;
const int N = 2e5+5;
vector<int> adj[N];
ll dam[N], water[N];
vector<ll> ans;

void dfs(int v, int p = 0) {
    ans[v] = max(ans[p]-water[v], dam[v]-water[v]);
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // De 0 a n
    int n; cin>>n;
    cin>>dam[0];
    water[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        int x; cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
        cin>>dam[i];
        cin>>water[i];
    }

    ans.resize(n+1);
    ans[0] = dam[0];

    dfs(0);

    cout<<*min_element(ans.begin(), ans.end())<<"\n";

    return 0;
}
