#include <bits/stdc++.h>
#define ll long long
using namespace std; 
#define ii pair<ll, ll> 

#define debug 0
#define ifd if(debug)
#define MAX 1e6+5
#define forr(i, a, b) for(int i=a; i<b; i++)
#define forn(i,b) forr(i, 0, b)

long double solve(double p, double k, double tp, double tc) {
    if (p==0) return k*tc;

    else if (k==0) return 0;

    double v1 = (p/(p+1))*(tp+solve(p-1, k, tp, tc));
    double v2 = (1/(p+1))*(tc+solve(p, k-1, tp, tc));
    return v1+v2;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int q; cin>>q;
    cout<<setprecision(4)<<fixed;
    
    while (q--) {
        ll p, k, tp, tc;
        cin>>p>>k>>tc>>tp;
        double ans = (tc*p+tp)*k;
        ans/=1000; 
        cout<<ans<<"\n";
    }

}
