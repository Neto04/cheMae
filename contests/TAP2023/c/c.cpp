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
bool rComp(ll a, ll b) {
    return a>b;
}


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;

    vector<ll> a(n), b(n);

    forn(i, n) cin>>a[i];
    forn(i, n) cin>>b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), rComp);
    vector<ll> c(n);
    forn(i, n) c[i]=a[i]+b[i];
    sort(c.begin(), c.end());
    cout<<c[n-1]-c[0]<<endl;


}
