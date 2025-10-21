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

    int n; cin>>n;
    ll izq = 1e9, der = 0, arr = 0, aba = 1e9;
    forn(i, n) {
        ll x, y; cin>>x>>y;
        izq = min(izq, x);
        der = max(der, x);
        aba = min(aba, y);
        arr = max(arr, y);
    }

    izq--; der++;
    aba--; arr++;

    cout<<(2LL*(der-izq)+2LL*(arr-aba))<<"\n";

    return 0;
}
