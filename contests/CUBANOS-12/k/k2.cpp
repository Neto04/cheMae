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
    freopen("key.in", "r", stdin);
    freopen("key.out", "w", stdout);
    int n, m; cin>>n>>m;
    priority_queue<ll> pq;
    forn(i, n) {
        ll x; cin>>x;
        pq.push(-x);
    }
    vector<ll> ans;
    ll suma =0;
    while (!pq.empty()) {
        ll x = -(pq.top());
        if (x>suma+1) {
            if (m<=0) break;
            m--;
            ans.push_back(suma+1);
            suma+=suma+1;
        } 
        else {
            suma+=x;
            pq.pop();
        }
    }
    while (m>0) {
        ans.push_back(suma+1);
        suma+=suma+1;
        m--;
    }
    for(ll u:ans) cout<<u<<" ";
    cout<<endl;

    


    return 0;
}
