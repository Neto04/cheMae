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
int n, h;
vector<int> v;

vector<vector<ll>> dp(305, vector<ll> (2));
vector<vector<bool>> seen(305, vector<bool> (2));

ll solve (int i, int shared) {
    if (seen[i][shared]) return dp[i][shared];
    seen[i][shared]=true;
    if (i==n-1) {
        if (shared) return dp[i][shared]=0;
        else return dp[i][shared]=h;
    }   
    int x1=v[i], x2=v[i+1];
    int d=x2-x1;
    int bloq=d-1+((d%2)?0:-1);
    int niv=d/2 +((d%2)?0:-1);
    int c1=bloq+h-niv;
    int c2=c1+3;
    if (shared) {
        dp[i][shared]=min(c1+solve(i+1,1), solve(i+1, 0));
    }
    else {
        dp[i][shared]=min(c2+solve(i+1, 1), h+solve(i+1, 0));
    }
    ifd cout<<"dp("<<i<<", "<<shared<<") = "<<dp[i][shared]<<endl;
    return dp[i][shared];

    
}





int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>h;
    v.resize(n);
    forn(i,n) cin>>v[i];
    cout<<min(solve(0, 0), solve(0, 1))<<endl;
}
