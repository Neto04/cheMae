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

    int tC; cin>>tC;
    while (tC--) {
        int n, m; cin>>n>>m;

        ll e1; cout<<"SCAN 1 1"<<endl; cin>>e1;
        ll e2; cout<<"SCAN 1 "<<m<<endl; cin>>e2;

        // e1 = x1 + x2 + y1 + y2 - 4
        // e2 = x1 + x2 - y1 - y2 + 2m - 2
        e1 += 4, e2 += (-2*m+2);
        ll sumaX = (e1+e2)/2;
        ll sumaY = (e1-e2)/2;
    
        ll e3; cout<<"SCAN "<<sumaX/2<<" "<<1<<endl; cin>>e3;
        ll e4; cout<<"SCAN "<<1<<" "<<sumaY/2<<endl; cin>>e4;

        // e3 = |x1 - x2| + y1 + y2 - 2
        // e4 = |y1 - y2| + x1 + x2 - 2
        ll x1 = (e3+sumaX-sumaY+2)/2;
        ll x2 = sumaX-x1;
        ll y1 = (e4+sumaY-sumaX+2)/2;
        ll y2 = sumaY-y1;

        cout<<"DIG "<<x1<<" "<<y1<<endl;
        bool ans; cin>>ans;
        if (ans) {
            cout<<"DIG "<<x2<<" "<<y2<<endl;
            cin>>ans;
        } else {
            cout<<"DIG "<<x1<<" "<<y2<<endl;
            cin>>ans;
            cout<<"DIG "<<x2<<" "<<y1<<endl;
            cin>>ans;
        }
    }

    return 0;
}
