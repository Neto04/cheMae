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
    int n, m,q; cin>>n>>m>>q;
    vector<vector<int>> v(n, vector<int>(m));
    forn(i, n) forn(j, m) cin>>v[i][j];

    while (q--) {
        int op; cin>>op;
        ifd cout<<"op = "<<op<<endl;
        if (op==1) {
            int r; cin>>r; r--;
            reverse(v[r].begin(), v[r].end());
        }
        if (op==2) {
            int c; cin>>c; c--;
            vector<int> temp;
            forn(i, n/2) 
                swap(v[i][c], v[n-1-i][c]);

        } 
        if (op==3) {
            int r, c; cin>>r>>c; r--, c--;
            cout<<v[r][c]<<"\n";
        }



    }






}
