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

bool valid(int i, int j) {
    return (i >= 1 and i <= 10 and j >= 1 and j <= 10);
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> board(11, vector<int>(11, 0));

    int n; cin>>n;
    forn(i,n) {
        int d, l, r, c; cin>>d>>l>>r>>c;
        if (d == 0) {
            for (int j = 0; j <= l-1; j++) {
                if (not valid(r,c+j) or board[r][c+j]) {
                    cout<<"N\n";
                    return 0;
                } 
                board[r][c+j] = 1;
            }
        } else {
            for (int j = 0; j <= l-1; j++) {
                if (not valid(r+j,c) or board[r+j][c]) {
                    cout<<"N\n";
                    return 0;
                } 
                board[r+j][c] = 1;
            }
        }
    }

    cout<<"Y\n";

    return 0;
}
