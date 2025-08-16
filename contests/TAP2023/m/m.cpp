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

const double epsilon = 0.0001;

void actualizar(priority_queue<double>& q, double paso, double denominador, double s, double& acumulado) {
    // Actualizar primer mae
    if (abs((-q.top()-acumulado)/s - paso) < epsilon) {
        acumulado += (-q.top()-acumulado);
        q.pop();
        // Limpiar la cola hasta encontrar el primer proceso sin terminar
        while (!q.empty()) {
            if (-q.top() <= acumulado) q.pop();
            else break;
        }
    } else {
        acumulado += paso*s;
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout<<setprecision(4)<<fixed;
    
    priority_queue<double> qN, qP;
    double sN, sP;
    double delN = 0, delP = 0;
    double pctN = 0.25, pctP = 0.75;
    double ans = 0.0;

    int n, T; cin>>n>>T;
    for (int i = 0; i < n; i++) {
        char tipo; double x; 
        cin>>tipo>>x;
        if (tipo == 'N') qN.push(-x);
        else qP.push(-x);
    }

    if (qP.empty()) pctN = 1.0;
    if (qN.empty()) pctP = 1.0;

    // Vaciar las dos hasta que alguna (o las dos) este vacia
    while (!qN.empty() and !qP.empty()) {
        sP = (pctP * T)/qP.size();
        sN = (pctN * T)/qN.size();

        ifd cout<<endl<<"Llevo "<<ans<<" segundos"<<endl;
        double paso1 = (-qP.top()-delP)/sP, denominador = sP;
        double paso2 = (-qN.top()-delN)/sN;
        if (paso2 < paso1) {
            ifd cout<<"Termina primero el N "<<(-qN.top()-delN)<<" con velocidad "<<sN
            <<", el otro es "<<(-qP.top()-delP)<<" con velocidad "<<sP<<endl;
            ans+=paso2, denominador = sN;
            
        } else {
            ifd cout<<"Termina primero el P "<<(-qP.top()-delP)<<" con velocidad "<<sP
            <<", el otro es "<<(-qN.top()-delN)<<" con velocidad "<<sN<<endl;
            ans+=paso1;
        }
        double paso=min(paso1, paso2);
        
        actualizar(qP, paso, denominador, sP, delP);
        actualizar(qN, paso, denominador, sN, delN);
    }
    // Si se vacio una y la otra no
    if (qN.empty() and !qP.empty()) {
        pctP = 1.0;
        ifd cout<<endl<<"Toca vaciar a P"<<endl;
        while (!qP.empty()) {
            sP = (pctP * T)/qP.size();
            ifd cout<<"Llevo "<<ans<<" y sigue "<<(-qP.top()-delP)<<" con velocidad "<<sP<<endl<<endl;
            if (-qP.top() > delP) {
                ans += (-qP.top()-delP)/sP;
                delP += (-qP.top()-delP);
            }
            qP.pop();
        }
    } else if (!qN.empty() and qP.empty()) {
        pctN = 1.0;
        ifd cout<<endl<<"Toca vaciar a N"<<endl;
        while (!qN.empty()) {
            sN = (pctN * T)/qN.size();
            ifd cout<<"Llevo "<<ans<<" y sigue "<<(-qN.top()-delN)<<" con velocidad "<<sN<<endl<<endl;
            if (-qN.top() > delN) {
                ans += (-qN.top()-delN)/sN;
                delN += (-qN.top()-delN);
            }
            qN.pop();
        }
    } 

    cout<<ans<<endl;

    return 0;
}
