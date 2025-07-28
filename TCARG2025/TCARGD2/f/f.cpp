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

vector<ll> pSumH;

int n, nCeros, nUnos;
// usted quiere saber si puede tener cada cero de len x y cada uno de len (n-x)/numUnos
bool sirve(int x0) {
    int sCeros=nCeros*x0;
    int sUnos=(n-sCeros)/nUnos;
    //return (sCeros*nCeros+sUnos*nUnos)==n;
    return (sUnos>0&&(((n - sCeros) % nUnos) == 0))&&((sCeros+sUnos*nUnos)==n);
}

vector<ll> hashI={-1, -1}; 

vector<ll> pot;
// hashea la vara de [l, r]
void pHashee() {
    ll res=0;
    for(int i=0; i<n; i++) {
        res=(res*31+(t[i]-'a'+1))%MOD;
        pSumH[i]=res;
    }
    
}


void prePotee() {
    pot[0]=1;
    forr(i, 1, n+1) pot[i]=(pot[i-1]*31)%MOD;
}

// hashee la vara de l a r
ll hashQ(int l, int r) {
    ll restar;
    if (l==0) restar=0;
    else restar = (pSumH[l-1]*(pot[r-l+1]))%MOD;
    return ((pSumH[r]-restar)%MOD+MOD)%MOD;
}

// recorra con tamagno de los ceros y el tamagno de los unos
bool recorra2(int tamano0, int tamano1) {
    bool error=false;
    // vaya agarrando grupos 
    // siguiente = siguiente inicio de bloque
    int siguiente = 0;

    for(int i=0; i<s.size()&&!error; i++) {
        if (s[i]=='0') {
            if (siguiente + tamano0-1 >= t.size()) {
                error= true;
                continue;
            }
            ll x = hashQ(siguiente, siguiente+tamano0-1);
            if (hashI[0] == -1) hashI[0] = x;
            if (hashI[0]!=-1) error = (x!=hashI[0]);
            siguiente += tamano0;
        } else {
            if (siguiente + tamano1-1>= t.size()){
                error=true;
                continue;
            }
            ll x = hashQ(siguiente, siguiente+tamano1-1);
            if (hashI[1] == -1) hashI[1] = x;
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
    pot.resize(n+1);
    pSumH.resize(n+1);
    
    pHashee();
    prePotee();

    for(int t0=1; t0<=n; t0++) {
        
        hashI[0]=-1; hashI[1]=-1;
        ifd cout<<"reviso si "<<t0<<" sirve"<<endl;
        if (!sirve(t0)) continue;
        int t1=((n-t0*nCeros)/nUnos);
        
        if(recorra2(t0, t1)) ans+=(hashI[0]!=hashI[1]);
    }

    cout<<ans<<endl;
    return 0;
}
