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
const int SIZE = 1e6+5;
#define debug 0
#define ifd if (debug)


double target,a, b, m;
vector<double> E;
vector<double> pSum;
double rSum(int l, int r) {
    ifd cout<<"rSum de "<<l<<", "<<r<<endl;
    if (l<0) l=0;
    double ans = pSum[r];
    if (l>0) ans-=pSum[l-1];
    ifd cout<<ans<<endl;
    return ans;
}



double esp1(int n) {
    double ans = m/(m-1) + (rSum(n-b, n-1))/(m-1);
    return ans;
}

double esp2(int n) {
    return 1 + (rSum(n-b, n-a))/m;
}  

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>target>>a>>b;
    E.resize(SIZE);
    pSum.resize(SIZE);
    m = b-a+1;
    forr(i, 1, a+1) {
        E[i]=1;
        pSum[i]=pSum[i-1]+E[i];
    }

    cout<<setprecision(6)<<fixed;
    for(int i = a+1; i<= target; i++) {
        if (a==0) E[i]=esp1(i);
        else E[i]=esp2(i);
        pSum[i] = E[i]+pSum[i-1];
    }

    ifd {
        cout<<"E:"<<endl;
        forn(i, target) cout<<E[i]<<" ";
        cout<<endl;
    }
    
    cout<<E[target]<<endl;
}
