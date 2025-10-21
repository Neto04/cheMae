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

const ll INF = 5e18;
vector<ll> a(4), b(4);

// (a1+a2+a3)*max(b1,b2,b3)
ll f1 (ll a1, ll a2, ll a3, ll b1, ll b2, ll b3) {
    return ((a1+a2+a3)*max(max(b1,b2),b3));
}

// (max(a1,a2)+a3)*max(b1+b2,b3)
ll f2 (ll a1, ll a2, ll a3, ll b1, ll b2, ll b3) {
    ll ans = INF;
    /*
        Rotar de la forma
        1 2 3
        3 1 2
        2 3 1
    */
   ans = min(ans, (max(a1,a2)+a3)*max(b1+b2,b3));
   ans = min(ans, (max(a3,a1)+a2)*max(b3+b1,b2));
   ans = min(ans, (max(a2,a3)+a1)*max(b2+b3,b1));
   return ans;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        ll ans = INF;
        for (int i = 1; i <= 3; i++) {
            cin>>a[i]>>b[i];
        }

        // Tipo 1
        ans = min(ans, f1(a[1],a[2],a[3], b[1],b[2],b[3]));  // Los tres normales

        ans = min(ans, f1(a[1],a[2],b[3], b[1],b[2],a[3]));  // Rotado 3
        ans = min(ans, f1(a[1],b[2],a[3], b[1],a[2],b[3]));  // Rotado 2
        ans = min(ans, f1(b[1],a[2],a[3], a[1],b[2],b[3]));  // Rotado 1

        ans = min(ans, f1(a[1],b[2],b[3], b[1],a[2],a[3]));  // Rotados 2 y 3
        ans = min(ans, f1(b[1],a[2],b[3], a[1],b[2],a[3]));  // Rotados 1 y 3
        ans = min(ans, f1(b[1],b[2],a[3], a[1],a[2],b[3]));  // Rotados 1 y 2

        ans = min(ans, f1(b[1],b[2],b[3], a[1],a[2],a[3]));  // Los tres rotados

        // Tipo 2
        ans = min(ans, f2(a[1],a[2],a[3], b[1],b[2],b[3]));  // Normales

        ans = min(ans, f2(a[1],a[2],b[3], b[1],b[2],a[3]));  // Rotado 3
        ans = min(ans, f2(a[1],b[2],a[3], b[1],a[2],b[3]));  // Rotado 2
        ans = min(ans, f2(b[1],a[2],a[3], a[1],b[2],b[3]));  // Rotado 1

        ans = min(ans, f2(a[1],b[2],b[3], b[1],a[2],a[3]));  // Rotados 2 y 3
        ans = min(ans, f2(b[1],a[2],b[3], a[1],b[2],a[3]));  // Rotados 1 y 3
        ans = min(ans, f2(b[1],b[2],a[3], a[1],a[2],b[3]));  // Rotados 1 y 2

        ans = min(ans, f2(b[1],b[2],b[3], a[1],a[2],a[3]));  // Los tres rotados

        cout<<ans<<"\n";
    }

    return 0;
}
