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

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int tC; cin>>tC;

    while (tC--) {
        int n, m; cin>>n>>m;
        vector<vector<int>> v(n, vector<int>(m));
        forn(i, n) forn(j, m) {
            char c; cin>>c;
            v[i][j] = (c == '.');
        }

        // 0 arr, 1 abaj
        // max cadena vertical free que empieza en el punto (i, j) (0 si va hacia arriba, 1 si va hacia abajo)
        vector<vector<vector<int>>> free(2, vector<vector<int>>(n, vector<int>(m)));
        vector<vector<int>> maxCol(2, vector<int>(m));
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (!v[i][j]) free[0][i][j]=0;
                else {
                    free[0][i][j] = 1;
                    if (i > 0) free[0][i][j] += free[0][i-1][j];
                    maxCol[0][j] = max(maxCol[0][j], free[0][i][j]);
                }
            }
            if (j > 0) maxCol[0][j] = max(maxCol[0][j], maxCol[0][j-1]);
        }

        for (int j = m-1; j >= 0; j--) {
            for (int i = n-1; i >= 0; i--) {
                if (!v[i][j]) free[1][i][j]=0;
                else {
                    free[1][i][j] = 1;
                    if (i < n-1) free[1][i][j] += free[1][i+1][j];
                    maxCol[1][j] = max(maxCol[1][j], free[1][i][j]);
                }
            }
            if (j < m-1) maxCol[1][j] = max(maxCol[1][j], maxCol[1][j+1]);
        }

        // freeBajon guarda el maximo free hasta es momento
        vector<vector<vector<int>>> freeBajon(2, vector<vector<int>>(n, vector<int>(m)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                freeBajon[0][i][j] = free[0][i][j];
                if (i > 0) freeBajon[0][i][j] = max(freeBajon[0][i][j], freeBajon[0][i-1][j]);
            }
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                freeBajon[1][i][j] = free[1][i][j];
                if (i < n-1) freeBajon[1][i][j] = max(freeBajon[1][i][j], freeBajon[1][i+1][j]);
            }
        }

        // maxColBajon es como maxCol pero para arriba y abajo
        vector<vector<int>> maxColBajon(2, vector<int>(n));
        for (int i = 0; i < n; i++) {
            maxColBajon[0][i] = 0;
            for (int j = 0; j < m; j++) {
                maxColBajon[0][i] = max(maxColBajon[0][i], freeBajon[0][i][j]);
                if (i > 0) maxColBajon[0][i] = max(maxColBajon[0][i], maxColBajon[0][i-1]);
            }
        }
        for (int i = n-1; i >= 0; i--) {
            maxColBajon[1][i] = 0;
            for (int j = 0; j < m; j++) {
                maxColBajon[1][i] = max(maxColBajon[1][i], freeBajon[1][i][j]);  
                if (i < n-1) maxColBajon[1][i] = max(maxColBajon[1][i], maxColBajon[1][i+1]);
            }
        }

        // Agarro dos filas
        int f1 = 0, f2 = 0;
        int ans1 = 0;
        int l = 0;
        for (int i = 0; i < n; i++) {
            l = 0;
            for (int j = 0; j < m; j++) {
                if (v[i][j]) l++;
                else {
                    if (l > f1) f2 = f1, f1 = l;
                    else if (l > f2) f2 = l;
                    l = 0;
                }
            }
            if (l > f1) f2 = f1, f1 = l;
            else if (l > f2) f2 = l;
        }
        ifd cout<<"f1 = "<<f1<<", f2 = "<<f2<<endl;
        ans1 = f1+f2;

        // Agarro dos columnas
        int ans2 = 0;
        int c1 = 0, c2 = 0;
        l = 0;
        for (int j = 0; j < m; j++) {
            l = 0;
            for (int i = 0; i < n; i++) {
                if (v[i][j]) l++;
                else {
                    if (l > c1) c2 = c1, c1 = l;
                    else if (l > c2) c2 = l;
                    l = 0;
                }
            }
            if (l > c1) c2 = c1, c1 = l;
            else if (l > c2) c2 = l;
        }
        ifd cout<<"c1 = "<<c1<<", c2 = "<<c2<<endl;
        ans2 = c1+c2;

        // Agarro una fila y una columna
        int ans3 = 0;
        int inicio = -1;
        l = 0;
        for (int i = 0; i < n; i++) {
            inicio = -1, l = 0;
            for (int j = 0; j < m; j++) {
                if (v[i][j]) {
                    // Si inicio = 1 empiezo una nueva fila
                    if (inicio == -1) inicio = j, l = 0;
                    l++;
                    if (inicio > 0) ans3 = max(ans3, l + maxCol[0][inicio-1]);
                    if (j < m-1) ans3 = max(ans3, l + maxCol[1][j+1]);
                    if (i > 0) ans3 = max(ans3, l + maxColBajon[0][i-1]);
                    if (i < n-1) ans3 = max(ans3, l + maxColBajon[1][i+1]);
                } else {
                    inicio = -1, l = 0;
                }
            }
        }

        cout<<max(ans1, max(ans2, ans3))<<"\n";
    }
    return 0;
}
