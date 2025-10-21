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


const ll maxn = 60;
ll C[maxn + 1][maxn + 1];
#define debug 0
#define ifd if (debug)



// usted tiene n maes, ocupa agarrar k de ellos
ll n, k;
// el peso de cada mae
vector<ll> weight;


ll choose (ll a, ll b) {
    if (a<b) return 0;
    return C[a][b];
}

// le tira cuantas formas hay de agarrar *exactamente* k maes tq la suma de todos es a lo sumo peso
ll combi(ll peso) {
    ifd cout<<"COMBI DE "<<peso<<endl;
    ll cPeso =peso;
    ll kk=k;
    ll indx=n-1;
    ll ans = 0;
    while (indx>=0 and kk>=0 and cPeso>=0) {
        // si ya no tiene que poner nada más, y todo lo que puso era legal, termine
        if (kk==0) {
            ans ++;
            break;

        }
        // transforme indx en el min mae tq puede agarrar 
        if (weight[indx]>cPeso) {
            indx--;
            continue;
        }
        
        ifd cout<<"ahorita indx = "<<indx<<", cPeso = "<<cPeso<<", kk = "<<kk<<endl;
        // vea que puede solo agarrar a ese mae, y ya
        // if (kk==1) {
        //     ifd cout<<"vea que puedo quedarme con ese mae y ya"<<endl;
        //     ans++;
        // }
        // si ya no queda suficiente gente para armar currentK maes, pare
        if (indx+1<kk) {
            ifd cout<<"f, no me queda para agarrar "<<kk<<" maes "<<endl;
            break;
        }
        
        // si ya solo le queda agarrar todos los que hay, intente coger todos, pare
        if (indx+1==kk) {
            ll check=0;
            forn(i, indx+1) check+=weight[i];
            ifd cout<<"si agarro todos los que hay, eso me da"<<check<<", compare con "<<cPeso<<endl;
            ans+=(check<=cPeso);
            break;
        }
        
        ans +=choose(indx, kk);
        ifd cout<<"coger todos menos a "<<indx<<", me da "<<choose(indx, kk)<<endl;
        kk--;
        cPeso-=weight[indx];

        indx--;
        ifd cout<<"de donde, ans = "<<ans<<endl;
    }
    // if (cPeso ==0) ans++;
    // ifd cout<<"COMBI DE "<<peso<<" = "<<ans<<endl;
    return ans;
}



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    
    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }


    cin>>n>>k;
    weight.resize(n);
    forn(i,n) cin>>weight[i];
    sort(weight.begin(), weight.end());

    ifd {
        cout<<"los pesos ordenados son "<<endl;
        forn(i, n) cout<<weight[i]<<" ";
        cout<<endl;
    }
    ll a, b; cin>>a>>b;

    ll ans = combi(b)-combi(a-1);
    cout<<ans<<endl;
}
