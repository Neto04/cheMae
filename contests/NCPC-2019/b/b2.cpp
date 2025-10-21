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

const ll INF = 5*1e18;

// (a1+a2+a3)*max(b1,b2,b3)
ll f1 (ll a1, ll a2, ll a3, ll b1, ll b2, ll b3) {
    ifd cout<<"pruebo: base =("<<a1<<", "<<b1<<"), arriba = ("<<a2<<", "<<b2<<"), ("<<a3<<", "<<b3<<")"<<endl;
    ll x = a1+a2+a3;
    ll y = max(max(b1, b2), b3);
    ifd cout<<"f1 = "<<x*y<<endl;
    return x*y;
}

// (max(a1,a2)+a3)*max(b1+b2,b3)
ll f2 (ll a1, ll a2, ll a3, ll b1, ll b2, ll b3) {
    ll x = max(a1, a2+a3);
    ll y = b1+max(b2, b3);
    ifd cout<<"f2 = "<<x*y<<endl;
    return x*y;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        ll ans = INF;
        vector<pair<ll,ll>> v;
        forn(i,3) {
            ll a, b; cin>>a>>b;
            v.push_back({a,b});
        }
        sort(v.begin(), v.end());
        do {
            ll a[2] = {v[0].first, v[0].second};
            ll b[2] = {v[1].first, v[1].second};
            ll c[2] = {v[2].first, v[2].second};
            forn(i,2) forn(j,2) forn(k,2) {
                ans = min(ans, f1(a[i], b[j], c[k], a[(i+1)%2], b[(j+1)%2], c[(k+1)%2]));
                ans = min(ans, f2(a[i], b[j], c[k], a[(i+1)%2], b[(j+1)%2], c[(k+1)%2]));
            }
        } while (next_permutation(v.begin(), v.end()));

        cout<<ans<<"\n";
    }

    return 0;
}
