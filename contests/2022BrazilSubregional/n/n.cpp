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

#define debug 0
#define ifd if (debug)

bool rComp(ll a, ll b) {
    return a>b;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vector<ll> a(n), b(n);
    forn(i, n) cin>>a[i];
    forn(i, n ) cin>>b[i];
    ll k, l; cin>>k>>l;

    vector<ll> oG;
    ll sU=0, sD=0;
    forn(i, k) {
        oG.push_back(b[i]);
        sU+=a[i];
    }

    ll lW=0, rW=k-1;
    sort(oG.begin(), oG.end(), rComp);
    ll indx=0;
    ifd {
        cout<<"oG se ve: "<<endl;
        for(auto u:oG) cout<<u<<" ";
        cout<<endl;
    }
    set<ii> lMax, resto;
    forn(i, l) {
        lMax.insert({oG[i], indx++});
        sD+=oG[i];
    }

    forr(i, l, k) resto.insert({-1*oG[i], indx++});

    ll ans =sU+sD;
    forn(i, k) {
        // meta el mae en la posicion lW
        lW=((lW-1)%n+n)%n;
        ifd cout<<"meto al mae en "<<lW<<" que vale "<<b[lW]<<endl;
        sU+=a[lW];
        auto minLM=lMax.begin();
        ll mLX, mLY; tie(mLX, mLY)=*minLM;
        if (b[lW]>(mLX)) {
            ifd cout<<"vea que es mayor al min de los grandes, entonces paso "<<(*minLM).first<<" a resto"<<endl;
            resto.insert({-1*mLX, mLY});
            lMax.erase(minLM);
            lMax.insert({b[lW], indx++});
            sD+=b[lW];
            sD-=mLX;
        } else {
            ifd cout<<"efe, ese mae va a resto"<<endl;
            resto.insert({-1*b[lW], indx++});
        }


        // ahora saque al mae en la posicion rW
        ifd cout<<"ahora saco al mae en "<<rW<<" que abajo vale "<<b[rW]<<endl;
        sU-=a[rW];
        ll cV=b[rW];
        // DOS CASOS: el mae estaba en resto, o el mae estaba en lMax

        // si estaba en resto 
        auto u = resto.lower_bound({-1*cV, -1}); 
        if (u!=resto.end()&&(*u).first==-1*cV) {
            resto.erase(u);
            ifd cout<<"ese valor estaba en resto, lo quito"<<endl;
        }


        // si NO estaba en resto:
        else {
            ifd cout<<"efe, no estaba en resto, entonces lo saco de lMax"<<endl;
            auto w = lMax.lower_bound({cV, -1});
            lMax.erase(w);
            sD-=cV;

            if (!resto.empty()) {
                ii uu = *(resto.begin());
                ifd cout<<"meto "<<-1*uu.first<<endl;
                resto.erase(uu);
                lMax.insert({uu.first*-1, uu.second});
                sD+=uu.first*-1;
            }
        }
        rW=((rW-1)%n+n)%n;
        ifd cout<<"de donde la suma de arriba ahora es "<<sU<<" y la de abajo "<<sD<<endl;
        ans = max (ans, sU+sD);
        ifd cout<<"ans ahorita es "<<ans<<endl;

    }


    cout<<ans<<endl;




}
