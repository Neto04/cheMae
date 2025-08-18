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


vector<ll> v; int n;

// l max que cumple, r min que no
ll search(ll x) {
    ll l=-1, r=n;
    while (r-l>1) {
        ll c=(r-l)/2+l;
        if (v[c]<=x) l=c;
        else r=c;
    }
    return l;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    v.resize(n);
    forn(i,n) cin>>v[i];
    sort(v.begin(), v.end());

    int q; cin>>q;
    while (q--) {
        int m; cin>>m;
        
        cout<<search(m)+1<<"\n";
    }

    return 0;
}
