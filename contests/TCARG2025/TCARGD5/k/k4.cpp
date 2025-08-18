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


ll d, r;


ll search () {
    ll a=-1, b=3*1e5;
    while (b-a>1) {
        ll k= (b-a)/2+a;
        ll kk =k*k;
        ll rr=2*r*2*r;
        if (kk*rr<=d) a=k;
        else b=k;
    }

    return a;
}

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll x1, y1, x2, y2;
    cin>>r>>x1>>y1>>x2>>y2;
    ll ans=ceil(hypot(x1-x2, y1-y2)/(2*r));
    
    cout<<ans<<endl;
    return 0;
}
