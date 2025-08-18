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

const int N = 405;
int n, m;
int adj[N][N];

bool soyTren=true;

int bfs(int x) {
    queue<int> q;
    vector<bool> visited(N);
    vector<int> dist(N);

    visited[x] = true;
    dist[x] = 0;
    q.push(x);
    int arista = soyTren;
    ifd cout<<"Quiero aristas de valor "<<arista<<endl;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (int u = 1; u <= n; u++) {
            if (visited[u]) continue;
            if (adj[s][u] == arista&&s!=u) {
                visited[u] = true;
                dist[u] = dist[s]+1;
                q.push(u);
    
                if (u == n) {
                    ifd cout<<"Hay una arista de "<<s<<" a "<<u<<endl;
                    return dist[u];
                }
            }
        }
    }

    return -1;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1;
        
    }

    if (adj[1][n]) soyTren=false;

    cout<<bfs(1)<<endl;

    return 0;
}
