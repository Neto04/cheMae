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


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin>>t;
    while (t--) {
        ll l, r; cin>>l>>r;
        ll count = r-l+1;

        if (count == 1) {
            cout<<l<<"\n";
            continue;
        }
        if (count == 2) {
            cout<<(1+r)<<"\n";
            continue;
        }
        ll ans = count-2;
        ans += gcd(l, r);
        ans += r;
        cout<<ans<<"\n";
    }

    return 0;
}
