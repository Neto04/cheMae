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
    int tC; cin>>tC;
    int tN=1;
    while (tC--) {
        ifd cout<<"CASO "<<tN++<<endl;
        int n; cin>>n;

        set<ii> xS, yS, zS;
        vector<ll> xV, yV, zV;
        int nAdd=0;
        forn(i,n) {
            string op; cin>>op;
            if (op=="ADD") {
                int x, y, z;
                cin>>x>>y>>z;
                xS.insert({x, nAdd});
                ifd cout<<"yo leo "<<x<<", "<<nAdd<<endl;
                xV.push_back(x);
                yS.insert({y, nAdd});
                yV.push_back(y);
                zS.insert({z, nAdd});
                zV.push_back(z);
                nAdd++;
            }
            else {
                int k; cin>>k; k--;
                ifd cout<<"yo saco al "<<k<<"-esimo mae"<<endl;
                ifd cout<<"antes xS = "<<xS.size()<<endl;
                ll xC = xV[k];
                ifd cout<<"vea que ese es "<<xC<<", "<<k<<endl;
                xS.erase({xC, k});
               ifd cout<<"ahora xS = "<<xS.size()<<endl;

                ll yC = yV[k];
                yS.erase({yC, k});

                ll zC = zV[k];
                zS.erase({zC, k});
            }
            if (xS.size()==0) {
                cout<<"0\n";
                continue;
            }

            ll xMin = (*xS.begin()).first;
            auto xIt = xS.end();
            xIt--;
            ll xBig = (*xIt).first;
            ll xD = xBig-xMin;
            ifd cout<<"xD = "<<xD<<endl;
            ll yMin = (*yS.begin()).first;
            auto yIt = yS.end();
            yIt--;
            ll yBig = (*yIt).first;
            ll yD = yBig-yMin;
            ifd cout<<"yD = "<<yD<<endl;


            ll zMin = (*zS.begin()).first;
            auto zIt = zS.end();
            zIt--;
            ll zBig = (*zIt).first;
            ll zD = zBig-zMin;
            ifd cout<<"zD = "<<zD<<endl;


            ll ans = xD*yD * 2 + xD*zD*2 + yD*zD*2;
            cout<<ans<<"\n";
        }
    }





}
