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

        if (puntos[a].find(b) == puntos[a].end()) {
            
            puntos[a].insert(b);
        }
        
    }

    for (auto u:xSes) {
        alturas.push_back(maxY[u]);
        alturas.push_back(minY[u]);
    }
    sort(alturas.begin(), alturas.end());
    

    ll x1=alturas[(alturas.size())/2];
    ifd cout<<"x1 = "<<x1<<endl;
    ll ans1 = solve(x1), ans2=1e18;
    if ((alturas.size()%2)==0) {
        ll x2 = alturas[((alturas.size())/2)-1];
        ifd cout<<"x2 = "<<x2<<endl;
        ans2=solve(x2);
    }
    cout<<min(ans1, ans2)<<endl;
}
