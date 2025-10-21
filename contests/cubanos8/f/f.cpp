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

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int tC; cin>>tC;
    while (tC--){
        int n; cin>>n;
        
        vector<ll> v(n);
        forn(i,n) cin>>v[i];
        sort(v.begin(), v.end());
        vector<ll> pAnd(n, v[0]), sAnd(n, v[n-1]);
        for(int i=1; i<n; i++) pAnd[i]=(pAnd[i-1]&v[i]);
        for(int i=n-2; i>=0; i--) sAnd[i]=(sAnd[i+1]&v[i]);
        ll bestAns=0;
        
        forn(i, n) {
            ll izq = (1LL<<32)-1;
            ifd cout<<izq<<endl;
            ll der = izq;
            if(i>0) izq = pAnd[i-1];
            if (i<n-1) der = sAnd[i+1];
            bestAns=max(bestAns, abs(v[i]-(der&izq)));
        }
        cout<<bestAns<<endl;
        
    }


}
