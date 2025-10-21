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
// la vara original
string s;
// el mod que está probando ahorita
ll MOD;
// me tira 10^k mod MOD
ll exp(ll base, ll exp) {
    ll r=1;
    while (exp) {
        if (exp%2) r=r*base%MOD;
        base=base*base%MOD;
        exp/=2;
    }
    return r;
}



ll dp[13][109][109][2];
bool seen[13][109][109][2];
// en este momento usted está viendo el dígito i (de izq a der) 
// lleva congruencia cong
// sus digitos suman sum
// y men le dice si de fijo la vara es < s
ll solve(int i, int cong, int sum, bool men) {
    ifd cout<<"estoy poniendo el digito "<<i<<", llevo congruencia "<<cong<<", suma = "<<sum<<", y men = "<<men<<endl;
    ifd cout<<"vea que s en i = "<<s[i]<<endl;
    // si ya lo vio, gg
    if (seen[i][cong][sum][men]) return dp[i][cong][sum][men];
    seen[i][cong][sum][men] = true;
    ll& ans = dp[i][cong][sum][men];
    int tope =9;
    if (!men) tope = (s[i]-'0');
    ifd cout<<"mi tope = "<<tope<<endl;
    // si ya es el ultimo digito, solo intente llenar la vara y ya
    if (i==12) {
        ifd cout<<"eyy, estoy en el ultimo digito"<<endl;
        for(int j =0; j<=tope; j++) if ((cong+j)%MOD ==0 and (sum + j)==MOD) {
            ifd cout<<"vea que sirve poner "<<j<<endl;
            ans ++;
        }
        return ans;
    }
    int cMen, cSum, cCong;
    for(int j =0; j<=tope; j++) {
        ifd cout<<"intento meter "<<j<<"en la posicion "<<i<<endl;
        // sepa que va a intentar 
        cMen = men or ((s[i]-'0')>j);
        // si se pasa de lo que tienen que sumar los digitos, rip
        if (sum + j > MOD) {
            ifd cout<<"SE PASA DE LA SUMA"<<endl;
            continue;
        }
        // cSum = suma de lo que lleva + j
        cSum = sum + j;
        ifd cout<<"cSum sería "<<cSum<<endl;
        // cCong =  (congruencia + 10^ #dig * j)%MOD
        
        cCong = (cong + exp(10, 12-i)*j)%MOD;
        ifd cout<<"y cCong = "<<cCong<<endl;
        ans +=solve(i+1, cCong, cSum, cMen);
    }

    return ans;

}








int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    freopen("just.in", "r", stdin);
    freopen("just.out", "w", stdout);
    cin>>s;
    // asegurese de que s tenga 12 digitos
    int falta = 13-s.size();
    string ss;
    while (falta--) ss.push_back('0');
    for(char c:s) ss.push_back(c);
    s=ss;
    
    ifd cout<<"s = "<<s<<endl;

    ll ans =0;
    forr(x, 1,109) {
        MOD = x;
        ifd cout<<"PRUEBO CON MOD = "<<MOD<<endl;
        forn(i, 13) forn(j, 109) forn(k, 109) forn(l, 2) {
            dp[i][j][k][l]=0;
            seen[i][j][k][l]=0;
        }
        ans+=solve(0, 0, 0, 0);
    }

    cout<<ans<<endl;
}
