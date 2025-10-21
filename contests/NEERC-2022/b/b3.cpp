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

        // 0 Up, 1 abaj
        // max cadena vertical free que empieza en el punto (i, j) (0 si va hacia Upiba, 1 si va hacia abajo)
        vector<vector<ll>> free(n, vector<ll> (m));
        // PRIMERO ENCUENTRE PARA CADA CASILLA CUAL ES LA MAX COL HACIA UpIBA QUE EXISTE EMPEZANDO EN ESA CASILLA
        forn(i, n) {
            forn(j, m) {
                if (v[i][j]) {
                    free[i][j]=1;
                    if (i>0) free[i][j]+=free[i-1][j];
                }
                
            }
        }
        
        // AHORA ENCUENTRE PARA UNA FILA, CUÁL ES LA MAX COLUMNA DE AHÍ UpIBA
        vector<ll> maxCadUp(n);
        forn(i,n) {
            forn(j, m) maxCadUp[i]=max(maxCadUp[i], free[i][j]);
            if (i>0) maxCadUp[i]=max(maxCadUp[i], maxCadUp[i-1]);
        }
        
        ifd {
            cout<<"maxCadUp"<<endl;
            forn(i, n) cout<<maxCadUp[i]<<" ";
            cout<<endl;
        }
        vector<ll> maxCadIzq(m);
        forn(j, m) {
            forn(i, n) maxCadIzq[j] = max(maxCadIzq[j], free[i][j]);
            if (j>0) maxCadIzq[j] = max(maxCadIzq[j], maxCadIzq[j-1]);
        }
        ifd {
            cout<<"maxCadIzq"<<endl;
            forn(j, m) cout<<maxCadIzq[j]<<" ";
            cout<<endl;
        }
        vector<ll> maxCadDer(m);
        for(int j=m-1; j>=0; j--) {
            forn(i, n) maxCadDer[j]=max(maxCadDer[j], free[i][j]);
            if (j<m-1) maxCadDer[j] = max(maxCadDer[j], maxCadDer[j+1]);
        }
        ifd {
            cout<<"maxCadDer"<<endl;
            forn(j, m) cout<<maxCadDer[j]<<" ";
            cout<<endl;
        }


        forn(i, n) forn(j, m) free[i][j]=0;
        for(int i=n-1; i>=0; i--) {
            forn(j, m){
                if (v[i][j]) {
                        free[i][j]=1;
                        if (i<n-1) free[i][j]+=free[i+1][j];
                }
            }
        }
        vector<ll> maxCadDown(n);
        for(int i=n-1; i>=0; i--) {
            forn(j, m) maxCadDown[i]=max(maxCadDown[i], free[i][j]);
            if (i<n-1) maxCadDown[i]=max(maxCadDown[i], maxCadDown[i+1]);
        }

        ifd {
            cout<<"maxCadDown"<<endl;
            forn(i, n) cout<<maxCadDown[i]<<" ";
            cout<<endl;
        }
        // AgUpo dos filas
        int f1 = 0, f2 = 0;
        ll ans1 = 0;
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

        // AgUpo dos columnas
        ll ans2 = 0;
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


        ifd cout<<"ans1 = "<<ans1<<", ans2="<<ans2<<endl;




        ll inicio=-1;
        ll ans =max(ans1, ans2);
        forn(i, n) {
            inicio =-1;
            forn(j, m) {
                if (v[i][j] and inicio==-1) inicio=j;
                else if (!v[i][j]) {
                    inicio=-1;
                    continue;
                }
                ifd cout<<"para i = "<<i<<", j = "<<j<<"inicio = "<<inicio<<endl;
                ll cAns = 0;
                if (i<n-1) cAns=max(cAns, maxCadDown[i+1]);
                ifd cout<<"cans = "<<cAns<<endl;
                if (i>0) cAns = max(cAns, maxCadUp[i-1]);
                ifd cout<<"cans = "<<cAns<<endl;
                if (j<m-1) cAns=max(cAns, maxCadDer[j+1]);
                ifd cout<<"cans = "<<cAns<<endl;
                if (inicio>0) cAns = max(cAns, maxCadIzq[inicio-1]);
                ifd cout<<"cans = "<<cAns<<endl;
                ifd cout<<"cAns = "<<cAns<<" + "<<(j-inicio+1)<<endl;
                ans = max ((j-inicio+1)+cAns, ans);
            }
        }

        inicio=-1;
        forn(i, n) {
            inicio =-1;
            for(int j = m-1; j >= 0; j--) {
                if (v[i][j] and inicio==-1) inicio=j;
                else if (!v[i][j]) {
                    inicio=-1;
                    continue;
                }
                ifd cout<<"para i = "<<i<<", j = "<<j<<"inicio = "<<inicio<<endl;
                ll cAns = 0;
                if (i<n-1) cAns=max(cAns, maxCadDown[i+1]);
                ifd cout<<"cans = "<<cAns<<endl;
                if (i>0) cAns = max(cAns, maxCadUp[i-1]);
                ifd cout<<"cans = "<<cAns<<endl;
                if (inicio<m-1) cAns=max(cAns, maxCadDer[inicio+1]);
                ifd cout<<"cans = "<<cAns<<endl;
                if (j>0) cAns = max(cAns, maxCadIzq[j-1]);
                ifd cout<<"cans = "<<cAns<<endl;
                ifd cout<<"cAns = "<<cAns<<" + "<<(inicio-j+1)<<endl;
                ans = max ((inicio-j+1)+cAns, ans);
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}
