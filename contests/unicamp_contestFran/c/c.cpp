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

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; cin>>n;
    set<ii> st;
    forn(i, n) {
        int x; cin>>x;
        if (x) st.insert({-x, i});
    }
    ifd for(auto u:st) cout<<u.first<<" "<<u.second<<endl;
    ifd cout<<"holi"<<endl;
    bool won=(st.size()!=1);
    stack<ii> ans;
    while (!st.empty() and won) {
        
        ii a=*(st.begin());
        st.erase(a);
        int ax=a.first, ai=a.second;
        ii b=*(st.begin());
        st.erase(b);
        int bx=b.first, bi=b.second;
        ifd cout<<"saco "<<ai<<" y "<<bi<<endl;
        ans.push({ai+1, bi+1});
        ax++, bx++;
        if (ax) st.insert({ax, ai});
        if (bx) st.insert({bx, bi});
        if (st.size()==1) won=false;
    }
    if (!won) cout<<"no\n";
    else {
        cout<<"yes\n";
        while (!ans.empty()) {
            ii x=ans.top();
            ans.pop();
            cout<<x.first<<" "<<x.second<<"\n";
        }
    }


}
