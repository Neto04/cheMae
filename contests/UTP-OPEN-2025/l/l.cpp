#include <bits/stdc++.h>
#define ll long long
using namespace std; 
#define ii pair<ll, ll> 

#define debug 0
#define ifd if(debug)
#define MAX 1e6+5
#define forr(i, a, b) for(int i=a; i<b; i++)
#define forn(i,b) forr(i, 0, b)
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<std::pair<long long, long long>, null_type, less<std::pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update>


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int q; cin>>q;
    ll tGente=0;

    vector<ll> freq(MAX);
    
    ordered_set oS;
    int cN=0;
    int x;
    while (q--) {
        int op; cin>>op;

        if (op==1) {
            cin>>x;
            oS.insert({x, cN++});
        }

        else if (op==2) {
            cin>>x;
            if (oS.size()) {
                
                auto u = oS.lower_bound({x, -1});
                if (u==oS.end()) continue;
                if ((*u).first==x) oS.erase(u);
            }
        }

        else if (op==3) {
            if (oS.size()==0) {
                cout<<"Empty!\n";
                continue;
            }

            const int x = oS.size();
            auto x1 = oS.find_by_order(x/2);
            if (x%2) {
                cout<<(*x1).first<<"\n";
                
            }
            else {
                auto x2 = oS.find_by_order(x/2-1);
                ll ans = ((*x1).first+(*x2).first)/2;
                cout<<ans<<endl;
            }
        
        }


    }

}
