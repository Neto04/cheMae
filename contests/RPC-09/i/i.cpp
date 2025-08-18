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
// retorna si empate (0) gana 1, gana 2, nadie (3)
int comp(vector<int>& d1, vector<int>& d2) {
    int ans1=0, ans2=0;
    forn(i, 6) forn(j, 6) {
        if (d1[i]>d2[j]) ans1++;
        if (d2[j]>d1[i]) ans2++;
    }

    if (ans1>ans2) return 1;
    if (ans2>ans1) return 2;
    if (ans1==0 and ans2==0) return 3;
    // sino, la vara es empate
    return 0;

}



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<vector<int>> v(3, vector<int> (6));


    forn(i, 3) forn(j, 6) cin>>v[i][j];
    int ans =-1;
    forn(i, 3) {
        // numero wins
        int nV=0;
        forn(j, 3) {
            if (j==i) continue;
            int cAns=comp(v[i], v[j]);

            if (cAns==1 or cAns==0) nV++;

        }

        if (nV==2) {
            ans=i+1; 
            break;
        }
    }
    if (ans==-1) cout<<"No dice"<<endl;
    
    else cout<<ans<<endl;

}
