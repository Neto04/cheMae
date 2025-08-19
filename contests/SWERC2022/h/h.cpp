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
    while (tC--) {
        int n; cin>>n;
        vector<bool> brincon(n+1);
        vector<int> a(n), b(n);
        forn(i, n) cin>>a[i];
        forn(i, n) cin>>b[i];
        int i1=n-1, i2;
        int ans=0;
        for( i2=n-1; i2>=0&&i1>=0; i2--) {
            ifd cout<<"i2 = "<<i2<<", i1="<<i1<<", ans = "<<ans<<endl;
            if (brincon[b[i2]]) {

                break;
            }
            while (a[i1]!=b[i2] and i1>=0) {
                brincon[a[i1]]=true;
                ifd cout<<a[i1]<<" es brincon"<<endl;
                i1--;
            }
            i1--;
            
        }
        ans=i2+1;
        cout<<ans<<endl;
    }

}
