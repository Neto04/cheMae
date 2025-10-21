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

int n, m;
vector<vector<char>> G;

// arriba, abajo, izq, der
const vector<int> dI = {-1, 1, 0, 0}, dJ = {0, 0, -1, 1};

bool valid(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m);
}

// Si reviso radio r supongo que ya r-1 es valido
bool check(int i, int j, int r) {
    // Horizontales
    if (j-r < 0 or j+r >= m) return false;
    if (G[i][j-r] != '-' or G[i][j+r] != '-') return false;

    // Arriba y abajo
    for (int j2 = j-r; j2 <= j+r; j2++) {
        // c es lo que tengo que encontrarme
        char  c1 = '.', c2 = '.';
        if (j2 == j-r) c1 = '\\', c2 = '/';
        else if (j2 == j) c1 = '|', c2 = '|';
        else if (j2 == j+r) c1 = '/', c2 = '\\';

        if (not valid(i-r,j2) or not valid(i+r,j2)) return false;
        if ((c1 != '.' and G[i-r][j2] != c1) or (c2 != '.' and G[i+r][j2] != c2)) return false;
    } 

    // Izq y der
    for (int i2 = i-r; i2 <= i+r; i2++) {
        // c es lo que tengo que encontrarme
        char c1 = '.', c2 = '.';
        if (i2 == i-r) c1 = '\\', c2 = '/';
        else if (i2 == i) c1 = '-', c2 = '-';
        else if (i2 == i+r) c1 = '/', c2 = '\\';

        if (not valid(i2,j-r) or not valid(i2,j+r)) return false;
        if ((c1 != '.' and G[i2][j-r] != c1) or (c2 != '.' and G[i2][j+r] != c2)) return false;
    } 

    return true;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    G.assign(n, vector<char>(m));
    
    forn(i,n) forn(j,m) {
        cin>>G[i][j];
    }

    // ifd {
    //     forn(i,n) {
    //         forn(j,m) cout<<G[i][j];
    //         cout<<endl;
    //     }
    // }

    int ans = 0;
    forn(i,n) forn(j,m) {
        if (G[i][j] == '+') {
            bool seguir = true;
            for (int r = 1; r <= 50 and seguir; r++) {
                //ifd cout<<"Probar r = "<<r<<" en ("<<i<<","<<j<<")"<<endl;
                if (check(i,j,r)) ans = max(ans, r);
                else seguir = false;
            }
        }
    }

    cout<<ans<<"\n";

    return 0;
}
