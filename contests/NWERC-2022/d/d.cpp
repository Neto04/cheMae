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

#define cuadrado 0
#define circulo 1 
typedef double ld;

const ld C = 10.0*3.14159265;
const ld INF = (ld)1e18;
const int N = 700, N2 = 3920000;

vector<vector<pair<int,ld>>> adj;

int n, m;
int ans = -1;

int siguiente = 1;

ld dijkstra() {
    bitset<3920000> processed;
    //vector<bool> processed(siguiente+1, false);
    vector<ld> dist(siguiente+1, INF);
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

    //vector<vector<int>> M;
    vector<vector<vector<int>>> G;

    cin>>n>>m;
    G.assign(n, vector<vector<int>>(m, vector<int>(8)));
    //M.assign(n, vector<int>(m));

    forn(i,n) {
        forn(j,m) {
            char c; cin>>c;
            G[i][j].assign(9, -1);
            if (c == 'X') G[i][j][8] = cuadrado;
            else G[i][j][8] = circulo;
        }
    }

    forn(i,n) {
        forn(j,m) {
            // Si tengo a alguien arriba, tiene mi 0, 1, 2
            if (i > 0) {
                G[i][j][0] = G[i-1][j][6];
                G[i][j][1] = G[i-1][j][5];
                G[i][j][2] = G[i-1][j][4];
            }
            // Si ya tengo a alguien a la izquierda, tiene mi 0, 7, 6
            if (j > 0) {
                G[i][j][0] = G[i][j-1][2];
                G[i][j][7] = G[i][j-1][3];
                G[i][j][6] = G[i][j-1][4];
            }
            forn(k,8) if (G[i][j][k] == -1) G[i][j][k] = siguiente++;

            
        }
    }
    adj.resize(siguiente+1);
    forn(i, n) {
        forn(j, m) {
            // Cuando tengo enumeradas mis cosas guardo las distancias
            // Entre esquinas y puntos medios
            forn(k,8) {
                int a = G[i][j][k], b = G[i][j][(k+1)%8];
                if (a == 0 and b == 1 and i > 0) continue;
                if (a == 1 and b == 2 and i > 0) continue; 
                if (a == 6 and b == 7 and j > 0) continue;
                if (a == 7 and b == 0 and j > 0) continue; 
                adj[a].push_back({b, 5.0});
                adj[b].push_back({a, 5.0});
            }
            // Si es circulo tambien entre puntos medios
            if (G[i][j][8] == circulo) {
                for (int k = 1; k < 8; k += 2) {
                    int a = G[i][j][k], b = G[i][j][(k+2)%8];
                    adj[a].push_back({b, C/4.0});
                    adj[b].push_back({a, C/4.0});  
                }
            }

            if (i == n-1 and j == m-1) ans = G[i][j][4];
        }
    }



    G.clear();
    //M.clear();

    ifd {
        // cout<<"Esquinas:"<<endl;
        // forn(i,n) forn(j,m) {
        //     cout<<"Esquinas de ("<<i<<","<<j<<"): ";
        //     forn(k,8) cout<<G[i][j][k]<<" ";
        //     cout<<endl;
        // }

        cout<<"Adyacentes:"<<endl;
        for(int i = 1; i < siguiente; i++) {
            cout<<"Adyacentes de "<<i<<endl;
            for (auto x : adj[i]) cout<<x.first<<" ";
            cout<<endl;
        }
    }

    cout<<setprecision(6)<<fixed<<dijkstra()<<"\n";

    return 0;
}
