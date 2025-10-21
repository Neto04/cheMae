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

    freopen("enchanted.in", "r", stdin);
    freopen("enchanted.out", "w", stdout);

    string s1, s2, t1, t2; cin>>s1>>s2>>t1>>t2;
    int n = s1.size();

    vector<pair<char,char>> cur, goal;
    forn(i,n) cur.push_back({s1[i],s2[n-i-1]});
    forn(i,n) goal.push_back({t1[i],t2[n-i-1]});

    forn(i,n) {
        if (cur[i] == goal[i]) continue;
        bool found = false;
        for (int j = i+1; j < n and !found; j++) {
            if (cur[j] == goal[i]) {
                swap(cur[i], cur[j]);
                found = true;
            }
        }
        if (not found) {
            cout<<"No\n";
            return 0;
        }
    }

    cout<<"Yes\n";

    return 0;
}
