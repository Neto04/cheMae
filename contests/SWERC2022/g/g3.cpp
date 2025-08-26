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
int n;
vector<int> v;

// me tira cuál es el máx # de 1s conseutivos
ll unosWind () {
    ll ans=0, cSum=0;

    for(int i=0; i<n; i++) cSum+=v[i];
    ans=cSum;
    for(int i1=0, i2=n; i2<2*n-1; i1++, i2++) {
        cSum=cSum+v[i2]-v[i1];
        ans=max(ans, cSum);
    }
    return ans;
    
}






int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n;

    
    v.resize(2*n-1);
    
    forn(i,2*n-1) {
        char c; cin>>c;
        // 0 si es R, 1 si es W
        v[i]=(c=='W');
    }
    cout<<unosWind()<<endl;




}
