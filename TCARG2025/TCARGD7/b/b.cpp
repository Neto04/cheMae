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
const ll INF = 1e14;
#define debug 1
#define ifd if (debug)

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int tC; cin>>tC; 
    while (tC--) {
        int n; cin>>n;
        vector<vector<ll>> v(n, vector<ll> (n));
        forn(i,n) forn(j,n) cin>>v[i][j];
        int med=n/2;
        // ans[0]=ponerlo en el centro
        // ans[1]=poner izq y der
        // ans[2]=poner arr y abajo
        vector<ll> ans(3);
        bool izq=0, der=0;
        // PONER CENTRO
        ans[0] = v[med][med];
        ifd cout<<"poner centro cuesta "<<ans[0]<<endl;
        // PONER ARRIBA Y LUEGO ABAJO
        // poner centro arriba
        ll op1=INF;
        forr(i, 0, med) op1=min(op1, v[i][med]);
        ifd cout<<"poner centro arriba = "<<op1<<endl;
        // poner arriba izq
        ll op21=INF;
        forr(i, 0, med) forr(j, 0, med) op21=min(op21,v[i][j]);
        ifd cout<<"poner arriba izq = "<<op21<<endl;
        // poenr arriba der
        ll op22=INF;
        forr(i, 0, med) forr(j, med+1, n) op22 = min(op22, v[i][j]);
        ifd cout<<"poner arriba der "<<op22<<endl;
        ans[1]+=min(op1, op21+op22);

        // poner abajo centro
        op1=INF;
        forr(i, med+1, n) op1=min(op1, v[i][med]);
        ifd cout<<"poner abajo centro "<<op1<<endl;
        // poner abajo izq
        op21=INF;
        forr(i, med+1, n) forr(j, 0, med) op21=min(op21, v[i][j]);
        ifd cout<<"poner abajo izq"<<op21<<endl;
        // poner abajo der
        op22=INF;
        forr(i, med+1, n) forr(j, med+1, n) op22=min(op22, v[i][j]);
        ifd cout<<"poner abajo der "<<op22<<endl;
        ans[1]+=min(op1, op22+op21);



        // PONER IZQ Y LUEGO DER
        // poner izq centro;
        op1=INF;
        forr(j, 0, med) op1=min(op1, v[med][j]);

        // poner izq arriba 
        op21=INF;
        forr(i, 0, med) forr(j, 0, med) op21=min(op21,v[i][j]);

        // poner izq abajo
        op22=INF;
        forr(i, med+1, n) forr(j, 0, med) op22=min(op22, v[i][j]);
        ans[2]+=min(op1, op21+op22);



        // poner der centro
        op1=INF;
        forr(j, med+1, n) op1=min(op1, v[med][j]);
        // poner der arriba
        op21=INF;
        forr(i, 0, med) forr(j, med+1, n) op21 = min(op21, v[i][j]);
        // poner der abajo
        op22=INF;
        forr(i, med+1, n) forr(j, med+1, n) op22=min(op22, v[i][j]);
        ans[2]+=min(op1, op22+op21);

        cout<<min(ans[0], min(ans[1], ans[2]))<<"\n";


    }   

}
