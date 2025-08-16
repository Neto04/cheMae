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
typedef pair<ll, ll> ii;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);


    int n; cin>>n;
    vector<ll> mcH(n), mcV(n);
    vector<ii> v(n*n);

    ll ans=0;
    forn(i,n) 
        forn(j, n) {
            int x; cin>>x;
            v[x-1]={i, j};
        }
    
    forn(x, n*n) {
        int i, j; tie(i,j) = v[x];

        ll cH =mcH[i];
        ll cV = mcV[j];

        mcH[i]=max(mcH[i], cV+1);
        mcV[j]=max(mcV[j], cH+1);
        ans = max(ans, max(mcH[i], mcV[j]));
    }

    cout<<ans<<endl;


}
