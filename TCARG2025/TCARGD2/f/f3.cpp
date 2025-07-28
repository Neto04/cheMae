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
#define debug 1
#define ifd if (debug)
// s el de unos y ceros, t el de letras
string s, t;
// n el número de caracteres que hay en t
vector<int> hashI{-1, -1};

#define bint __int128
struct Hash {
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	vector<bint> h,pi;
	Hash(string& ss){
		assert((P*PI)%MOD==1);
		h.resize(ss.size()+1);pi.resize(ss.size()+1);
		h[0]=0;pi[0]=1;
		bint p=1;
		forr(i,1,ss.size()+1){
			h[i]=(h[i-1]+p*ss[i-1])%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
		}
	}
	ll get(int ss, int e){
		return (((h[e]-h[ss]+MOD)%MOD)*pi[ss])%MOD;
	}
};

int n, nCeros, nUnos;
// usted quiere saber si puede tener cada cero de len x y cada uno de len (n-x)/numUnos
bool sirve(int x0) {
    int sCeros=nCeros*x0;
    int sUnos=(n-sCeros)/nUnos;
    //return (sCeros*nCeros+sUnos*nUnos)==n;
    return ((sUnos!=0)&&(((n - sCeros) % nUnos) == 0))&&((sCeros+sUnos*nUnos)==n);
}

// recorra con tamagno de los ceros y el tamagno de los unos
bool recorra2(int tamano0, int tamano1, Hash& hsh) {
    bool error=false;
    // vaya agarrando grupos 
    // siguiente = siguiente inicio de bloque
    int siguiente =0;

    for(int i=0; i<s.size()&&!error; i++) {
        if (s[i]=='0') {
            if (siguiente + tamano0-1 > t.size()) {
                error= true;
                ifd cout<<"1."<<endl;
                continue;
            }
            ll x = hsh.get(siguiente, siguiente+tamano0-1);

            if (hashI[0] == -1) hashI[0] = x;
            if (hashI[0]!=-1) error = (x!=hashI[0]);
            siguiente += tamano0;
        } else {
            if (siguiente + tamano1-1> t.size()){
                error=true;
                continue;
            }
            ll x = hsh.get(siguiente, siguiente+tamano1);
            if (hashI[1] == -1) hashI[1] = x;
            else error = (x!=hashI[1]);
            siguiente += tamano1;
        }
    }

    error =(error||(hashI[0]==hashI[1]));
    return !error;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>s>>t;
    Hash hsh(t);
    ll ans =0;
    for(char c:s) {
        if (c=='0') nCeros++;
        else nUnos++;
    }
    n=t.size();
    for(int t0=1; t0<n; t0++) {
        hashI[0]=-1; hashI[1]=-1;
        if (!sirve(t0)) continue;
        ifd cout<<t0<<" sirve"<<endl;
        int t1=((n-t0*nCeros)/nUnos);
        
        if(recorra2(t0, t1, hsh)) {
            ifd cout<<"el recorrido de "<<t0<<" cumple"<<endl;
            ans++;
        }
    }

    cout<<ans<<endl;
}

