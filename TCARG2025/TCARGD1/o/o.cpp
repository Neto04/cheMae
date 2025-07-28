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
const ll INF =1e9;
// para cada bit, cuales index lo tienen como maxBit
vector<vector<int>> posBit(33);

vector<ll> v;
int n;
ll xOg;

vector<ll> pXor;

queue<ll> fAns;
ll score(int i, ll x) {
    ifd cout<<"calculando score de index "<<i<<" valor "<<x<<endl;
    if (i==n-1||x==0) return 0;
    ll mSi=0;  while ((1<<(mSi+1))<=x) mSi++;
    ifd cout<<"el mSi = "<<mSi<<endl;
    // (pos del mas cerc, bit mas sig)
    ii closAns={INF, INF};
    
    // revise para cada valor de bit >ud, cuál es el primer mae > su pos
    for(int j=mSi; j<=32; j++)  {
        if (posBit[j].empty()) continue;
        // busque el min mae con un index > al suyo
        auto u=upper_bound(posBit[j].begin(), posBit[j].end(), i);
        // si no tiene a nadie >su index, siga con su vida
        if (u==posBit[j].end()) continue;
        // pos del primer mae con index >=suyo
        int pos=*u;
        // si esa pos esta mas cerquita, coja esa pos
        if (pos<closAns.first) {
            closAns={pos, j};
        }
    }
    ifd cout<<"vea que el mas cercano a ud esta en "<<closAns.first<<endl;
    if (closAns.first==INF) {
        ifd cout<<"de donde la respuesta es todos los que hay en frente suyo, = "<<n-1-((i>-1)?i:0)+ (i==-1)<<endl;
        return n-1-((i>-1)?i:0) + (i==-1);
    }
    ll ans =0;
    ifd cout<<"vea que closAns = "<<closAns.first<<" e i = "<<i<<endl;
    if (closAns.first != i+1) {
        ans=closAns.first-i-1;
        ifd cout<<"me como hasta closAns-1 y eso son "<<ans<<" maes "<<endl;
        if (i>-1) x=xOg;
        x=x^(pXor[closAns.first-1]);
    }
    // si ya no puede comer, stop
    if (v[closAns.first]>x) {
        ifd cout<<"opa, vea uqe "<<v[closAns.first]<<"> "<<x<<endl;
        return ans;
    }
    
    ans++;
    ifd cout<<"se lo come, su score ahora es "<<ans<<", y sigue en "<<closAns.first<<endl;
    // si sigue pudiendo, coma, y siga
    x=(x^v[closAns.first]);
    
    ans+=score(closAns.first, x);
    return ans;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int tC; cin>>tC;
    int tN=1;
    while (tC--) {
        ifd cout<<"CASO "<<tN++<<endl;
        int q;
        cin>>n>>q;
        forn(i,33) posBit[i].resize(0);
        ifd cout<<"n = "<<n<<" q = "<<q;
        v.resize(n); pXor.resize(n);
        forn(i, n) cin>>v[i];
        reverse(v.begin(), v.end());
        ifd{
            cout<<"v:"<<endl;
            forn(i, n) cout<<v[i]<<" ";
            cout<<endl;
        } 
        pXor[0]=v[0];
        ifd cout<<"pXor:"<<endl;
        forr(i,1, n) {
            pXor[i]=(v[i]^pXor[i-1]);
            
        }
        ifd forn(i, n) cout<<pXor[i]<<" ";
        ifd cout<<endl;
        
        forn(i, n) {
            int cI=0;
            while ((1<<(cI+1))<=v[i]) cI++;
            posBit[cI].push_back(i);
        }


        forn(i, q) {
            cin>>xOg;
            ifd cout<<"RESPUESTA PARA QUERY "<<i<<endl;
            fAns.push(score(-1, xOg));
        }

        while (!fAns.empty()) {
            cout<<fAns.front()<<" ";
            fAns.pop();
        }
        cout<<"\n";

    }

}
