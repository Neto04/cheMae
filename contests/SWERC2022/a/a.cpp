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
    int tC; cin>>tC;
    while (tC--) {
        int n; cin>>n;
        vector<int> v(n+1);
        v[0]=0;
        forr(i, 1, n+1) cin>>v[i];
        v.push_back(1440);
        int ans =0;
        forr(i,0, n+1) {
            if (v[i+1]-v[i]>=240) ans=2;
            else ans+=(v[i+1]-v[i]>=120);
        }
        if (ans>=2) cout<<"YES\n";
        else cout<<"NO\n";
    }

}
