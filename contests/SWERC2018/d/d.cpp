// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (ll i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((ll)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<ll, ll> ii;
#define dforn(i, n) for (ll i=n-1; i>=0; i--)
#define dprll(v) cout<<#v"="<<v<<endl
const ll MAXN=100100;

#define debug 0
#define ifd if (debug)
ll x, y, n;
vector<ll> maxY(1e5+5, -1);

vector<ll> minY(1e5+6, 1e8);
vector<set<ll>> puntos(1e5+5);
set<ll> xSes;


ll sign(ll k) {
    if (k>=0) return 1;
    return -1;
}


ll solve(ll oG) {
    ifd cout<<"OG = "<<oG<<endl;
    ll ans =0;
    
    for(ll u:xSes) {
        ifd cout<<"me fijo en "<<u<<""<<endl;
        
        ll y1 = maxY[u]-oG, y2 = minY[u]-oG;
        ifd cout<<"y1 = "<<y1<<", y2 = "<<y2<<endl;
        if (sign(y1)==sign(y2)) {
            ans +=max(abs(y1), abs(y2))*2;
        }
        else {
            ans +=abs(y1)*2+abs(y2)*2;
        }
        ifd cout<<"de donde ans = "<<ans<<endl;
    }

    
    return ans+x-1;
        
}



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>x>>y>>n;
    
    vector<ll> alturas;
    forn(i, n) {
        ll a, b; cin>>a>>b;
        maxY[a]=max(maxY[a], b);
        minY[a]=min(minY[a], b);
        xSes.insert(a);        
    }

    for (auto u:xSes) {
        alturas.push_back(maxY[u]);
        if (minY[u]!=maxY[u]) alturas.push_back(minY[u]);
    }
    sort(alturas.begin(), alturas.end());
    ll mid=(alturas.size())/2;
    ll x1=alturas[mid];
    ll ans1 = solve(x1);
    ll ans2=1e18;
    ll ans3=1e18;
    
    ans1=min(ans1, ans2);
    for(int i=1; i<=100; i++) {
        if (mid-i>=0) ans2=solve(alturas[mid-i]);
        if (mid+i<alturas.size()) ans3 = solve(alturas[mid+i]);
        ans1=min(ans1, min(ans2, ans3));
    }
    
    cout<<ans1<<endl;
}
