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
const int MAXN=3*1e4+1;

#define debug 0
#define ifd if (debug)
const ll MOD = 1e9+7;
vector<ll> F(MAXN), I(MAXN);

ll binom (ll n, ll k) {
    return F[n]*I[k]%MOD*I[n-k]%MOD;
}
ll exp(ll base, ll exp) {
    ll r=1;
    while (exp) {
        if (exp%2) r=r*base%MOD;
        base=base*base%MOD;
        exp/=2;
    }
    return r;
}


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    F[0] = 1;
    for(int i=1; i<MAXN; i++) {
        F[i]=(F[i-1]*i)%MOD;
    }

    I[MAXN-1] = exp(F[MAXN-1], MOD-2);
    for(ll i=MAXN-2; i>=0; i--) {
        I[i]=I[i+1]*(i+1)%MOD;
    }

    int tC; cin>>tC;
    while (tC--) {
        int n; cin>>n;

        // primero pre-calcule freq y guarde 
        vector<int> v(n);
        set<int> s;
        vector<int> freq(MAXN);
        forn(i, n) {
            cin>>v[i];
            freq[v[i]]++;
            s.insert(v[i]);
        }
        vector<int> pSum(MAXN);
        forr(i,1, MAXN) pSum[i] = (pSum[i-1] + freq[i])%MOD;

        ll ans =0;

        for(int i=1; i<MAXN; i++) {
            if (!freq[i]) continue;
            int b = pSum[i-1];
            int a = n-pSum[i];
            ans =((ans + binom(a+b, a))%MOD+MOD)%MOD;
            for(int j = 1; j<freq[i]; j++) {
                ans =(((ans + binom(a+b+j, a) +binom(a+b+j, a+j) - binom(a+b+j-1,b) - binom(a+b+j-1, a))%MOD)+MOD)%MOD;
            }

            // if (a==0&&b==0) ans = 1;
        }
        cout<<((ans%MOD)+MOD)%MOD<<"\n";
    }
}
