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

ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}




int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    ll xOg; cin>>xOg;
    ll xx=xOg;
    // contiene todos los primos <=1e6 que dividen a x
    vector<ll> divP;
    for(ll i =2; i<=1e6 and xx!=1; i++) {
        if (xx%i) continue;
        divP.push_back(i);
        while (xx%i==0) xx/=i;
    }
   
    forn(i, n) {
        ll bestAns=1e18;
        ll x = xOg;
        ll y, yOg; cin>>y; yOg=y;
        ll mcd=gcd(x, y);
        x/=mcd; y/=mcd;
        if (x==1) {
            cout<<"-1\n";
            continue;
        }
        if (divP.empty()) {
            cout<<x<<'\n';
            continue;
        }
        for(ll& u : divP) {    
            if (x % u ) continue;
            ll ans = u;
            while (xOg%ans == 0 and (yOg%ans == 0)) {
                ans *= u;
            }    
            bestAns=min(bestAns, ans);
        }

        cout<<bestAns<<"\n";
    }








}
