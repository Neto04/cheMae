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
ll a, b;
int gauss(int x) {
    return (x*(x+1))/2;
}
ll maxGauss() {
    for(int x=b; x>=0; x--) 
        if (gauss(x-1)+b-x<a) return x;
        return -1;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    char kk; 
    cin>>a>>kk>>b;
    if (a<b) {
        if (a!=b-1) cout<<"impossible"<<endl;
        else {
            cout<<b<<" "<<b-1<<endl;
            for(int i=2; i<=b; i++) cout<<1<<" "<<i<<endl;
        }
    }
    else if (a==b and b==1) cout<<"3 2\n1 2\n2 3"<<endl;
    
    else {

        // TODO: qué pasa si uno (o los dos) son 1?
        if (a>((b-1)*b)/2) {
            ll x=(b+2*a)/(b*b)+2;
            a*=x, b*=x;
        }
        ifd cout<<"a = "<<a<<", b = "<<b<<endl;
        // usted quiere dejar x nodos en total
        ll x = maxGauss();
        ifd cout<<"yo voy a dejar "<<x<<" columnas/niveles en total, que tiene gauss "<<gauss(x-1)<<endl;
        // niv[i] es la cantidad de gente que hay a distancia i
        vector<ll> niv(x+1, 1);
        ll sb=(b-x);
        ll sa=a-gauss(x-1)-b+x;
        niv[1]+=(b-x);
        while (sa>0) {
            sa++; niv[1]--;
            if (sa>x-1) {
                niv[x-1]++;
                sa-=(x-1);
            }
            else {
                niv[sa]++;
                sa=0;
            }
        }
        int cSuma=0;
        ifd {
            forn(i, x) {
                cout<<"en nivel "<<i<<" hay "<<niv[i]<<" maes"<<endl;
                cSuma+=i*niv[i];
            }
            ifd cout<<"de donde en total la suma de distancias es "<<cSuma<<endl;
        }
        cout<<b<<" "<<b-1<<endl;
        int curr =1;
        int last=1;
        forr(i,1, x) {
            forn(j, niv[i]) cout<<last<<" "<<++curr<<endl;
            last=curr;
        }

    }






}
