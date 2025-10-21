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

int n, s;
vector<int> ans;

void solve(int l, int r, int count) {
    if (l > r) return;
    count++;
    int m = (l+r)/2;
    if (count == s) ans.push_back(m);
    else if (count < s) {
        solve(l, m-1, count);
        solve(m+1, r, count);
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while(tC--) {
        cin>>n>>s;
        ans.clear();

        solve(0, n-1, 0);

        sort(ans.begin(), ans.end());
        for (int& x : ans) cout<<x<<" ";
        cout<<"\n";
    }

    return 0;
}
