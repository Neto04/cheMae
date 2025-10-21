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
    vector<int> freq(101);
    set<int> st;


    forn(i, 4) {
        int x; cin>>x;
        freq[x]++;
        st.insert(x);
    }


    int b; cin>>b;
    int ans;
    if (st.size()>2) ans=0;
    else if (st.size()==1) ans=1;
    else {
        vector<int> v;
        for(auto u:st) v.push_back(u);
        if (freq[v[0]]>1) ans=0;
        else ans =( (v[0] + b) == v[1]);
    }

    cout<<ans<<endl;


}
