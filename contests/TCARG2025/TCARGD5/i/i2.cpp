#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)

typedef long long ll;
typedef pair<int, int> ii;
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
const int MAXN=100100;
const ll INF=1e9+7;

#define debug 1
#define ifd if (debug)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

bool rComp(ii a, ii b) {
    if(a.first==b.first) return a.second>b.second;
    return a.first>b.first;
    
}
int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin>>n;
    // yo quiero un vector de {#episodios, temporada}
    vector<ii> v(n);

    forn(i,n) {
        ll x;
        cin>>x;
        x=min(x, n);
        v[i]={x, i+1};
    }


    sort(v.begin(), v.end(), rComp);

    ifd {
        cout<<"v, ordenado por (episodios, temporada) se ve: "<<endl;
        for(auto u:v) cout<<"("<<u.first<<" "<<u.second<<"), ";
        cout<<endl;
    }
    ll ans =0;
    ordered_set os;
    ll cNEp=0;
    for (ii x:v) {
        int season=x.second, ep=x.first;
        // usted quiere cuanta gente hay con una season < su num episodios+1
        int r=os.order_of_key(ep+1);
        // usted quiere saber cuanta gente hay con una season < su season
        int l = os.order_of_key(season);
        os.insert(season);
        ans +=r-l;
    }

    cout<<ans<<endl;

    
}
