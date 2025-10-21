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
int tope=1e6;

const ll INF = 1e18;
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // vector<int> v(1e6+3,1);
    // int mD=0, bV=0;
    // forr(i, 2, tope+1) {
    //     for(int j=i; j<tope+1; j+=i) {
    //         v[j]++;
    //         if (v[j]>mD) {
    //             mD = v[j];
    //             bV=j;
    //         }
    //     }
    // }
    // cout<<mD<<" "<<bV<<endl;
    ll a = INF, b = INF;
    ll c, d; cin>>c>>d;
    vector<ll> fizz, buzz, fizzbuzz, solos;
    for (ll i = c; i <= d; i++) {
        string s; cin>>s;
        if (s == "Fizz") {
            fizz.push_back(i);
            if (a == INF) a = i;
            else a = gcd(a, i); 
        } else if (s == "Buzz") {
            buzz.push_back(i);
            if (b == INF) b = i;
            else b = gcd(b, i);
        } else if (s == "FizzBuzz") {
            fizzbuzz.push_back(i);
            if (a == INF) a = i;
            else a = gcd(a, i); 
            if (b == INF) b = i;
            else b = gcd(b, i);
        } else solos.push_back(i);
    }
    
    if (a == INF) a = d+1;
    if (b == INF) b = d+1;

    // // Corrijo a
    // for (ll& x : buzz) {
    //     if (a < x) a /= gcd(a, x);
    // }
    // for (ll& x : solos) {
    //     if (a < x) a /= gcd(a, x);
    // }
    // // Corrijo b
    // for (ll& x : fizz) {
    //     if (b < x) b /= gcd(b, x);
    // }
    // for (ll& x : solos) {
    //     if (b < x) b /= gcd(b, x);
    // }

    cout<<a<<" "<<b<<"\n";

    return 0;
}
