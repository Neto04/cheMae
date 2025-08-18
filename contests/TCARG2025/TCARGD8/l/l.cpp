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

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int tC; cin>>tC;
    while (tC--) {
        // n # baterias, m # estaciones
        int n, m;
        cin>>n>>m;
        // me dice capacidad de la i-ésima batería
        vector<ll> capacBat(n+1);
        // me dice en qué pos está la i-ésima estación
        vector<ll> estaPos(m);
        // me dice qué batería tiene la i-ésima estación
        vector<ll> estaBat(m);
        forn(i, n) cin>>capacBat[i+1];
        forn(i,m) cin>>estaPos[i]>>estaBat[i];
        
        
        // me dice ahorita mismo cuanto tiene cada bat
        vector<ll> currCapacBat(n+1); currCapacBat=capacBat;
        int currBatIndx=0;
        ll currPos=0;
        bool rip =false;
        forn(i, m) {

        }



    }

}
