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
typedef pair<ll, ll> ii;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)
// TODO: cin
int n,l, h;
// TODO: resize
vector<int> v;
bool valid(int x) {
    return (l<=x and x<=h);
}
// me dice el min que tengo que sumarle, y el max que tengo que sumarle
// TODO: resize
vector<ii> cotas;


// TODO: resize
vector<bool> seen, dp;
// ahorita mismo usa tamagno k de intervalo
int k;
bool solve (int i) {
    // si ya dejó solo el último, todo bien
    if (i==n) return true;
    // si dejó extra por whatever motivo, rip
    if (i>n) return false;
    // si seen, dp
    if (seen[i]) return dp[i];
    seen[i]=true;
    // si no puede agarrar k maes, rip
    if (i+k-1>=n) return dp[i]=false;
    ll minV=-1e9, maxV=1e9;
    ll cMin, cMax;
    for(int j =i; j<i+k; j++) {
        tie(cMin, cMax)=cotas[j];
        // si lo min que usted ocupa sumarle es > al max que podia sumar, rip
        // si lo max que usted ocupa sumar es < al min que podia sumar, rip
        if (cMin>maxV or cMax <minV) return dp[i]=false;
        minV = max(minV, cMin), maxV=min(maxV, cMax);
        // si algo sale mal, echele tierra
        if (minV >maxV) return dp[i]=false;
    }
    // quiere de ahí al fondo algo que 
    for(int j=i+k; j<=n; j++) {
        // revise si puede solo dejar esa vara y ya
        if (solve(j)) return dp[i]=true;
        if (j>=n) break;
        // sino, simule comerse a ese mae
        // saque las cotas
        tie(cMin, cMax)=cotas[j];
        // si lo min que usted ocupa sumarle es > al max que podia sumar, rip
        // si lo max que usted ocupa sumar es < al min que podia sumar, rip
        if (cMin>maxV or cMax <minV) return dp[i]=false;
        minV = max(minV, cMin), maxV=min(maxV, cMax);
        // si algo sale mal, echele tierra
        if (minV >maxV) return dp[i]=false;
    }
    return dp[i]=false;
}
// me retorna el max min tamańo de intervalo
ll search() {
    // 1 de fijo se puede, n+1 de fijo no se puede
    int a=1, b=n+1;
    // usted busca el max mae tq puede ser el min
    while (b-a>1){
        k = (b+a)/2;
        forn(i, n) dp[i]=seen[i]=false;
        if (solve(0)) a=k;
        else b=k;
    }
    return a;
}




int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>l>>h;
    v.resize(n);
    cotas.resize(n);
    seen.resize(n);
    dp.resize(n);
    forn(i,n) {
        cin>>v[i];
        for(int x=-1000; x<=1000; x++) if (valid(v[i]+x*12)) {
            cotas[i].first=x*12;
            break;
        }
        for(int x=1000; x>=-1000; x--) if (valid(v[i]+x*12)) {
            cotas[i].second=x*12;
            break;
        }
    }
    
    cout<<search()<<endl;

}
