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

#define debug 0
#define ifd if (debug)
vector<ll> freq(5);
ll ans=0;

int gente() {

    ll nG=0;
    forr(i, 1, 5) if (freq[i]) nG++;
    return nG;
}


ll f(ll m1, ll m2, ll c11, ll c12, ll c21, ll c22) {
    ifd cout<<"m1 ="<<m1<<" m2 = "<<m2<<" c11 ="<<c11<<" c21 ="<<c21<<" c22 = "<<c22<<endl;
    ll x= min(freq[m1]/c11, freq[m2]/c12);
    ll fA, fB;
    ll ans1, ans2;
    fA=(freq[m1]-x*c11); fB=(freq[m2]-c12*x);

    ll y = min(fA/c21, fB/c22);
    ll resp = x+y+((fA-y*c21)/5+(fB-y*c22)/5);

    return resp;
}




void hagaDos() {
    ll x, y,ans1, ans2, fA, fB;
    // si hay 1: 
    if (freq[1]) {

        // si 1 2  
        if (freq[2]) {
            // 1 1 1 2 y luego 1 2 2 

            ans1 = f(1, 2, 3, 1, 1, 2);

            // 1 2 2 
            ans2 = f(1, 2, 1, 2, 3, 1);

            ans += max(max(ans1, ans2), freq[1]/5+freq[2]/5);
        }

        // si 1 3
        if (freq[3]) {
            // 1 1 3 y luego 1 3 3 3
            ans1 = f(1, 3, 2, 1, 1, 3);

            
            // 1 3 3 3 y luego 1 1 3
            ans2 = f(1, 3, 1, 3, 2, 1);
            
            ans += max(max(ans1, ans2), freq[1]/5+freq[3]/5);
        }
    }
    // ahora caso 4
    else {
        // si 4 2
        if (freq[2]) {
            // 4 4 2 y luego 4 2 2 2
            ans1 = f(4, 2, 2, 1, 1, 3);

            // 4 2 2 2 
            ans2 = f(4, 2, 1, 3, 2, 1);

            ans += max(max(ans1, ans2), freq[4]/5+freq[2]/5);
        }

        // si 4 3
        if (freq[3]) {
            // 4 4 4 3 
            ans1 = f(4, 3, 3, 1, 1, 2);
            
            // 4 3 3
            ans2 = f(4, 3, 1, 2,3, 1);

            ans += max(max(ans1, ans2), freq[4]/5+freq[3]/5);

        }
    }

}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin>>n;
    forn(i, n) {
        ll x; cin>>x; freq[x%5]++;
    }
    ans=freq[0]; freq[0]=0;

    // haga 1 y 4
    ll x =min(freq[1], freq[4]);
    freq[1]-=x;
    freq[4]-=x;
    ans +=x;
    
    // haga 2 y 3
    x =min(freq[2], freq[3]);
    freq[2]-=x;
    freq[3]-=x;
    ans+=x;


    int nG=gente();
    if (nG==1) forr(i, 1, 5) ans +=freq[i]/5;
    else if (nG) hagaDos();
    cout<<ans<<endl;



}