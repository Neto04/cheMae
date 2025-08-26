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

#define T(x) x.first
#define A(x) (x.second).first
#define B(x) (x.second).second

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int k; cin>>k;
    // {t,{a,b}}
    vector<pair<ll,pair<ll,ll>>> v;
    for (int i = 0; i < k; i++) {
        ll t, a, b; cin>>t>>a>>b;
        v.push_back({t,{a,b}});
    }
    sort(v.begin(), v.end());

    int q; cin>>q;
    while (q--) {
        ll temp, flujo; cin>>temp>>flujo;
        // Flujo
        ll minFlujo = 0LL, maxFlujo = 0LL;
        for (auto& x : v) {
            minFlujo += A(x);
            maxFlujo += B(x);
        }
        if (flujo < minFlujo or flujo > maxFlujo) {
            cout<<"no\n";
            continue;
        }

        // Temp
        ll minTemp = 0, maxTemp = 0;
        for (auto& x : v) {
            minTemp += A(x)*T(x);
            maxTemp += A(x)*T(x);
        }
        // Temp minima
        ll count = flujo-minFlujo;
        int i = 0;
        while (count and i < k) {
            // Termino lo que me falta sin pasarme del maximo o de lo que me queda
            ll x = min(count, B(v[i])-A(v[i]));
            minTemp += (x * T(v[i]));
            count -= x;
            i++;
        }
        // Temp maxima
        count = flujo-minFlujo;
        i = k-1;
        while (count and i >= 0) {
            ll x = min(count, B(v[i])-A(v[i]));
            maxTemp += (x * T(v[i]));
            count -= x;
            i--;
        }

        if (temp*flujo < minTemp or temp*flujo > maxTemp) {
            cout<<"no\n";
            continue;
        }

        cout<<"yes\n";
    }

    return 0;
}
