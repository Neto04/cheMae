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

const int N = 2e6+1;
int n, k;
vector<ll> v;
deque<int> ans;

int contarAtras(int inicio, ll d, bool guardar = false) {
    int count = 0;
    int ultimo = inicio;
    for (int i = ultimo-1; i >= 0; i--) {
        ll diff = v[ultimo]-v[i];
        if (diff != d) {
            count++;
            if (guardar) ans.push_front(i+1);
        }
        else ultimo = i;
    }
    return count;
}

int contarAdelante(int inicio, ll d, bool guardar = false) {
    int count = 0;
    int ultimo = inicio;
    for (int i = ultimo+1; i < n; i++) {
        ll diff = v[i]-v[ultimo];
        if (diff != d) {
            count++;
            if (guardar) ans.push_back(i+1);
        }
        else ultimo = i;
    }
    return count;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    v.resize(n);
    for(ll& x : v) cin>>x;

    int inicio = 0, minBorrados = 1e7;
    pair<int,ll> mejor;
    // Para cada uno de los k+1 grupos
    for (int i = 1; i <= k+1; i++) {
        ll d = v[inicio+1] - v[inicio];

        int count = 0;
        count += contarAtras(inicio, d);
        count += contarAdelante(inicio, d);

        if (count < minBorrados) {
            minBorrados = count;
            mejor = {inicio, d};
        }

        inicio += 2;
    }

    if (minBorrados > k) {
        cout<<-1<<"\n";
        return 0;
    }

    contarAtras(mejor.first, mejor.second, true);
    contarAdelante(mejor.first, mejor.second, true);
    cout<<ans.size()<<"\n";
    for (int x : ans) cout<<x<<" ";
    cout<<"\n";

    return 0;
}
