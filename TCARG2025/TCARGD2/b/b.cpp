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
    int tC=1;
    while (tC--) {
        string s; cin>>s; 
        ifd cout<<"s = "<<s<<endl;
        int n =s.size();
        vector<ii> ans(n+1);
        queue<int> q0, q1;
        forn(i, n) {
            int x=s[i]-'0';
            // if vertical
            if (!x) {
                if (q0.empty()) q0.push(i);
                else {
                    int j=q0.front(); q0.pop();
                    ans[j] = {1, 4}; ans[i]={3, 4};
                }
            }
            // if horizont
            else {
                if (q1.empty()) q1.push(i);
                else {
                    int j=q1.front(); q1.pop();
                    ans[j] = {4, 1}; ans[i]={4, 3};
                }
            }
        }
        // si quedaba vertical
        if (!q0.empty()) {
            int j=q0.front(); q0.pop();
            ans[j] = {2, 1};
        }
        // if horizon
        if (!q1.empty()) {
            int j=q1.front(); q1.pop();
            ans[j] = {1, 1};
        }


        forn(i,n) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }

}
