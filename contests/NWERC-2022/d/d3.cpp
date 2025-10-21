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

#define ld double

const ld C = 10.0*3.14159265;
const ld INF = (ld)1e18;
const int N = 700, N2 = 5e6+5;

vector<vector<pair<int,ld>>> adj;

int n, m;
int ans = -1;

ld dijkstra() {
    bitset<5000000> processed;
    //vector<bool> processed(siguiente+1, false);
    vector<ld> dist(ans+1, INF);
    priority_queue<pair<ld, int>> q;
    dist[1] = 0.0;
    q.push({0.0,1});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first; ld w = u.second;
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b], b});
            }
        }
    }
    return dist[ans];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    int v = 1;
    int ultimoV = -1;

    // First pass: just compute node indices
    forn(i,n) {
        if (v != 1) v = (v + 1 + 2*m + 1);
        forn(j,m) {
            char c; cin >> c;
            bool circulo = (c == 'O');
            // We don’t add edges yet, just update v
            v += 2;
        }
    }

    ans = v + 4*m + 2;
    int num_nodes = ans;

    // Now allocate adjacency list
    adj.assign(num_nodes+1, {});

    // Reset v and re-read input to actually build edges
    cin.clear();
    cin.seekg(0, ios::beg);
    cin >> n >> m;
    v = 1;

    forn(i,n) {
        if (v != 1) v = (v + 1 + 2*m + 1);
        forn(j,m) {
            char c; cin >> c;
            bool circulo = (c == 'O');

            if (i == 0) {
                adj[v].push_back({v+1, 5.0});
                adj[v+1].push_back({v, 5.0});
                adj[v+1].push_back({v+2, 5.0});
                adj[v+2].push_back({v+1, 5.0});
            }
            adj[v+4*m+2].push_back({v+4*m+3, 5.0});
            adj[v+4*m+3].push_back({v+4*m+2, 5.0});
            adj[v+4*m+3].push_back({v+4*m+4, 5.0});
            adj[v+4*m+4].push_back({v+4*m+3, 5.0});

            if (j == 0) {
                adj[v].push_back({v+2*m+1, 5.0});
                adj[v+2*m+1].push_back({v, 5.0});
                adj[v+2*m+1].push_back({v+4*m+2, 5.0});
                adj[v+4*m+2].push_back({v+2*m+1, 5.0});
            }
            adj[v+2].push_back({v+2*m+3, 5.0});
            adj[v+2*m+3].push_back({v+2, 5.0});
            adj[v+2*m+3].push_back({v+4*m+4, 5.0});
            adj[v+4*m+4].push_back({v+2*m+3, 5.0});

            if (circulo) {
                adj[v+1].push_back({v+2*m+3, C/4.0});
                adj[v+2*m+3].push_back({v+1, C/4.0});

                adj[v+2*m+3].push_back({v+4*m+3, C/4.0});
                adj[v+4*m+3].push_back({v+2*m+3, C/4.0});

                adj[v+4*m+3].push_back({v+2*m+1, C/4.0});
                adj[v+2*m+1].push_back({v+4*m+3, C/4.0});

                adj[v+2*m+1].push_back({v+1, C/4.0});
                adj[v+1].push_back({v+2*m+1, C/4.0});
            }
            v += 2;
        }
    }

    ifd cout << "ans = " << ans << endl;

    cout << setprecision(6) << fixed << dijkstra() << "\n";
    return 0;
}
