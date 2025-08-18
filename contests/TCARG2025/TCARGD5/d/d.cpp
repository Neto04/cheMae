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
const int N = 2*1e5+5;
#define debug 0
#define ifd if (debug)

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        int n; cin>>n;
        vector<ll> v(n);
        forn(i,n) {
            cin>>v[i];
            v[i]=max(v[i].val, n);
        }
        vector<bool> seen(N);
        vector<ll> ans(n), minSup(N);
        ll maxMat=0;
        
        
        forn(i, n ) {
            ll x= v[i];
            ifd cout<<" i = "<<i<<" x = "<<x<<endl;
            ll v1=i+1-minSup[x]; if (!seen[x]) v1= 0;
            ans[i]=max(v1, maxMat);
            if (seen[x]) minSup[x]= min(i-ans[i-1], minSup[x]);
            else minSup[x]=i-maxMat;
            maxMat=max(maxMat, ans[i]);
            seen[x]=true;
        }
        ifd{
            cout<<"ans:"<<endl;
            forn(i, n) {
                cout<<ans[i]<<" ";
            }
            cout<<endl;

            cout<<"minSup"<<endl;
            forn(i, N) {
                if (seen[i]) cout<<i<<": "<<minSup[i]<<" ";
            }
            cout<<endl;

            
        }

        cout<<ans[n-1]<<"\n";
    }


}
