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
ll techo(ll x) {
    return (x/3+(x%3!=0));
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, disp;
    cin>>n>>disp;
    vector<ll> v(n); forn(i, n) cin>>v[i];
    sort(v.begin(), v.end());
    ll taken=0;
    // gaste el primer y ultimo socket poniendo los dos mas grandes
    while (v.size()>0 and taken<2 and disp>0){
        v.pop_back();
        taken++;
        disp--;
    }
    ifd cout<<"disp = "<<disp<<endl;
    n=v.size();
    // cSize es cuantos sockets me gasta cada mae ahorita
    ll cSize=1;
    vector<ll> nG(3);
    vector<ll> sob(3);
    // OJO: no estoy seguro de si a usted le importa lo de disp<cSize
    for (ll indx=0; indx<n; indx++) {
        ifd cout<<"viendo "<<v[indx]<<endl;
        ll cong = (v[indx]%3);
        ifd cout<<"cong = "<<cong<<endl;
        // si tiene que update cSize, update cSize
        if (techo(v[indx])!=cSize) {
            while (disp<cSize and sob[1]>=2) {
                sob[1]-=2;
                disp++;
            }
            
            // usted de fijo solo tiene gente que no podía emparejar con nadie sobrante antes
            // intente comerse los unos primero
            while (nG[1]) {
                // vea a ver si se puede comer el uno
                nG[1]--;
                if (disp>=cSize) {
                    disp-=cSize; 
                    taken++;
                }
                else break;
                // revise si hay un dos con el que emparejarlo, y si se puede comer a ese dos
                if (disp>=cSize-1 and nG[2]) {
                    nG[2]--;
                    disp-=cSize-1;
                    taken++;
                }
                else sob[1]++;
            }
            while (nG[2]and disp>=cSize) {
                nG[2]--;
                disp-=cSize;
                taken++;
                sob[2]++;
            }

            while (nG[0]and disp>=cSize) {
                nG[0]--;
                disp-=cSize;
                taken++;
                sob[0]++;
            }
            cSize=techo(v[indx]);
        }
        ifd cout<<"cSize = "<<cSize<<", disp = "<<disp<<endl;
        // // vea a ver si siquiera puede combinarlo con alguien
        // if (disp<cSize-1) break;
        // si puede mezclarlo con algun sobrante, metalo con algun sobrante
        if (cong==2 and sob[1]) {
            ifd cout<<"opa, puedo mezclarlo con alguien de sobra "<<1<<endl;
            sob[1]--;
            disp-=(cSize-1);
            taken++;
            continue;
        }
        if (cong==1 and sob[2]) {
            ifd cout<<"opa, puedo mezclarlo con alguien de sobra "<<2<<endl;
            sob[2]--;
            disp-=(cSize-1);
            taken++;
            continue;
        }
        ifd cout<<"no hay sobrantes que me sirvan"<<endl;
        // si no puede mezclarlo con ningun sobrante
        // si ni siquiera puede comerse a este mae, rip
        nG[cong]++;
    }
    // POR AQUELLO DEL ULTIMO GRUPO
    while (nG[1] and disp>=cSize) {
        // vea a ver si se puede comer el uno
        nG[1]--;
        if (disp>=cSize) {
            disp-=cSize; 
            taken++;
        }
        else break;
        // revise si hay un dos con el que emparejarlo, y si se puede comer a ese dos
        if (disp>=cSize-1 and nG[2]) {
            nG[2]--;
            disp-=cSize-1;
            taken++;
        }
        else sob[1]++;
    }
    while (nG[2]and disp>=cSize) {
        nG[2]--;
        disp-=cSize;
        taken++;
        sob[2]++;
    }

    while (nG[0]and disp>=cSize) {
        nG[0]--;
        disp-=cSize;
        taken++;
        sob[0]++;
    }
    cout<<taken<<endl;
}
