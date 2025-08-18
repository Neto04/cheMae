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

const int ANCHO = 21, LARGO = 7;
int n; 
const int N = 1000;
int m[N][N];

int valido(int i, int j) {
    return (i >= 0 and j < n);
}

// Pinta rectangulo 10x15 con esquina superior izquierda en (x,y)
/*
x ... x+9
y
...
y+14
*/
void pintar(int x, int y, int color) {
    for (int i = x; i < x + ANCHO; i++) {
        for (int j = y; j < y + LARGO; j++) {
            if (valido(i,j)) m[i][j] = color;
        }
    }
}

void imprimir() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;

    // Voy moviendome en rectangulos 15x10
    int color = 1;
    for (int i = 0; i < n; i += ANCHO) {
        for (int j = 0; j < n; j += LARGO) {
            // Solo lo pinto cuando no me salgo
            if ((i + ANCHO - 1 < n) and (j + LARGO - 1 < n)) {
                pintar(i,j,color);
                color++;
            };
        }
    } 

    // Ahora llevo control de la cantidad de color
    int cantidad = 150;
    // Empiezo a pintar los bloques que me sobraron a la derecha
    int inicioDerecha = n - (n % LARGO), inicioAbajo = n - (n % ANCHO);
    for (int i = 0; i < inicioAbajo; i++) {
        for (int j = inicioDerecha; j < n; j++) {
            if (cantidad == 0) {
                color++;
                cantidad = 150;
            }
            m[i][j] = color;
            cantidad--;
        }
    }
    // Empiezo a pintar los bloques que me sobraron ababjo
    for (int j = n-1; j >= 0; j--) {
        for (int i = inicioAbajo; i < n; i++) {
            if (cantidad == 0) {
                color++;
                cantidad = 150;
            }
            m[i][j] = color;
            cantidad--;
        }
    }

    ifd {
        int C = 10 + (n*n)/100;
        cout<<"C = "<<C<<endl;
    }

    imprimir();

    return 0;
}
