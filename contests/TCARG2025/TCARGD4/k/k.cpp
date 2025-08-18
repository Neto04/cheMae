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

const int INF = 1e9;

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> minimos(n);
    for (int i = 0; i < n; i++) {
        string s; cin>>s;
        int a, b, c; cin>>a>>b>>c;
        if (a == -1) a = INF;
        if (b == -1) b = INF;
        if (c == -1) c = INF;
        minimos[i] = min(a, min(b,c));
    }

    sort(minimos.begin(), minimos.end());
    int tiempo = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (tiempo + minimos[i] <= 300) {
            ans++;
            tiempo += minimos[i];
        } else {
            break;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
