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
    int n; cin>>n;
    vector<int> v(n);
    vector<int> p(n+1);
    forn(i, n)  {
        cin>>v[i];
        p[v[i]]=i;
    }
    ll ans =n;
    map<ll, int> freq;
    forr(i, 1, n+1) {
        ll x1=p[i]+i;
        ans +=2*freq[x1];
        ll x2 = p[i]+i-n;
        ans+=2*freq[x2];
        freq[x1]++;
    }
    cout<<ans<<endl;

}
