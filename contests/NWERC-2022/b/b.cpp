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

double h, r, dA, dW;
// xW la altura del agua
double f(double xW) {
    double num = (h+xW)*(h-xW)*dA + xW*xW*dW;
    double denum = (h-xW)*dA+dW*xW;
    return num/(2*denum);

}

double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        // 
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>h>>r>>dA>>dW;
    cout<<setprecision(6)<<fixed;
    cout<<ternary_search(0.000001, h)<<endl;
}
