// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (ll i=a; i<b; i++)
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
    ll n; cin>>n;
    vector<ll> v(n);
    forn(i, n) cin>>v[i];
    vector<ll> v2=v;
    
    sort(v2.begin(), v2.end());
    ll ans1 = 0, ans2 = 0;
    forn(i, n) {
        ans1+=v[i]*(i+1);
        ans2+=v[i]*(i+1);
    }
    
    // PASE GRANDE AL FONDO
    // busque el max tq esta desacomodado
    ll cagadoGrande = -1;
    ll targetPosG;
    for (ll i=n-1; i>=0; i--) {
        if (v2[i]!=v[i]) {
            cagadoGrande=v2[i];
            ifd cout<<"el max mal puesto es "<<cagadoGrande<<endl;
            targetPosG=i;
            break;
        }
    } 
    if (cagadoGrande!=-1) {
        // busque la primera pos en la que está ese mae
        ans1=0;
        ll malPos;
        for(ll i=0; i<n; i++) if (v[i]==cagadoGrande) {
            malPos=i;
            break;
        }

        vector<ll> v3;
        for(ll i=0; i<malPos; i++) v3.push_back(v[i]);
        for(ll i=malPos+1; i<=targetPosG; i++) v3.push_back(v[i]);
        v3.push_back(cagadoGrande);
        for(ll i=targetPosG+1; i<n; i++) v3.push_back(v[i]);
        ifd {
            cout<<"moviendo el grande al fondo me queda:"<<endl;
            for (auto u:v3) cout<<u<<" ";
            cout<<endl;
        }

        forn(i, n) ans1+=v3[i]*(i+1);
    }

    // busque el min tq está desacomodado
    ll cagadoMin = -1, targetPosM;
    for(ll i=0; i<n; i++) {
        if (v[i]!=v2[i]) {
            cagadoMin=v2[i];
            targetPosM=i;
            break;
        }
    }

    // busque la primera pos en la que está ese mae
    if (cagadoMin!=-1) {
        ans2=0;
        ll malPos;
        for(ll i=n-1; i>=0; i--) if (v[i]==cagadoMin) {
            malPos=i;
            break;
        }

        vector<ll> v3;
        for(ll i=0; i<targetPosM; i++) v3.push_back(v[i]);
        v3.push_back(cagadoMin);
        for(ll i=targetPosM; i<malPos; i++) v3.push_back(v[i]);
        for(ll i=malPos+1; i<n; i++) v3.push_back(v[i]);

        ifd {
            cout<<"moviendo el Min al fondo me queda:"<<endl;
            for (auto u:v3) cout<<u<<" ";
            cout<<endl;
        }

        for(ll i=0; i<n; i++) ans2+=v3[i]*(i+1);
    }
    cout<<max(ans1, ans2)<<endl;

    return 0;
}
