#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;
#define debug 1
#define ifd if (debug)


int n;
ll h, k;

vector<vector<int>> adj;
vector<pair<ll,ll>> coord;
// si es negro o blanco
vector<int> rod;
map<pair<ll,ll>, int> indice;

// tirar bfs desde nodo x
ll bfs(int x) {
    // coso son las coordenadas en las que está
    pair<ll,ll> coso1 = coord[x];
    // si el mae es negro Y tiene altura brincable
    // OPCIÓN 1
    // if (rod[x] and coso1.second*coso1.second <= h) {
    //     return 1;
    // }
    // OPCIÓN 2
    if (coso1.second*coso1.second <= h) return 1;
    
    // queue de nodos
    queue<int> q;
    // vector de seen
    vector<bool> visited(n);
    // distancias
    vector<ll> dist(n);
    visited[x] = true;
    // el inicio tiene dist 0
    dist[x] = 0;
    q.push(x);

    while (!q.empty()) {
        int s = q.front(); q.pop();
        // si el mae está en el eje ooo está en negro Y brincable
        // OJO: aquí no estamos segurxs de si esta vara debería de fijarse si el mae es negro para poder brincar la pared
        // OPCIÓN 1
        // if (coord[s].second==0||(rod[s] and coord[s].second*coord[s].second <= h)) return dist[s] +!(coord[s].second==0);
        // OPCIÓN 2
        if (coord[s].second==0||(coord[s].second*coord[s].second <= h)) return dist[s] +!(coord[s].second==0);
        // ^igual las dos tiran WA en tc 5 jaja
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            dist[u] = dist[s] + 1;
            q.push(u);            
        }
    }
    // si nunca pudo llegar a algo salible, rip
    return -1;
} 

__int128_t euclidiana(int u, int v) {
    // distancia euclidiana entre dos puntos 
    pair<ll,ll> c1 = coord[u], c2 = coord[v];

    __int128_t x1 = c1.first, x2=c2.first, y1 = c1.second, y2=c2.second;
    __int128_t xx = (x1-x2)*(x1-x2);
    __int128_t yy = (y1-y2)*(y1-y2);
    return (xx + yy);
}


bool son_adyacentes(int u, int v) {
    __int128_t hh=h, kk=k;
    if (rod[u]) {
        // negro-negro
        if (rod[v]) {
            if (euclidiana(u,v) <= min(hh,kk)) return true;
        } else {
            // negro-blanco
            if (euclidiana(u,v) <= hh) return true;
        }
    } else {
        if (rod[v]) {
            // blanco a negro
            if (euclidiana(u,v) <= kk) return true;
        }
    }
    return false;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>h>>k;

    k *= k;
    h *= h;

    adj.resize(n);
    coord.resize(n);
    rod.resize(n);

    for (int i = 0; i < n; i++) {
        ll a, b; int x; cin>>a>>b>>x;
        rod[i] = x;
        coord[i] = {a,b};
        indice[{a,b}] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (son_adyacentes(i,j)) adj[i].push_back(j);
            if (son_adyacentes(j,i)) adj[j].push_back(i);
        }
    }

    ll a, b; cin>>a>>b;
    if (b == 0) {
        cout<<0<<"\n";
        return 0;
    }

    pair<ll,ll> x = {a,b};
    cout<<bfs(indice[{a,b}])<<"\n";

    return 0;
}