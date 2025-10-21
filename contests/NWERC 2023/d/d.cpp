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
    cout<<setprecision(7)<<fixed;
    vector<string> cal(7);
    forn(i, 7) cin>>cal[i];
    double d, h; cin>>d>>h;
    vector<double> probs;
    double ans =0;
    for(int msk=0; msk<128; msk++) {
        double nD = __builtin_popcount(msk);
        vector<double> probs;
        if (nD!=d) continue;
        ifd cout<<"checking "<<msk<<endl;
        for(int cH =0; cH<24; cH++) {
            double cProb =0;
            for(int cD =0; cD<7; cD++) {
                // si ud no esta entre los dias he elegido ahorita, continue
                if (!(msk & (1<<(6-cD)))) continue;
                if (cal[cD][cH]=='.') {
                    ifd cout<<"vea que el dia "<<cD<<" esta libre a la hora "<<cH<<endl;
                    cProb++;
                }
            }
            ifd cout<<"vea que si elijo la hora "<<cH<<", me sirve para "<<cProb<<" dias"<<endl;
            probs.push_back(-(cProb/(nD*h)));
        }

        sort(probs.begin(), probs.end());
        if (probs.size()<h) continue;
        double cAns =0;
        forn(i, h) cAns +=(-probs[i]);
        ans = max(ans, cAns);
    }

    cout<<ans<<endl;
}
