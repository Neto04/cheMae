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
const ll MAXN=1e17;

#define debug 0
#define ifd if (debug)

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int tC; cin>>tC;
    int n, x;
    while (tC--) {
        cin>>n;
        vector<int> freq(1e5+2);
        int nT=n;
        forn(i, n) {
            cin>>x;
            freq[x]++;
        }
        ll ans=0;
        int i1=0, i2=0, v3;
        queue<ll> q1, q2;
        forn(i, 1e5+2) {
            while (freq[i]) {
                q1.push(i);
                freq[i]--;
            }
        }

        ll x1 = q1.front(); q1.pop();
        ll x2 = q1.front(); q1.pop();
        ans+=x1+x2;

        q2.push(x1+x2);
        while ((q1.size()+q2.size())>=2) {
            ll x11 = (q1.empty())?MAXN:q1.front();
            ll x12 = (q2.empty())?MAXN:q2.front();

            x1 = min(x11, x12);
            if (x11<x12) q1.pop();
            else q2.pop();
            
            ll x21 = (q1.empty())?MAXN:q1.front();
            ll x22 = (q2.empty())?MAXN:q2.front();
            x2 = min(x21, x22);

            if (x21<x22) q1.pop();
            else q2.pop();

            ans+=x1+x2;
            q2.push(x1+x2);
        }
        
        cout<<ans<<"\n";

    }

}
