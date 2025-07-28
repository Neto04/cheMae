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

ll raizQ(ll a) {
    long long x = sqrt(a) + 2;
    while (x * x > a) x--;

    return x;
}

ll q;
void factors( vector<ll>&ans) {
    ll qq=q;
    for (int x = 2; x*x <= qq; x++) {
        while (qq%x == 0) {
            ans.push_back(x);
            qq/= x;
        }
    }
    if (qq > 1) ans.push_back(qq);
    
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int tC; cin>>tC;
    while (tC--) {
        ll p; cin>>p>>q;
        vector<ll> div;
        factors(div);
        ll ans =1;
        
        for (ll x:div) {
            ifd cout<<"me fijo en "<<x<<endl;
            ll pp=p;
            while (pp%q==0) pp/=x;
            ans = max(ans, pp);
        }
        
        cout<<ans<<"\n";
    }
}
