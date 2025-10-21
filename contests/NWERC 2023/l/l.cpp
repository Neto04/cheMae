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

int n, k;
bool valid(int i, int j) {
    return (i >= 1 and i <= n and j >= 1 and j <= n);
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    int sunk = 0;
    string ans;
    for (int i = 1; i <= n and sunk < k; i++) {
        for (int j = 1; j <= n and sunk < k; j++) {
            // Si esto pasa, entonces estoy en una diagonal
            if ((i+j)%5 == 1) {
                cout<<i<<" "<<j<<endl;
                cin>>ans;
                // Si hay un hit, ataco las siguientes 4 casillas en las 4 direcciones
                if (ans[0] == 'h') {
                    bool seguir = true;
                    for (int k = 1; k <= 4 and seguir; k++) {
                        // Arriba
                        if (seguir and valid(i-k,j)) {
                            cout<<i-k<<" "<<j<<endl;
                            cin>>ans;
                            if (ans[0] == 's') seguir = false;
                        }
                        // Abajo
                        if (seguir and valid(i+k,j)) {
                            cout<<i+k<<" "<<j<<endl;
                            cin>>ans;
                            if (ans[0] == 's') seguir = false;
                        }
                        // Izquierda
                        if (seguir and valid(i,j-k)) {
                            cout<<i<<" "<<j-k<<endl;
                            cin>>ans;
                            if (ans[0] == 's') seguir = false;
                        }
                        // Derecha
                        if (seguir and valid(i,j+k)) {
                            cout<<i<<" "<<j+k<<endl;
                            cin>>ans;
                            if (ans[0] == 's') seguir = false;
                        }
                    }
                    sunk++;
                } else if (ans[0] == 's') { // Sunk
                    sunk++;
                }
            }
        }
    }

    return 0;
}
