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

const int N = 1e3+5;
const double eps = 0.00001;
long double x, y;
int n;

vector<pair<double,double>> pts(N);

struct datos {
    // left, right, up, down
    double l, r, u, d;
};

int link[N];
datos cosas[N];

int find(int current) {
    while (current != link[current]) current = link[current];
    return current;
}

bool same(int a, int b, double r) {
    pair<double,double> p1 = pts[a], p2 = pts[b];
    double v1 = (p1.first-p2.first)*(p1.first-p2.first);
    double v2 = (p1.second-p2.second)*(p1.second-p2.second);
    r = r*r*4.0;
    return (v1+v2 < r)&&(r-v1-v2>eps);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    cosas[a].l = min(cosas[a].l, cosas[b].l);
    cosas[a].r = max(cosas[a].r, cosas[b].r);
    cosas[a].d = min(cosas[a].d, cosas[b].d);
    cosas[a].u = max(cosas[a].u, cosas[b].u);

    link[b] = a;
}

bool check(double radio) {
    ifd cout<<"pruebo con "<<radio<<endl;
    for (int i = 0; i < n; i++) {
        link[i] = i;
        cosas[i].l = pts[i].first-radio;
        cosas[i].r = pts[i].first+radio;
        cosas[i].u = pts[i].second+radio;
        cosas[i].d = pts[i].second-radio;
        ifd cout<<cosas[i].l<<" "<<cosas[i].r<<" "<<cosas[i].u<<" "<<cosas[i].d<<" "<<endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (same(i,j,radio)) unite(i,j);
        }
    }
    for (int i = 0; i < n; i++) {
        datos datillos = cosas[link[i]];
        ifd cout<<"vea que u, d, l, r = "<<datillos.u<<" "<<datillos.d<<" "<<datillos.l<<" "<<datillos.r<<endl;
        // Arriba y abajo
        if ((datillos.u > y and datillos.u-y>eps) and ((datillos.d < 0) and 0-datillos.d>eps)) return false;
        // Izq y abajo
        if ((datillos.l < 0 and 0-datillos.l>eps) and (datillos.d < 0 and 0-datillos.d>eps)) return false;
        // Izq y der
        if ((datillos.l < 0 and 0-datillos.l>eps) and (datillos.r > x and datillos.r-x>eps)) return false;
        // Arriba y der
        if ((datillos.u > y and datillos.u-y>eps) and (datillos.r > x and datillos.r-x>eps)) return false;
    }
    return true;
}


double search() {
    double a=eps, b = min(x, y);
    double ans;
    while (a<b&&(b-a)>eps) {
        double c=(b-a)/2 + a;
        if (check(c)) {
            ans = c;
            a=c+eps;
        }

        else b= c-eps;
    }

    return ans;
}


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>x>>y>>n;
    for (int i = 0; i < n; i++) {
        double a, b; cin>>a>>b;
        pts[i] = {a,b};
    }
    cout<<setprecision(6)<<fixed<<search()<<"\n";
    return 0;
}
