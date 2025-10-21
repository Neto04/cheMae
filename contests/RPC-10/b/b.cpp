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
    ll t; cin>>t;
    vector<ll> a(n);
    forn(i, n) cin>>a[i];
    forn(tC, t) {
        int curr=1;
        forn(i, n) {
            curr--; a[i]++;
            if (curr==0) {
                if (a[i]==1) break;
                else {
                    curr+=a[i];
                    a[i]=0;
                }
            }
            

        }

        forn(i, n) cout<<a[i]<<" ";
        cout<<endl;
    }
    



}
