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
    vector<ii> v(n);
    forn(i,n) cin>>v[i].first>>v[i].second;
    sort(v.begin(), v.end());
    bool won = 1;
    queue<ii> ans;
    forn(i,n-1) ans.push(v[i]);
    if (won) {
        cout<<"YES\n";
        while (!ans.empty()) {
            cout<<ans.front().first<<" "<<ans.front().second<<"\n";
            ans.pop();
        }
    }
}


