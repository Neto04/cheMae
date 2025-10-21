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

bool sComp(ii a, ii b) {
    return a.second<b.second;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, s,d;
    cin>>n>>m>>s>>d;
    vector<ii> v(s);
    vector<int> v2(s);
    forn(i, s) {
        int x; cin>>x;
        v[i]={x, i};
        v2[i]=x;
    }
    
    sort(v.begin(), v.end());
    int indx=s-1;
    while (m>0 and indx>=0) {
        m-=v[indx].first;
        indx--;
        ifd cout<<"m = "<<m<<" index "<<indx<<endl;
    }
    int nIndx=0;
    while (n>0) {
        if (n-(d-v[nIndx].first)>=0) {
            n-=(d-v[nIndx].first);
            v[nIndx].first=d;
        }
        else {
            v[nIndx].first+=n;
            n=0;
        }
        nIndx++;
        ifd cout<<"n = "<<n<<endl;
    }
    nIndx--;
    if (nIndx>indx) cout<<"impossible"<<endl;

    else {
        sort(v.begin(), v.end(), sComp);
    
        ll ans =0;
        for(int i=0; i<s; i++) {
            cout<<abs(v2[i]-v[i].first)<<" ";
        }

        
        cout<<endl;

    }
    


}
