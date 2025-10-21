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
vector<ll> pSum;
ll rSum(int l, int r) {
    ll ans  = pSum[r];
    if (l>=0) ans -=pSum[l-1];
    return ans;
}


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    freopen("fenwick.in", "r", stdin);
    freopen("fenwick.out", "w", stdout);
    int n; cin>>n;
    vector<ll> v(n+1);
    forr(i,1,n+1) cin>>v[i];
    pSum.resize(n+1, v[1]);
    for(int i=2; i<=n; i+=2) {
        // el tamagno del rango por el que responde
        ll lSOne = i&-i;
        ll x = rSum(i-(lSOne-1), i-2);
        v[i-1]=-x;
        pSum[i-1]=pSum[i-2]+v[i-1];
        pSum[i]=pSum[i-1]+v[i];
    }
    forr(i,1,n+1) cout<<v[i]<<" ";


    cout<<endl;

}
