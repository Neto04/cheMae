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
const int MAXNN=100100;

#define debug 0
#define ifd if (debug)
ll raizQ(ll a) {
    long long x = sqrt(a) + 2;
    while (x * x > a) x--;

    return x;
}




int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vector<ll> v(n);
    forn(i,n) cin>>v[i];
    sort(v.begin(), v.end());
    if (n==1 and v[0]==1) {
        cout<<"*"<<endl;
        return 0;
    }
    // si 1 no está, de fijo rip
    if (v[0]!=1) {
        cout<<v[n-1]<<" "<<1<<endl;
        return 0;
    }
    
    set<ll> s;
    forn(i, n) s.insert(v[i]);
    ll NN = v[n-1];
    ll nReal=NN, missing=-1;
    for(ll x:s) {
        if ((NN%x)!=0) {
            ifd cout<<"NN = "<<NN<<", x = "<<x<<endl;
            nReal = v[1]*NN;
            missing = nReal;
            break;
        }
        auto u = s.find(NN/x);
        // si el otro mae no está
        if (u==s.end()) missing = NN/x;
    }
    if (missing ==-1) {

        ll x = raizQ(NN);
        // if NN tiene raiz cuadrada
        if (x*x==NN and s.find(x)==s.end()) {
            nReal=NN, missing = x;
        }
        // ya sea que no hay raizQ o el mae sí estaba, entonces de fijo es v[1]*NN
        else {
            nReal=v[1]*NN;
            missing = nReal;
        }
    }
    cout<<nReal<<" "<<missing<<endl;



}
