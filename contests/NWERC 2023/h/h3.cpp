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

ll n;
string ans = "";

ll getK() {
    ll maxi = 0, k = 1;
    for (ll i = 1; i <= n; i++) {
        ll cosa = pow(i, n/i) * (n - n/i * i);
        if (cosa > maxi) k = i, maxi = cosa;
    }
    return k;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    multiset<int> s;
    int maxi = 0, unos = 0;
    forn(i,n) {
        int x; cin>>x;
        if (x == 1) unos++;
        else s.insert(x);
        maxi = max(maxi, x);
    }   

    if (maxi == 1) {
        ll k = n;
        if (n > 3) k = getK();
        forn(i,n/k) {
            ans += '(';
            forn(j,k) ans += "1+";
            ans.pop_back();
            ans += ")*";
        }
        cout<<"k = "<<k<<endl;
        ll sobro = n - (n/k * k);
        ans += '(';
        forn(i,sobro) ans += "1+";
        ans.pop_back();
        ans += ')';
    } else {
        // Quito todos los unos
        while (unos and (*s.begin() == 2)) {
            s.erase(s.begin());
            s.insert(3);
            unos--;
        }
    }

    if (ans[ans.size()-1] == '*') ans.pop_back();

    cout<<ans<<"\n";

    return 0;
}
