// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (ll i=a; i<b; i++)
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

// nuevo plan: para cada mae: intente mover su primera ocurrencia al fondo, y su última ocurrencia al inicio 
int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin>>n;
    vector<ll> v(n);
    vector<ll> pSum(n);
    vector<ll> pPSum(n);
    vector<ll> fSum(n);
    vector<ll> fPSum(n);
    // para cada valor, me dicen primera y última pos en la que aparece
    vector<ll> first(1e6+5,1e9), last(1e6+5, -1);
    set<int> valores;
    forn(i, n) {
        cin>>v[i];
        pSum[i]=v[i]+((i>0)?pSum[i-1]:0);
        pPSum[i]=v[i]*(i+1)+((i>0)?pPSum[i-1]:0);
        first[v[i]]=min(first[v[i]], i);
        last[v[i]]=max(last[v[i]], i);
        valores.insert(v[i]);
    }
    // de atrás palante
    for(int i=n-1; i>=0; i--) {
        fSum[i]=v[i]+((i<n-1)?fSum[i+1]:0);
        fPSum[i]=v[i]*(i+1)+((i<n-1)?fPSum[i+1]:0);
    }
    
    ll ans=pPSum[n-1];
    for (ll u:valores) {
        // primero intente pasar su última aparición pal inicio
        int cL=last[u];
        ll inic=pPSum[n-1];
        if (cL>0) inic = pPSum[n-1]-u*(cL+1) +pSum[cL-1]+u;
        // ahora intente pasar su primera aparición pal final
        int cF=first[u];
        ll fin=0;


    }

    vector<ll> v2=v;
    sort(v2.begin(), v2.end());
    ll minV=v2[0], maxV=v2[n-1];
    ll firstMax=1e9, lastMin=-1;
    forn(i, n) {
        if (v[i]==maxV) firstMax=min(firstMax, i);
        if (v[i]==minV) lastMin=max(lastMin, i);
    }
    ll ans1=minV, ans2=maxV*n;
    for(int i=0; i<lastMin; i++) ans1+=v[i]*(i+1+1);
    for(int i=lastMin+1; i<n; i++) ans1+=v[i]*(i+1);

    for(int i=0; i<firstMax; i++) ans2+=v[i]*(i+1);
    for(int i=firstMax+1; i<n; i++) ans2+=v[i]*(i);
    cout<<max(ans1, ans2)<<endl;;
}
