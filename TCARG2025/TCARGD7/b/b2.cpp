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

const ll INF = 1e18;
const int N = 500;
int n, mitad;
ll A[N][N];
/*
Los mini se guardan por regiones de la forma
| 1 | 2 | 3 |
-------------
| 4 | 5 | 6 |
-------------
| 7 | 8 | 9 |
*/
ll mini[10];

void calcularmini() {
    for (int i = 1; i <= 9; i++) mini[i] = INF;

    // Minimo 1
    for (int i = 1; i < mitad; i++) {
        for (int j = 1; j < mitad; j++) {
            mini[1] = min(mini[1], A[i][j]);
        }
    }
    // Minimo 2
    for (int i = 1; i < mitad; i++) {
        mini[2] = min(mini[2], A[i][mitad]);
    }
    // Minimo 3
    for (int i = 1; i < mitad; i++) {
        for (int j = mitad+1; j <= n; j++) {
            mini[3] = min(mini[3], A[i][j]);
        }
    }

    // Minimo 4
    for (int j = 1; j < mitad; j++) {
        mini[4] = min(mini[4], A[mitad][j]);
    }
    // Minimo 5
    mini[5] = A[mitad][mitad];
    // Minimo 6
    for (int j = mitad+1; j <= n; j++) {
        mini[6] = min(mini[6], A[mitad][j]);
    }

    // Minimo 7
    for (int i = mitad+1; i <= n; i++) {
        for (int j = 1; j < mitad; j++) {
            mini[7] = min(mini[7], A[i][j]);
        }
    }
    // Minimo 8
    for (int i = mitad+1; i <= n; i++) {
        mini[8] = min(mini[8], A[i][mitad]);
    }
    // Minimo 9
    for (int i = mitad+1; i <= n; i++) {
        for (int j = mitad+1; j <= n; j++) {
            mini[9] = min(mini[9], A[i][j]);
        }
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) 
    {
        cin>>n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin>>A[i][j];
            }
        }
        mitad = n/2+1;
        calcularmini();

        ifd {
            cout<<"Los mini son: ";
            for (int i = 1; i <= 9; i++) cout<<mini[i]<<" ";
            cout<<endl;
        }   
        const int FIN = 10;
        ll ans = mini[5];
        vector<ll> comp={mini[1]+mini[3]+mini[7]+mini[9], 
            mini[1]+mini[3]+mini[8], 
            mini[2]+mini[7]+mini[9], 
            mini[4]+mini[3]+mini[9],
            mini[1]+mini[7]+mini[6],
            mini[2]+mini[6]+mini[7],
            mini[6]+mini[8]+mini[1],
            mini[8]+mini[4]+mini[3],
            mini[4]+mini[2]+mini[9],
            mini[2]+mini[8],
            mini[4]+mini[6]
        };
        for(auto u:comp) ans = min(ans, u);
        cout<<ans<<"\n";
        
        
        
    }
    return 0;
}
