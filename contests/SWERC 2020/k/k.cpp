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


const ll MOD =1e9+7;
string s;
int n;
ll exp(ll base, ll exp) {
    ll r=1;
    while (exp) {
        if (exp%2) r=r*base%MOD;
        base=base*base%MOD;
        exp/=2;
    }
    return r;
}
// revise si puede hacerlo con un window de size x
int check(int x) {
    ll cH=0;
    vector<ll> gente;
    map<ll, int> freq;
    forn(i, x) cH=((cH*31)%MOD+(s[i]-'A'))%MOD;
    freq[cH]++;
    gente.pb(cH);
    
    int last=0;
    const ll pI=exp(31, x-1);
    for(int r=x; r<n; r++) {
        int lastL=s[last++]-'A';
        cH=((cH-(pI*lastL)%MOD)%MOD+MOD)%MOD;
        cH=(cH*31)%MOD;
        cH+=s[r]-'A';
        freq[cH]++;
        gente.pb(cH);
    }

    forn(i, gente.size()) {
        if (freq[gente[i]]==1) return i;
    }
    return -1;
}

// retorna {size, primerPuntoDondeCumple}
ii bSearch (){
    ii ans;
    int a=1, b=n;
    while (a<=b) {
        int c=(b-a)/2+a;
        int x=check(c);
        if (x!=-1) {
            ans = {c, x};
            b=c-1;
        }
        else a=c+1;

    }

    return ans;
}





int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>s; n=s.size();


    ii ans=bSearch();
    int start = ans.second;
    int fin=start+ans.first;
    for(int i=start; i<fin; i++) cout<<s[i];
    cout<<endl;

}
