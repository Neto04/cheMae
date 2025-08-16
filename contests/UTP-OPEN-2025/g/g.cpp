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

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
ll rnd(ll lo, ll hi) {
    return uniform_int_distribution <long long> (lo, hi)(rng);
}



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<ll> sustituto(26);
    // para cada letra saque su sustituto
    forn(i, 26) sustituto[i] =  rnd(1, 1e14);
    int tC; cin>>tC;
    while (tC--) {
        string s1, s2; cin>>s1>>s2;
        int n = s1.size();
        unordered_map<ll, int> freq;
        // PRIMERO, VAMOS CON A
        // para cada tamaño de window posible
        forr(i, 1, n+1) {
            ifd cout<<"window de tamaño "<<i<<endl;
            ll cS=0;
            int i2=0;
            for(i2; i2<i; i2++) cS+=sustituto[s1[i2]-'a'];
            freq[cS]++;
            while (i2<n) {
                ifd cout<<"meto el mae en "<<i2<<endl;
                cS+=sustituto[s1[i2]-'a'];
                ifd cout<<"saco al mae en "<<i2-i<<endl;
                cS-=sustituto[s1[i2-i]-'a'];
                freq[cS]++;
                i2++;
            }
        }

        ll ans =0;
        // AHORA, VAMOS CON B
        // para cada tamaño de window posible
        forr(i, 1, n+1) {
            ifd cout<<"window de tamaño "<<i<<endl;
            ll cS=0;
            int i2=0;
            for(i2; i2<i; i2++) cS+=sustituto[s2[i2]-'a'];
            ans+=freq[cS];
            while (i2<n) {
                ifd cout<<"meto el mae en "<<i2<<endl;
                cS+=sustituto[s2[i2]-'a'];
                ifd cout<<"saco al mae en "<<i2-i<<endl;
                cS-=sustituto[s2[i2-i]-'a'];
                ans+=freq[cS];
                i2++;
            }
        }

        cout<<ans<<endl;
    }
}
