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

    int n; cin>>n;
    string s; cin>>s;

    // cantidad de -, cantidad de +
    ll m = 0, M = 0;
    for (char c : s) {
        if (c == '-') m++;
        else M++;
    }

    int q; cin>>q;
    while (q--) {
        ll a, b; cin>>a>>b;
        // Si son iguales tiene que haber la misma cantidad de + y -
        if (a == b) {
            if (m == M) cout<<"YES\n";
            else cout<<"NO\n";
            continue;
        } 
        // Si solo hay sumas o solo hay restas nunca se llega a 0
        if (m == 0 or M == 0) {
            cout<<"NO\n";
            continue;
        }
        // Si k no es entero no se puede
        if ((b*abs(m-M) )% abs(a-b)) {
            cout<<"NO\n";
            continue;
        }
        ll k = (b*(m-M))/(a-b);
        if (k >= 0) {
            if (k <= M) cout<<"YES\n";
            else cout<<"NO\n";
        } else {
            if (abs(k) <= m) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }

    return 0;
}
