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
    vector<int> v(n);
    for (int& x : v) cin>>x;
    sort(v.begin(), v.end());

    string ans = "";
    if (v[n-1] == 1) {
        if (n == 1) ans = "1";
        else if (n == 2) ans = "1+1";
        else {
            int parejas = 0;
            if (n % 2) parejas = (n-3)/2, ans = "(1+1+1)*";
            else parejas = (n-2)/2, ans = "(1+1)*";
            forn(i,parejas) ans += "(1+1)*"; 
        }
    } else {
        int i = 0;
        while (i < n) {
            if (v[i] == 1 and i+1 < n) {
                ans += "(1+";
                ans += to_string(v[i+1]);
                ans += ")*";
                i += 2;
            } else {
                break;
            }
        }

        while (i < n) {
            ans += to_string(v[i]);
            ans += '*';
            i++;
        }
    }

    if (ans[ans.size()-1] == '*') ans.pop_back();

    cout<<ans<<"\n";

    return 0;
}
