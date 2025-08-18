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


ll raizQ(ll a) {
    long long x = sqrt(a) + 2;
    while (x * x > a) x--;

    return x;
}


int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll r, x1, y1, x2, y2;
    cin>>r>>x1>>y1>>x2>>y2;

    ll d = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    if (d == 0) {
        cout<<0<<"\n";
        return 0;
    }
    if (d%(4LL*r*r)==0) {
        ifd cout<<"d cuadrado = "<<d<<" y r cuadr = "<<r<<endl;
        ll k = raizQ(d/(r*r));
    
        if(k%2){
            cout<<1<<"\n";
        }else cout<<l/(2*r)+1<<"\n";
        return 0;

    }

    if (d==4LL*r*r) {
        cout<<1<<"\n";
        return 0;
    }
    
    if (d<9LL*r*r) {
        ifd cout<<"hue"<<endl;
        cout<<2<<"\n";
        return 0;
    }
    d = raizQ(d);
    
    ll pasos = (d-r)/(2LL*r);
    // if (d -r  - 2LL*r*pasos == 0 ) pasos++;
   
    // else pasos += 2LL
    ifd cout<<"holi"<<endl;
    ifd cout<<d<<" "<<pasos<<endl;
    cout<<pasos+2<<"\n";

    return 0;
}
