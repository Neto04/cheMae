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
#define debug 0
#define ifd if (debug)
const int MAX=1e6+5;




const int MOD =998244353;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll rand64() {
	// vea que puede tener 250000 números, cuya suma puede darle A LO SUMO 1e18
  return uniform_int_distribution<int64_t>(0, 4000000000000)(rng);
}
// freq[i][j] me dice la freq de la letra i en S[0,...j]
vector<vector<int>> freqS(26);

// me dice la freq de la letra i en el rango [l, r]
int freqRng(int i, int l, int r) {
    int ans = freqS[i][r];
    if (l>0) ans-=freqS[i][l-1];
    return ans;
}



vector<ll> f(1e6+5);
vector<ll> I(1e6+5);
ll exp(ll base, ll exp) {
    ll r=1;
    while (exp) {
        if (exp%2) r=r*base%MOD;
        base=base*base%MOD;
        exp/=2;
    }
    return r;
}
ll choose (int a, int b) {
    if (b==0) return 1;
    if (a<b) return 0;
    return (((f[a]*I[b])%MOD)*I[a-b])%MOD;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    f[0]=1;
    forr(i, 1, MAX) f[i]=(f[i-1]*i)%MOD;
    I[MAX-1] = exp(f[MAX-1], MOD-2);
    for(ll i=MAX-1; i>0; i--) I[i-1]=(I[i]*i)%MOD;

    vector<ll> val(26);
    forn(i,26) val[i]=rand64();


    int tC; cin>>tC;
    while (tC--) {
        string s; cin>>s;
        // construya la vara de freq de S
        forn(i, 26) {
            freqS[i].clear();
            freqS[i].resize(s.size());
        }
        freqS[s[0]-'a'][0] =1;
        for(int j=1; j<s.size(); j++) 
            for (int i=0; i<26; i++) {
                freqS[i][j]= freqS[i][j-1] + (s[j]-'a'==i);
            }
        
        
        int q; cin>>q;
        while (q--) {
            string op; cin>>op;
            if (op=="INSIDE") {
                int l, r; cin>>l>>r; l--, r--;
                string w; cin>>w;
                // cree freqW
                vector<vector<int>>freqW(26, vector<int>(w.size()));
                freqW[w[0]-'a'][0] =1;
                for(int j=1; j<w.size(); j++) for (int i=0; i<26; i++) freqW[i][j]= freqW[i][j-1] + (w[j]-'a'==i);

                bool ans =1;
                forn(i, 26) 
                    ans = ans and (freqRng(i, l, r) == freqW[i][w.size()-1]);
                if (ans) cout<<"YES\n";
                else cout<<"NO\n";
            }


            else {
                int l, r; cin>>l>>r; l--, r--;
                int nn = r-l+1;
                ll ans = 1;
                ifd cout<<"ans = "<<ans<<endl;
                forn(i, 26) {
                    ll ci = freqRng(i, l, r);
                    ifd cout<<"freq de "<<i<<" en "<<l<<", "<<r<<" = "<<ci<<endl;
                    ifd cout<<"ahorita n = "<<nn<<" y ci = "<<ci<<endl;
                    ans = (ans*choose(nn, ci))%MOD;
                    nn-=ci;
                    ifd cout<<"ans ahorita = "<<ans<<endl;
                }
                cout<<ans<<"\n";
            }
 


        }



        



        




    }






}

