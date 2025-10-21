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

const int N = 501;

int n;
// {i,j} y movimiento que le toca hacer
bool visited[N][N][2];
pair<int,int> moves[2];

bool valid(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < n);
}

void dfs(int i, int j, int num) {
    if (visited[i][j][num]) return;
    visited[i][j][num] = true;
    int a = moves[num].first, b = moves[num].second;

    if (valid(i-a, j-b)) dfs(i-a,j-b, (num+1)%2);
    if (valid(i-a, j+b)) dfs(i-a,j+b, (num+1)%2);
    if (valid(i+a, j-b)) dfs(i+a,j-b, (num+1)%2);
    if (valid(i+a, j+b)) dfs(i+a,j+b, (num+1)%2);

    if (valid(i-b, j-a)) dfs(i-b,j-a, (num+1)%2);
    if (valid(i-b, j+a)) dfs(i-b,j+a, (num+1)%2);
    if (valid(i+b, j-a)) dfs(i+b,j-a, (num+1)%2);
    if (valid(i+b, j+a)) dfs(i+b,j+a, (num+1)%2);
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    int a, b; 
    cin>>a>>b; moves[0] = {a,b};
    cin>>a>>b; moves[1] = {a,b};

    dfs(0,0,0);
    dfs(0,0,1);

    int ans = 0;
    forn(i,n) forn(j,n) if (visited[i][j][0] or visited[i][j][1]) ans++;
    cout<<ans<<"\n";

    return 0;
}
