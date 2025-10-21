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

vector<int> pSum;

ll rSum(int l, int r) {
    if (l>r) return 0;
    ll ans = pSum[r];
    if (l) ans -=pSum[l-1];
    return ans;
}


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int tC; cin>>tC;
    while (tC--) {
        int n, q; cin>>n>>q;
        pSum.clear();
        pSum.resize(n);
        vector<int> mes(n);
        forn(i, n) {
            cin>>mes[i];
            pSum[i]=mes[i];
            if (i) pSum[i] +=pSum[i-1]; 
        }
        
        while (q--) {
            ll ans=1e18;
            int d1, m1, d2, m2;
            cin>>d1>>m1>>d2>>m2;
            m1--, m2--;
            if (m1==m2) {
                if (d1<=d2) {
                    ifd cout<<"caso 1"<<endl;
                    ans = d2-d1+1;
                }
                else {
                    ifd cout<<"caso 2"<<endl;
                    ans = rSum(m1+1, n-1) +rSum(0, m1-1) + (mes[m1]-d1+1) + d2;
                }
            }

            if (m1<m2) {
                ifd cout<<"caso 3"<<endl;
                ans = mes[m1]-d1+1 + rSum(m1+1, m2-1) + d2;
            }

            if (m1>m2) {
                ifd cout<<"caso 4"<<endl;
                ans = rSum(m1+1, n-1) + rSum(0, m2-1) + (mes[m1]-d1+1) + d2;
            }


            cout<<ans<<"\n";
        }



    }

}
