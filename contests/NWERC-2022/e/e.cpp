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
int a, b;
ll maxGauss(int x) {
    for(int i=1; i<=x; i++) {
        int xx=x;
        if ((i*(i+1))/2 >x) return i-1;
    }

    return -1;
}



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a, b; char kk; cin>>a>>kk>>b;
    if (a<b and a!=b-1) cout<<"IMPOSSIBLE"<<endl;
    else if (a==b and b==1) {
        cout<<"3 2\n1 2\n2 3"<<endl;
    }
    else {
        if (b==1) b*=(2*a+1);
        if (a==b-1 or b== 2*a+1) {
            cout<<b<<" "<<b-1<<endl;
            forr(i, 1, b) cout<<i<<" "<<i+1<<endl;
            return 0;
        }


        if (a>((b-1)*b)/2) {
            ll x=(b+2*a)/(b*b)+2;
            a*=x, b*=x;
        }
        ifd cout<<"a= "<<a<<" b = "<<b<<endl; 
        ll g = maxGauss(a);
        ifd cout<<"g = "<<g<<endl;

        vector<int> niv(g+2, 1); 
        vector<int> first(g+1);
        while (g>1) {
            while (a>=g+1) {
                a-=(g);
                niv[g+1]++;
            }
            ifd cout<<"niv de "<<g+1<<" = "<<niv[g+1]<<endl;
            g--;
        }


        cout<<b<<" "<<b-1<<endl;
        int curr =1;
        int last=1;
        forr(i,1, g+2) {
            forn(j, niv[i]) cout<<last<<" "<<++curr<<endl;
            last=curr;
        }
    }

}
