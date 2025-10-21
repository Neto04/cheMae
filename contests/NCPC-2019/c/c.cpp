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
ll a;
// asume una vara con n filas, todas de length m
bool puedeDos(ll n, ll m) {
    ll com =0;
    // vea a ver si puede hacer un cuadradito
    for(int i=1; i<=min(a, m); i++) {
        if (a%i==0) {
            ll c = a/i;
            if (c<=n) return true;
        }
    }

    if (a<m) return true;

    for(ll i=1; i<n and (i*m<=a); i++) {
        // hasta ahorita se ha comido i*m
        com = i*m;
        // si a - la cantidad que se ha comido, es divisible por lo que sobra, gg
        if ((a-com)%(n-i)==0) return true;
    }
    
    return false;
}


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin>>n>>m>>a;
    ll nAns, mAns;
    // si m divide a a, de fijo es un corte
    if (a%m==0) mAns=1;
    else if (puedeDos(n, m)) mAns=2;
    else mAns=3;


    if (a%n==0) nAns=1;
    else if (puedeDos(m, n)) nAns=2;
    else nAns=3;


    cout<<min(mAns, nAns)<<"\n";

    return 0;
}
