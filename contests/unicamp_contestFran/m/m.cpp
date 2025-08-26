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

    string x, y; cin>>x>>y;

    if (x[0] == '0' or y[0] == '0') {
        cout<<0<<"\n";
        return 0;
    }

    ll esesX = 0, esesY = 0;
    for (char c : x) {
        if (c == 'S') esesX++;
    }
    for (char c : y) {
        if (c == 'S') esesY++;
    }

    ll esesAns = esesX * esesY;
    for (ll i = 0; i < esesAns; i++) {
        cout<<"S(";
    }
    cout<<0;
    for (ll i = 0; i < esesAns; i++) {
        cout<<")";
    }
    cout<<"\n";

    return 0;
}
