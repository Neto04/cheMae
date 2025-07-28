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

const int N = 2005;

int n, m, r, c, x, y;

// Arriba, abajo, izq, der
int dI[4] = {-1, 1, 0, 0};
int dJ[4] = {0, 0, -1, 1};

char G[N][N];
// Movimientos {izq, der}
ii dist[N][N];

bool valid(ii v) {
    int i = v.first, j = v.second;
    return (i >= 1 and i <= n and j >= 1 and j <= m);
}

void bfs() {
    queue<ii> q;
    G[r][c] = '+';
    q.push({r,c});

    while (!q.empty()) {
        ii s = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            // Si voy para la izq o der y ya no puedo continue
            if (k == IZQ and dist[s.first][s.second].first + 1 > x) continue;
            else if (k == DER and dist[s.first][s.second].second + 1 > y) continue;

            ii u = {s.first + dI[k], s.second + dJ[k]};

            if (!valid(u) or G[u.first][u.second] == '+' or 
                G[u.first][u.second] == '*') continue;

            G[u.first][u.second] = '+';
            dist[u.first][u.second] = dist[s.first][s.second];
            // Aumento el contador de izq o der
            if (k == IZQ) (dist[u.first][u.second]).first ++;
            else if (k == DER) (dist[u.first][u.second]).second ++;
            q.push(u);
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
        }
    }
    
    dist[r][c] = {0,0};
    bfs();

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
