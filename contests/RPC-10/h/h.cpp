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

    ll a, b, c; 
    ll s1 = 0, s2 = 0;

    cin>>a>>b>>c;
    s1 += a;
    s1 += (2*b);
    s1 += (3*c);

    cin>>a>>b>>c;
    s2 += a;
    s2 += (2*b);
    s2 += (3*c);

    if (s1 > s2) {
        cout<<1<<endl;
    } else if (s1 == s2) {
        cout<<0<<endl;
    } else {
        cout<<2<<endl;
    }

    return 0;
}
