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
    freopen("important.in", "r", stdin);
    freopen("important.out", "w", stdout);
    int n; cin>>n;
    string s;
    vector<char> ans;
    getline(cin, s);
    ifd cout<<"s = "<<s<<endl;
    forn(i, n) {
        getline(cin, s);
        ans.push_back(s[0]);
    }
    cout<<"Yes"<<endl;
    forn(i,n) {
        cout<<"("<<ans[i]<<" | ~"<<ans[i]<<")";
        if (i<n-1) cout<<"&";
    }
    cout<<endl;

}
