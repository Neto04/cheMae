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
ll n, g; 


bool check(ll k) {
    return ((k*(k+1))/2)<=n;
}
// me tira el min k tq k*(k+1)/2 <=n
ll bSearch () {
    // a de fijo cumple, b de fijo no
    ll a =0, b= n;
    while (b-a>1) {
        ll c= (b+a)/2;
        // ifd cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<endl;
        if (check(c)) a=c;
        else b=c;
    }
    return a;


}
// pref Sum
vector<ll> pSum;
// vector de los huequitos
vector<ll> v;
vector<vector<ll>> dp;
vector<vector<bool>> seen;


// cuanto es el max que puede ganar si ahorita está en i y tiene que poner el tuco de length k?
ll solve(int i, int k) {
    // vea que si en la pos i pone un tuco tam k, usted termina en la pos i+k-1
    
    // TODO:esto está bien?
    // si ni siquiera puede ponerlo, no lo ponga
    if (i+k-1>=n) return 0;
    ifd cout<<"i = "<<i<<", k = "<<k<<endl;

    if (seen[i][k]) return dp[i][k];
    seen[i][k]=true;
    // ponerlo en la sig
    ll x1 = solve(i+1, k);
    ll rest=pSum[i+k-1];
    if (i>0) rest-=pSum[i-1];
    // ponerlo en esta, y empezar en el sig
    ll x2 = solve(i+k, k+1) + g - rest ;

    return dp[i][k]=max(x1, x2);

}



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>g;
    // lea v y pSum
    v.resize(n);
    forn(i,n) cin>>v[i];
    pSum.resize(n, v[0]);
    forr(i, 1, n) pSum[i]=v[i]+pSum[i-1];

    // aliste dp y seen
    dp.resize(n);
    seen.resize(n);
    ll k=bSearch();
    forn(i, n) {
        dp[i].resize(k+1);
        seen[i].resize(k+1);
    }

    
    cout<<solve(0, 1)<<endl;




}
