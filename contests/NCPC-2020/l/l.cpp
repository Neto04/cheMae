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

// Valor de cada letra
vector<ll> valor(26);

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll rand64() {
	// vea que puede tener 250000 números, cuya suma puede darle A LO SUMO 4e12
  return uniform_int_distribution<int64_t>(0, 1000000000000)(rng);
}

const int MAX = 45;
int l, c, n;

// Sopa con hashes
ll sopa[MAX][MAX]; 
ll cant[MAX][MAX];
bool bueno[MAX][MAX];

// Hash y tamano de cada palabra
vector<ll> hashes, tamanos;

// vert para abajo, hor para izq, \ (desde izq), / (desde izq), \ (desde der), / (desde der),
// \ (desde arriba), / (desde arriba)
const vector<int> dI = {1, 0,  1, -1,  -1, 1,  1, 1};
const vector<int> dJ = {0, 1,  1, 1,  -1, -1,  1, -1};

bool valid(int i, int j) {
    return (i >= 0 and i < l and j >= 0 and j < c);
}

void buscar(int palabra, int dir) {
    ifd cout<<"dir = "<<dir<<endl;
    // Valor de la ventana
    ll goal = hashes[palabra], tamano = tamanos[palabra];
    ll ventana = 0;
    deque<pair<int,int>> maes;

    // Empiezo a buscar en cada columna si es vertical, si no empiezo en cada fila
    int limite = l; 
    if (dir == 0 or dir > 5) limite = c;
    for (int inicio = 0; inicio < limite; inicio++) {
        int i = 0, j = 0;
        // Si busco en vertical empiezo a buscar en cada columna desde arriba
        if (dir == 0 or dir > 5) i = 0, j = inicio;
        // Si es una diagonal desde la derecha, empiezo a buscar en cada fila pero desde la ultima columna
        else if (dir > 3) i = inicio, j = c-1;
        // Si no, empiezo a buscar en cada fila desde la primera columna
        else i = inicio, j = 0;

        while (valid(i,j)) {
            // Si no he llegado al tamano de la palabra solo actualizo la ventana
            if (maes.size() < tamano) {
                maes.push_back({i,j});
                ventana += sopa[i][j];
                // Reviso si acabo de llegar al tamano y me sirve
                if (maes.size() == tamano and ventana == goal) {
                    ifd {
                        cout<<"Me sirve empezar en ("<<maes.front().first<<","<<maes.front().second
                        <<") y terminar en ("<<maes.back().first<<","<<maes.back().second<<")"<<endl;
                    }
                    for (auto mae : maes) bueno[mae.first][mae.second] = true;
                }
            } else { // maes.size() == tamano
                ventana -= sopa[maes.front().first][maes.front().second];
                maes.pop_front();
                maes.push_back({i,j});
                ventana += sopa[i][j];
                if (maes.size() == tamano and ventana == goal) {
                    ifd {
                        cout<<"Me sirve empezar en ("<<maes.front().first<<","<<maes.front().second
                        <<") y terminar en ("<<maes.back().first<<","<<maes.back().second<<")"<<endl;
                    }
                    for (auto mae : maes) bueno[mae.first][mae.second] = true;
                }
            }
            i += dI[dir];
            j += dJ[dir];
        }
        ventana = 0;
        maes.clear();
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    forn(i, 26) valor[i] = (rand64()+1);

    cin>>l>>c;
    forn(i,l) {
        forn(j,c) {
            char C; cin>>C;
            sopa[i][j] = valor[C-'A'];
            cant[i][j] = 0LL;
            bueno[i][j] = false;
        }
    }
    
    cin>>n;
    hashes.assign(n, 0LL), tamanos.assign(n, 0LL);
    // Precalculo el hash y tamano de cada palabra
    forn(i,n) {
        string s; cin>>s;
        for (char C : s) {
            tamanos[i]++;
            hashes[i] += valor[C-'A'];
        }
    }

    // Buscar cada palabra en las cuatro direcciones
    forn(palabra,n) {
        ifd cout<<"Voy a buscar la palabra "<<palabra<<endl;
        // Busco las casillas buenas en todas las direcciones
        forn(dir,8) buscar(palabra, dir);
        // Le sumo uno a todas las casillas buenas
        forn(i,l) forn(j,c) {
            if (bueno[i][j]) cant[i][j]++;
            // Voy limpiando la matriz para las siguientes palabras
            bueno[i][j] = false;
        }
    }

    ifd {
        forn(i,l) {
            forn(j,c) cout<<cant[i][j]<<" ";
            cout<<endl;
        }
    }

    ll ans = 0;
    forn(i,l) forn(j,c) if (cant[i][j] >= 2) ans++;
    cout<<ans<<"\n";

    return 0;
}
