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

    ll n, m, k; cin>>n>>m>>k;

    if (n < m) {
        m = n;
    }
    if (m==1) {
        // cuantas veces puede restarle k a n
        ll q = n/k;
        ll ans = n*(q+1)-((q*(q+1))/2)*k;
        cout<<ans<<endl;
        return 0;
    }
    // q es la cantidad de maes que le faltan por asignar
    ll q = (n-m)/k, ans=0;
    ll r = n-m-q*k;
    ll p = r/(m-1);
    ll rPrima=r-p*(m-1);
    ll uno = q*k+1;
    ll d=0;



    while (uno>0) {
        d+=uno + rPrima*(p+2)+(m-1-rPrima)*(p+1);
        uno-=k;
    }

    ll total = (p+2)*rPrima + (p+1)*(m-1-rPrima);
    if (p+2<=k) {
        forn(i, rPrima) {
            d+=total;
            total-=p+2;
            
        }

        forn(i, m-1-rPrima) {
            d+=total;
            total-=(p+1);
        }
        
    }
    else {
        forn(i, rPrima) {
            d+=total;
            total-=k;
            d+=total;
            total-=(p+2-k);
        }
        if (p+1<=k) {
            forn(i, m-1-rPrima) {
                d+=total;
                total-=(p+1);
            }
        }
        else {
            forn(i, m-1-rPrima) {
                d+=total;
                total-=k;
                d+=total;
                total-=(p+1-k);
            }
        }
    }
    cout<<d<<endl;
    return 0;
}
