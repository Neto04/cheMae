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
int minSz=1e9+7, maxSz=-1;
vector<ii> v;
int n;
bool dist(int a, int b, int target) {
    return (b-a+1)>=target;
}

bool check (int target){
    
    queue<ii> sirven;
    int cA, cB, oA, oB;
    forn(i, n) {
        cA=v[i].first; cB=v[i].second;
        // si usted no cumple, olvídese de toda la gente de antes
        if (!dist(cA, cB, target)) {
            while (!sirven.empty()) sirven.pop();
            continue;
        }
        // si hasta ahora nada cumple, basta con ver que el current pair sirva
        if (sirven.empty()) {
            if (dist(cA, cB, target)) {
                sirven.push({cA, cB});
                // por aquello de que target = 1
                if (sirven.size()==target) return true;
            }
            continue;
        }
        // si algo ya cumplía revise a partir de qué algo usted cumple respecto a ese algo
        oA=sirven.front().first; oB=sirven.front().second;
        // saque todos los algos que cumplían con los que usted no cumple
        while (!dist(max(oA, cA), min(oB, cB), target)) {
            sirven.pop();
            if (sirven.empty()) break;
            oA=sirven.front().first; oB=sirven.front().second;
        }
        // métase usted
        sirven.push({cA, cB});
        if (sirven.size()>=target) return true;
    }
    return false;
}
ll search() {
    ll a =minSz, b=maxSz, ans;
    while (a<=b) {
        ll c = a+(b-a)/2;
        if (check(c)) {
            ans =c;
            a=c+1;
        }
        else b=c-1;
    }
    return ans;
}


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n; v.resize(n);
    forn(i,n) {
        int a,b; cin>>a>>b;
        v[i]={a, b};
        minSz=min(minSz, b-a+1);
        maxSz=max(maxSz, b-a+1);
    }
    ifd cout<<"vea que minSz = "<<minSz<<", y maxSz = "<<maxSz<<endl;
    cout<<search()<<endl;


}
