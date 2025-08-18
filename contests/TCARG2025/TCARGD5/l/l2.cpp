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

#define ARR 0
#define ABA 1
#define IZQ 2
#define DER 3

const int INF = 1e9;
const int N = 2005;

int n, m, r, c, x, y;

// Arriba, abajo, izq, der
int dI[4] = {-1, 1, 0, 0};
int dJ[4] = {0, 0, -1, 1};

char G[N][N];
// Movimientos hacia la izquierda
int dist[N][N];
bool alcanzable[N][N], visited[N][N];

bool valid(ii v) {
    int i = v.first, j = v.second;
    return (i >= 1 and i <= n and j >= 1 and j <= m);
}

// Minimiza izquierdas
void dijkstra() {
    priority_queue<pair<int,ii>> q;
    dist[r][c] = 0;
    q.push({0,{r,c}});

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[i][j] = false;
            dist[i][j] = INF;
        }
    }
            
    while (!q.empty()) {
        ii a = (q.top()).second; q.pop();
        if (visited[a.first][a.second]) continue;
        visited[a.first][a.second] = true;

        for (int k = 0; k < 4; k++) {
            ii b = {a.first + dI[k], a.second + dJ[k]};
            int w = dist[a.first][b.first] + (k == IZQ ? 1 : 0);
            if (dist[a.first][b.first] + w < )
        }
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    cin>>r>>c;
    cin>>x>>y;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin>>c;
            G[i][j] = c;
            alcanzable[i][j] = false;
        }
    }
    
    dijkstra();

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ifd cout<<G[i][j];
            if (G[i][j] == '+') ans++; 
        }
        ifd cout<<"\n";
    }
    ifd cout<<endl;

    cout<<ans<<"\n";

    return 0;
}
