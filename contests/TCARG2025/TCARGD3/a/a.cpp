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

vector<ll> pos;
vector<ll> pot;
// empieza a quitar en i

bitset<100005> seen;
vector<ll> dp(1e5+5);
int n;
// busca el max con pos <x
ll bS (ll x){
    // l siempre cumple
    ll l=-1, r=n;
    while (r-l>1) {
        ll c=(r-l)/2+l;
        if (pos[c]<x) l=c;
        else r=c;

    }
    return l;
}

// cuanta gente queda viva si usted a partir de i decide activarlo todo
ll solve (ll i) {
    if (i==0) return 1;
    if (seen[i]) return dp[i];
    seen[i]=true;

    ll&ans =dp[i];
    ll i2=bS(pos[i]-pot[i]);
    if (i2==-1) ans=1;
    else ans=1+solve(i2);
    return ans;
    
}



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n;
    vector<ii> v(n);
    forn(i,n) cin>>v[i].first>>v[i].second;
    sort(v.begin(), v.end());
    pos.resize(n);
    pot.resize(n);
    forn(i, n) {
        pos[i]= v[i].first; 
        pot[i]= v[i].second;
    }
    ll best=-1;
    for(int i=n-1; i>=0; i--) {
        ll bi=solve(i);
        ifd cout<<"vea que solve de "<<i<<" = "<<bi<<endl;
        best=max(best, bi);
    }
    cout<<n-best<<endl;



}
