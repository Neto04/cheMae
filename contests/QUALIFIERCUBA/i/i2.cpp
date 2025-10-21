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

const ll MOD = 998244353;

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

    int tC; cin>>tC;
    while (tC--) {
        ll n; ll k; cin>>n>>k;
        vector<ll> a(n);
        for (ll& x : a) cin>>x;

        sort(a.begin(), a.end());
        vector<ll> diff(n-1);
        forn(i,n-1) diff[i] = a[i+1]-a[i];

        ll f = -1;
        forn(i,n-1) {
            if (k >= diff[i] * (i+1)) k -= (diff[i] * (i+1));
            else {
                f = i;  // Ya no puedo alcanzar al i+1-esimo mae (diff[i] = a[i+1]-a[i])
                break;
            }
        }

        // Si f es -1 entonces pude igualar a todos al ultimo mae
        if (f == -1) {
            forn(i,n) a[i] = a[n-1] + k/n;
            forn(i, k % n) a[i]++;
        } else { // Si no, igualo todos al mae f
            forn(i,f+1) a[i] = a[f] + k/(f+1);
            forn(i, k % (f+1)) a[i]++;
        }

        ll ans = 0;
        forn(i,n) {
            ans += exp(a[i], MOD-2);
            ans %= MOD;
        }
        ans *= exp(n, MOD-2);
        ans %= MOD;
        cout<<ans<<"\n";
    }
}
