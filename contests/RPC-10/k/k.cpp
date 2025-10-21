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

    cout<<setprecision(6)<<fixed;
    int n; cin>>n;
    vector<ll> v(n+1); 
    for (int i = 1; i <= n; i++) cin>>v[i];
    sort(v.begin(), v.end());

    vector<ll> p(n+1);
    p[0] = 0LL;
    for (int i = 1; i <= n; i++) p[i] = v[i] + p[i-1];

    double ans = 0.0;
    for (int i = 0; i <= n; i++) {
        double x, y;
        x = (double)(n-i)/(double)n;
        y = (double)(p[n]-p[i])/(double)p[n];  
        ans = max(ans, y-x);
    }

    ans *= 100.0;
    cout<<ans<<"\n";

    return 0;
}
