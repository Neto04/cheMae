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

int p;
int cien = 0, uno = 0, cero = 0, otro = 0;
vector<pair<string,int>> lugares(p);
double minimo = 0.50, maximo = 1.49;
double suma = 0.00;

void casosCien() {
    // Si hay 100 solo puede haber 1 o 0
    if (otro) {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    // Si hay 100 y 1
    if (cien and uno) {
        // Si hay mas de un 1 no se puede
        if (uno > 1) {
            cout<<"IMPOSSIBLE\n";
            return;
        }
        // Si no, 100 es 99.5 y 1 es 0.5
        for (auto& x : lugares) { 
            cout<<x.first<<" ";
            if (x.second == 100) cout<<95.50<<" "<<95.50<<"\n";
            else if (x.second == 1) cout<<0.50<<" "<<0.50<<"\n";
            else if (x.second == 0) cout<<0.00<<" "<<0.00<<"\n";
        }
        return;
    }
}

bool bajarMaximo() {
    while (minimo <= maximo) {
        double x = suma + maximo + (double)(p-1)*minimo;
        if (x > 100.00) {
            maximo -= (x - 100.00);
        } else {
            return true;
        }
    }
    return false;
}

bool subirMinimo() {
    while (minimo <= maximo) {
        double x = suma + minimo + (double)(p-1)*maximo;
        if (x < 100.00) {
            minimo += (100.00-x);
        } else {
            return true;
        }
    }
    return false;
}

void solve(double minimoOG, double maximoOG) {
    if (suma + (double)p * maximo < 100.00) {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    if (suma + (double)p * minimo > 100.00) {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    

    
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    for (auto& x : lugares) {
        cin>>x.first>>x.second;

        if (x.second == 100) cien++;
        else if (x.second == 1) uno++;
        else if (x.second == 0) cero++;
        else otro++;
    }

    if (cien) {
        casosCien();
        return 0;
    }

    for (auto& x : lugares) {
        if (x.second == 0) {
            minimo = 0.0;
            maximo = 0.5;
        } else {
            suma += (double)x.second;
        }
    }

    for (auto& x : lugares) {
        cout<<x.first<<" "<<minimo<<" "<<maximo<<"\n";
    }

    return 0;
}

/*
    int n; cin>>n;
    double res1=0.0, res2=0.0;
    double x, y; 
    forn(i, n) {
        cin>>x>>y;
        res1+=x;
        res2+=y;
    }
    cout<<res1<<", "<<res2<<endl;
    double a = 0.97*3;
    cout<<a+97.08<<endl;
*/