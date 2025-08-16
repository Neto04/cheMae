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


vector<pair<ll,ll>> coord;
// si es negro o blanco
bitset<10005> rod;



ll euclidiana(int u, int v) {
    // distancia euclidiana entre dos puntos 
    return ((coord[u].first-coord[v].first)*(coord[u].first-coord[v].first) + (coord[u].second-coord[v].second)*(coord[u].second-coord[v].second));
}


bool son_adyacentes(int u, int v) {
    
    if (rod[u]) {
        // negro-negro
        if (rod[v]) {
            if (euclidiana(u,v) <= max(h,k)) return true;
        } else {
            // negro-blanco
            if (euclidiana(u,v) <= h) return true;
        }
    } else {
        if (rod[v]) {
            // blanco a negro
            if (euclidiana(u,v) <= k) return true;
        }
    }
    return false;
}

// tirar bfs desde nodo x
ll bfs(int x) {
    // coso son las coordenadas en las que está
    pair<ll,ll> coso1 = coord[x];
    // si el mae es negro Y tiene altura brincable
    // OPCIÓN 1
    if (rod[x] and coso1.second*coso1.second <= h) {
        return coso1.second!=0;
    }
    // // OPCIÓN 2
    // if (coso1.second*coso1.second <= h) return 1;
    
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
        if (coord[s].second==0||(rod[s] and coord[s].second*coord[s].second <= h)) return dist[s] +!(coord[s].second==0);
        // // OPCIÓN 2
        // if (coord[s].second==0||(coord[s].second*coord[s].second <= h)) return dist[s] +!(coord[s].second==0);
        // ^igual las dos tiran WA en tc 5 jaja
        for (int u=0; u<n; u++) { 
            if (u==s||visited[u]||!son_adyacentes(s,u)) continue;
            visited[u] = true;
            dist[u] = dist[s] + 1;
            q.push(u);            
        }
    }
    // si nunca pudo llegar a algo salible, rip
    return -1;
} 



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>h>>k;

    k *= k;
    h *= h;

    coord.resize(n);
    

    for (int i = 0; i < n; i++) {
        ll a, b; int x; cin>>a>>b>>x;
        rod[i] = x;
        coord[i] = {a,b};
        
    }

    ll a, b; cin>>a>>b;
    if (b == 0) {
        cout<<0<<"\n";
        return 0;
    }

    pair<ll,ll> x = {a,b};
    
    forn(i, n) if (coord[i]==x) {
        cout<<bfs(i)<<"\n";
        break;
    }

    return 0;
}