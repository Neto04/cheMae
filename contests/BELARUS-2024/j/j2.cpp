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

double f(int n) {
    double nn = n;    
    return (nn-2);
}


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int tC; cin>>tC;
    cout<<tC<<endl;
    while (tC--) {  
        // OJO: SIEMPRE VA A TOMAR EL AREA * 2
        int n, s; cin>>n;
        cin>>s;
        s;


        cout<<n<<"\n";
        // if (f(n)>s) {
        //     cout<<"NO\n";
        //     continue;
        // }
        // cout<<"YES\n";
        
        
        // TODO: FALTA METER CÓMO AÑADIR EL ULTIMO PUNTO
        if (n==3) {
            cout<<"0 0\n0 1\n"<<s<<" 0\n";
            continue;
        }


        
        int x =1;
        vector<ii> up={{0, 1}}, down={{0, 0}, {1, 1}};
        // mientras todavía sobre al menos un mae
        forn(i, n-4) {
            if(i%4==0) up.push_back({x, 2});
            
            
            if (i%4==1) up.push_back({x, 1});
            
            if (i%4==2) down.push_back({x, 0});
            if (i%4==3) down.push_back({x, 1});

            if (i%2==0) x++; 
        }
        int cong=(n-4)%4;
        int xMas =0, yMas=0;
        if (cong==0) up.push_back({x, 1+(s-n+3)});
        if (cong==1) up.push_back({x-1+(s-n+3), 1});
        if (cong==2) {
            ifd cout<<"cong = 2"<<endl;
            int res =1-(s-n+3);
            ifd cout<<"res = "<<res<<endl;
            if (res<0) yMas=abs(res);
            ifd cout<<"yMas = "<<yMas<<endl;
            for(ii& u:up) u.second+=yMas;
            for(ii& u:down) u.second+=yMas;
            down.push_back({x, 0});
        }
        if (cong==3) down.push_back({x-1+(s-n+3), 1});

        reverse(down.begin(), down.end());
        vector<ii> ans;
        for(auto u:up) ans.push_back(u);
        for(auto u:down) ans.push_back(u);
        for(auto u:ans) cout<<u.first<<" "<<u.second<<endl;





    }


}
