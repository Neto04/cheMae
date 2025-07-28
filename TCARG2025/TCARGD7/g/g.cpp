// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (ll i=a; i<b; i++)
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
    ll n; cin>>n;
    vector<ll> v(n);
    forn(i, n) cin>>v[i];
    vector<ll> v2=v;
    sort(v2.begin(), v2.end());
    ll minV=v2[0], maxV=v2[n-1];
    ll firstMax=1e9, lastMin=-1;
    forn(i, n) {
        if (v[i]==maxV) firstMax=min(firstMax, i);
        if (v[i]==minV) lastMin=max(lastMin, i);
    }
    ll ans1=minV, ans2=maxV*n;
    for(int i=0; i<lastMin; i++) ans1+=v[i]*(i+1+1);
    for(int i=lastMin+1; i<n; i++) ans1+=v[i]*(i+1);

    for(int i=0; i<firstMax; i++) ans2+=v[i]*(i+1);
    for(int i=firstMax+1; i<n; i++) ans2+=v[i]*(i);
    cout<<max(ans1, ans2)<<endl;

    return 0;
}
