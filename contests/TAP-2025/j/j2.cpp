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
const ll INF = 1e18;

#define debug 1
#define ifd if (debug)


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string resp="SN";


    int t; cin>>t;
    vector<vector<ll>> v1(t), v2(t);
    vector<ll> gente1, gente2;
    bool error =false;
    ll minV=INF;
    forn(i, t) {
        ll last = INF;
        int n; cin>>n;
        v1[i].resize(n);
        forn(j, n) {
            cin>>v1[i][j];
            if (v1[i][j]>last) error=true;
            minV=min(minV, v1[i][j]);
            last=v1[i][j];
            gente1.push_back(v1[i][j]);
        }
    }
    sort(gente1.begin(), gente1.end());

    forn(i, t) {
        ll last = INF;
        int n; cin>>n;
        v2[i].resize(n);
        forn(j, n) {
            cin>>v2[i][j];
            if (v2[i][j]>last) error=true;
            minV=min(minV, v2[i][j]);
            last=v2[i][j];
            gente2.push_back(v2[i][j]);
        }
    }
    sort(gente2.begin(), gente2.end());
    // si tienen distinta cantidad de bloques en total, RIP
    if (gente1.size()!=gente2.size()) error=true;
    // si uno tiene un bloque que el otro no, RIP
    for(int i=0; i<gente1.size() and ! error; i++) if (gente1[i]!=gente2[i]) error=true;
    // si c/u tiene solo una torre, tienen los mismos bloques y esas torres cumplen, todo bien
    if (t==1) cout<<resp[error]<<endl;
    // si tienen dos torres
    if (t==2) {
        // si aún no ha salido nada mal (cumplen lo del tamaño y se usan los mismos bloques)
        if (!error) {
            
            // PRUEBA1: revise si los dos pueden ser equivalentes 
            // prueba1 guarda si pasan la prueba 1
            bool prueba1=true;
            vector<int> total1, total2;

            forn(i, t) {
                total1.clear();
                total2.clear();
                for(int u:v1[i]) total1.push_back(u);
                for(int u:v2[i]) total2.push_back(u);
                if (total1.size()!=total2.size()) prueba1=false;
                else for(int j=0; j<total1.size(); j++) if (total1[j]!=total2[j]) prueba1=false;
            }
            

            // PRUEBA2: si pasó una cantidad de las ocurrencias del min elemento de ambas columnas
            bool prueba2=true;
            forn(i, t) {
                total1.clear();
                total2.clear();
                for(int u:v1[i]) if (u!=minV) total1.push_back(u);
                for(int u:v2[i]) if (u!=minV) total2.push_back(u);
                // no debería de pasar, pero por aquello de que los sizes difieran
                if (total1.size() !=total2.size()) prueba2=false;
                // revise si las dos torres son equivalentes, sino RIP prueba2
                else for(int j=0; j<total1.size(); j++) if (total1[j]!=total2[j]) prueba2=false;
            }
    
            error = !(prueba1 or prueba2);
        }

        cout<<resp[error]<<endl;
    }


    if (t>=3) cout<<resp[error]<<endl;
    



}
