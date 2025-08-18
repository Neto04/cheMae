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
const ll MOD =1e9+7;
#define debug 0
#define ifd if (debug)
// s el de unos y ceros, t el de letras
string s, t;
// n el número de caracteres que hay en t
int n, nCeros, nUnos;
// usted quiere saber si puede tener cada cero de len sCero y cada uno de len (n-sCero*nCeros)/numUnos
bool sirve(int sCeros) {
    
    int sUnos=(n-sCeros*nCeros)/nUnos;
    // ifd cout<<"revisando "<<x0<<", sCeros = "<<x0<<", y sUnos = "<<sUnos<<endl;;
    //return (sCeros*nCeros+sUnos*nUnos)==n;
    return (((n - sCeros*nCeros) % nUnos) == 0)&&((sCeros+sUnos*nUnos)==n);
}

// guarda en (x, y) una solucion entera de la ecuación
// retorna gcd de a, b
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

vector<ll> hashI={-1, -1}; 

// hashea la vara de [l, r]
ll hashee(int l, int r) {
    ll res=0;
    for(int i=l; i<=r; i++) res=(res*31+(t[i]-'a'+1))%MOD;
    ifd cout<<"HASH DE "<<l<<" A "<<r<<" = "<<res<<endl;
    return res;
}

// recorra con tamagno de los ceros y el tamagno de los unos
bool recorra2(int tamano0, int tamano1) {
    ifd cout<<"recorro dejando "<<tamano0<<" para los ceros, y "<<tamano1<<" para los unos"<<endl;
    bool error=false;
    // vaya agarrando grupos 
    // siguiente = siguiente inicio de bloque
    int siguiente = 0;

    for(int i=0; i<s.size()&&!error; i++) {
        ifd cout<<"voy por el digito "<<i<<"del de unos y ceros"<<endl;
        ifd cout<<"vea que voy por el "<<siguiente<<" del de palabras"<<endl;
        if (s[i]=='0') {
            ifd cout<<"eso es un cero!"<<endl;
            if (siguiente + tamano0-1 >= t.size()) {
                error= true;
                continue;
            }
            ll x = hashee(siguiente, siguiente+tamano0-1);
            ifd cout<<"el hash desde "<<siguiente<<" hasta "<< siguiente+tamano0-1<<" me da "<<x<<endl;
            if (hashI[0] == -1) hashI[0] = x;
            ifd cout<<"el hash de cero debería de dar "<<hashI[0]<<endl;
            if (hashI[0]!=-1) error = (x!=hashI[0]);
            ifd if (error) cout<<"ERROR"<<endl;
            siguiente += tamano0;
        } else {
            ifd cout<<"eso es un uno!"<<endl;
            if (siguiente + tamano1-1>= t.size()){
                ifd cout<<"opa, vea que eso +tamano1="<<tamano1<<"es mayor a la palabra"<<endl;
                error=true;
                continue;
            }
            ll x = hashee(siguiente, siguiente+tamano1-1);
            ifd cout<<"el hash desde "<<siguiente<<" hasta "<< siguiente+tamano1-1<<" me da "<<x<<endl;
            if (hashI[1] == -1) hashI[1] = x;
            ifd cout<<"el hash de uno debería de dar "<<hashI[1]<<endl;
            else error = (x!=hashI[1]);
            siguiente += tamano1;
        }
    }
    return !error;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll ans =0;
    cin>>s>>t;
    for(char c:s) {
        if (c=='0') nCeros++;
        else nUnos++;
    }
    n=t.size();
    for(int t0=1; t0<=n; t0++) {
        if (gcd())

        ifd cout<<"holi"<<endl;
        hashI[0]=-1; hashI[1]=-1;
        ifd cout<<"reviso si "<<t0<<" sirve"<<endl;
        if (!sirve(t0)) continue;
        int t1=((n-t0*nCeros)/nUnos);
        if (!t1&&nUnos) continue;
        if(recorra2(t0, t1)) ans+=(hashI[0]!=hashI[1]);
    }

    cout<<ans<<endl;
    return 0;
}
