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

const int N = 1e5+5;
int n;
vector<ll> c(N), p(N);

bool check(ll m) {
    ll acumulados = p[1];
    for (int i = 1; i <= n; i++) {
        if (c[i]*m > acumulados) {
            return false;
        };
        acumulados -= (c[i]*m);
        acumulados += p[i+1];
    }
    return true;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for (int i = 1; i <= n; i++) cin>>c[i];
    for (int i = 1; i <= n; i++) cin>>p[i];

    ll l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        ll m = l+(r-l)/2;
        if (check(m)) {
            l = m+1; ans = m;
        } else {
            r = m-1;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
