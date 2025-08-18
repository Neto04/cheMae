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

double p, r, y;

bool check(double sigma, double maxi, double mini) {
    double sigma2 = r - maxi + mini - sigma;
    if (maxi - sigma >= mini + sigma2) return true;
    return false;
}

double search(double maxi, double mini) {
    double a=0.000001, b=1e18;
    for(int i=1; i<=100; i++) {
        double sigma;
        if (b>2*a) sigma=sqrt(a*b);
        else sigma=(a+b)/2;
        if (check(sigma, maxi, mini)) a=sigma;
        else b=sigma;
    }
    return a;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cout<<setprecision(6)<<fixed;

    int q; cin>>q;
    while (q--) {
        string dummy;
        cin>>dummy; p = stod(dummy);
        cin>>dummy; r = stod(dummy);
        cin>>dummy; y = stod(dummy);

        double A = (p+r+y)/4.0, B = (-p-r+y)/4.0;
        ifd cout<<"A = "<<A<<", B="<<B<<endl;
        double eps1, eps2, n, e, s, w;

        if (abs(A) >= abs(B)) {
            eps1 = search(abs(A), abs(B));
            if (A < 0) eps1 *= -1.0;
            eps2 = r - A + B - eps1;
        } else {
            eps2 = search(abs(B), abs(A));
            if (B < 0) eps2 *= -1.0;
            eps1 = r - A + B - eps2;
        }
        ifd cout<<"eps1 = "<<eps1<<", eps2 = "<<eps2<<endl;
        n = A + eps1, e = A - eps1, w = B + eps2, s = B - eps2;
        cout<<n<<" "<<e<<" "<<s<<" "<<w<<"\n";
    }

    return 0;
}
