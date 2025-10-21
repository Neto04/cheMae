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

int n, r, c;
bool valid (int i, int j) {
    return (i >= 0 and i < r and j >= 0 and j < c);
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    freopen("class.in", "r", stdin);
    freopen("class.out", "w", stdout);
    cin>>n>>r>>c;
    vector<vector<char>> ans(r, vector<char>(c, '.'));
    ans[0][0] = '#';
    n--;
    int i = 1;
    while (n) {
        if (!valid(i,0) and !valid(0,i)) break;
        // Lleno la primera columna
        if (n and valid(i,0)) {
            ans[i][0] = '#';
            n--;
        }
        // Y la primera fila
        if (n and valid(0,i)) {
            ans[0][i] = '#';
            n--;
        }
        i++;
    }

    // Lleno el resto
    forn(i,r) forn(j,c) {
        if (n and ans[i][j] == '.') {
            ans[i][j] = '#';
            n--;
        }
    }

    int maxFila = 0, maxColumna = 0;
    forn(i,r) {
        int count = 0;
        forn(j,c) if (ans[i][j] == '#') count++;
        maxFila = max(maxFila, count);
    }
    forn(j,c) {
        int count = 0;
        forn(i,r) if (ans[i][j] == '#') count++;
        maxColumna = max(maxColumna, count);
    }

    cout<<min(maxFila,maxColumna)<<"\n";
    forn(i,r) {
        forn(j,c) cout<<ans[i][j];
        cout<<"\n";
    }

    return 0;
}
