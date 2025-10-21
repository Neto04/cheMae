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

const int N = 2500;
int v[N][N];
int n, m;

bool posible(int l) {
    // Copia para pintar
    int copia[N][N];
    forn(i, n) forn(j, m) copia[i][j] = v[i][j];
    int count = 0;
    forn(i, n) {
        count = 0;
        forn(j, m) {
            // Si me encuentro a alguien pintable
            if (copia[i][j]) {
                // Si no tengo pintura la refilleo
                if (count == 0) count = l;
                count--;
                copia[i][j] = 0;
                // Pinto para abajo
                for (int k = 1; k <= l-1; k++) {
                    // Si se me acaba el espacio entonces no es posible
                    if (i+k >= n) return false;
                    // Si no es pintable entonces no es posible
                    if (not copia[i+k][j]) return false;
                    // Si todo bien entonces lo pinto
                    copia[i+k][j] = 0;
                }
            } else {
                // Si no es pintable y tengo pintura entonces no es posible
                if (count) return false;
            }
        }
        if (count) return false;
    }
    
    return true;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    // x es el minimo de # consecutivos considerando todas las filas y todas las columnas
    int x = 1e9, count = 0;
    // max de filas
    forn(i, n) {
        count = 0;
        forn(j, m) {
            char c; cin>>c;
            v[i][j] = (c == '#');
            
            // Mientras leo encuentro el max de consecutivos en cada fila
            if (v[i][j]) count++;
            else {
                if (count > 0) x = min(x, count);
                count = 0;
            }
        }
        if (count > 0) x = min(x, count);
    }
    // Max de consecutivos en cada col
    forn(j, m) {
        count = 0;
        forn(i, n) {
            if (v[i][j]) count++;
            else {
                if (count > 0) x = min(x, count);
                count = 0;
            }
        }
        if (count > 0) x = min(x, count);
    }

    int ans = 0;
    for (int l = 1; l*l <= x; l++) {
        if (x % l) continue;
        if (posible(x/l)) {
            cout<<x/l<<"\n";
            return 0;
        }
        if (posible(l)) ans = max(ans, l);
    }

    cout<<ans<<"\n";

    return 0;
}
