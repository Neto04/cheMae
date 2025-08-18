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

int n, m; 

struct punto {
    ll value;
    int id;
    bool abre;
};
bool comp(punto p1, punto p2) {
    if (p1.value==p2.value) return p1.id<p2.id;
    return p1.value<p2.value;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    vector<ii> isl(n);
    forn(i,n) cin>>isl[i].first>>isl[i].second;
    
    vector<punto> recta;

    vector<ii> par(n);
    forn(i, n-1) {
        ll I=isl[i+1].first-isl[i].second;
        recta.push_back({I, i, 1});
        ll F=isl[i+1].second-isl[i].first;
        recta.push_back({F, i, 0});
        par[i]={I, F};
    }
    sort(recta.begin(), recta.end(), comp);


    set<ii> as;
    forn(i,m ) {
        ll x;
        cin>>x;
        as.insert({x, i});
    }
    bool error =false;
    vector<ll> ans(n);
    for(int i=0;i<recta.size()&&!error; i++) {
        // si es un cierre
        if (!recta[i].abre) {
            // busque el punto que lo abre
            punto g=recta[i];
            ll I = par[g.id].first;

            auto u=as.lower_bound({I, -1});

            if (u==as.end()||((*u).first>g.value)) {
                error=true;
                continue;
            }
            ans[g.id]=(*u).second+1;
            
            as.erase(u);
        }
    }

    if (error) cout<<"No"<<endl;
    else {
        cout<<"Yes"<<endl;
        for(auto a:ans) if (a>0) cout<<a<<" ";

        cout<<endl;
    }




    
}
