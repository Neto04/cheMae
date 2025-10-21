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
ll target;
bool check(double c) {
    double intR= (int) c;
    double x = intR;
    double y =1;
    ll count =0;
    ifd cout<<"checking radio = "<<c<<endl;
    while (y<=intR and x>0) {
        while (x*x+y*y>c*c and x>0) x--;
        count+=x;
        y++;
    }
    count*=4;
    return count>target;


}




double search() {
    double a = 0.000001, b = 1e9+7;
    for(int i=1; i<=100; i++) {
        double c;
        if (b>2*a) c=sqrt(a*b);
        else c=(a+b)/2;
        if (check(c)) {
            ifd cout<<"sirve!!"<<endl;
            b = c;
        }
        else a=c;
    }
    return a;
}




int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>target;
    cout<<setprecision(6)<<fixed;
    cout<<search()<<endl;


}
