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

ll n, m, m2;
vector<ll> a, b;

bool check(ll y) {
    forn(i, n) {
        ll x = -1;
        if (a[i]*b[i] <= y) {
            x = 0;
        } else {
            long double xD = (long double)(a[i]*b[i]-y)/(long double)b[i];
            x = ceil(xD);
        }
        m2 -= x;
        if (m2 < 0) return false;
    }
    return true;
}

ll search() {
    ll l = -1, r = 1e18+5;
    while (r-l > 1) {
        ll y = (r-l)/2 + l;
        m2 = m;
        if (check(y)) r = y;
        else l = y;
    }
    return r;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        cin>>n>>m;
        a.resize(n), b.resize(n);
        forn(i,n) cin>>a[i];
        forn(i,n) cin>>b[i];
        ll ans = search();
        cout<<ans<<"\n";
    }

    return 0;
}
