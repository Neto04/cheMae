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

const int INF = 1e9;

#define fore(e,c) for(const auto &e : (c))
#define all(v) begin(v), end(v)

struct Dinic{ // O(n^2 * m)
	int n, src, dst;
	vector<int> dist, q, work; // dist: distancias desde S, sin ponderar
	struct edge {int to, rev; ll f, cap;};
	vector<vector<edge>> g; vector<ll> dd;
	Dinic(int n_): n(n_), dist(n_+2), q(n_+2), work(n_+2), g(n_+2), dd(n_+2)
	               {} // Deja espacio para el min_cap
	void add_edge(int s, int t, ll cap, ll mincap = 0){
		// assert(0 <= mincap and mincap <= cap);
		dd[s] += mincap; dd[t] -= mincap;
		g[s].pb({t, sz(g[t]),   0, cap-mincap});
		g[t].pb({s, sz(g[s])-1, 0, 0}); // Residual: cap = 0 y flujo < 0
	}
	bool dinic_bfs(){
		fill(all(dist), -1); dist[src] = 0;
		int qt = 0; q[qt++] = src;
		for(int qh = 0; qh < qt; qh ++){
			int u = q[qh];
			fore(e, g[u]){
				int v = e.to;
				if(dist[v] < 0 and e.f < e.cap) dist[v] = dist[u]+1, q[qt++] = v;
			}
		}
		return dist[dst] >= 0;
	}	
	ll dinic_dfs(int u, ll f){
		if(u == dst) return f;
		for(int &i = work[u]; i < sz(g[u]); i ++){
			edge &e = g[u][i];
			if(e.cap <= e.f) continue;
			int v = e.to;
			if(dist[v] == dist[u]+1){
				ll df = dinic_dfs(v, min(f, e.cap - e.f));
				if(df > 0){
					e.f += df; g[v][e.rev].f -= df;
					return df;
				}
			}
		}
		return 0;
	}
	ll max_flow(int _src, int _dst){
		src = _src; dst = _dst;
		ll result = 0;
		while(dinic_bfs()){
			fill(all(work), 0);
			while(ll delta = dinic_dfs(src, INF)) result += delta;
		}
		return result;
	} // ll max_flow_min_cap() esta en el mcMF
};

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        /*
        Nodos:
        0: source
        1 - n: numeros
        n+1 - n+61: bits
        n+61+1: sink

        n+61+1+1 nodos
        */
        Dinic G((n+61+1+1)+1, 0, n+61+1);
        // Indice de los nodos en 
        vector<int> v(n), indice(101), freq(101,0);
        int siguiente = 1;
        for (int i = 0; i < n; i++) {
            int x; cin>>x;
            freq[x]++;
        }
        // Arista de los bits al sink
        for (int k = 0; k <= 60; k++) {
            G.add_edge(k, n+1+k, 1);
        }
        // Aristas de numeros
        for (int i = 0; i < n; i++) {
            int x = v[i];
            // Arista del source al numero
            G.add_edge(0, indice[x], freq[x]);
            for (int k = 0; k <= 60; k++) {
                // Arista de numero a cada bit
                if ((1 << k) & x) {
                    G.add_edge(indice[x], n+1+k, INF);
                }
            }
        }

        G.flow();


    }

    return 0;
}

