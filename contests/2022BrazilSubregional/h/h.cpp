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

#define debug 1
#define ifd if (debug)

const int MAXN=1e4+5;

vector<int> g[MAXN];     
bool vis[MAXN];
int low[MAXN], scc[MAXN];  //Inicializar en -1
int idx = 0, cant = 1;
stack<int> s;
void dfs(int v){
	vis[v] = true;
	int tag = low[v] = idx++;
	s.push(v);
	for(int x : g[v]){
		if(vis[x] and scc[x] > -1) continue;
		if(not vis[x]) dfs(x);
		low[v] = min(low[v], low[x]);
	}
	if(low[v] == tag){
		while(1){
			int x = s.top(); s.pop();
			scc[x] = cant;
			if(x == v) break;
		}
		cant++;
	}
}

int mi[MAXN];

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) scc[i] = -1;
    for (int i = 1; i <= n; i++) 
        if (!vis[i])
            dfs(i);

    for (int i = 1; i <= n; i++) mi[i] = -1;
    for (int i = 1; i <= n; i++) {
        if (mi[scc[i]] != -1) {
            scc[i] = mi[scc[i]];
        } else {
            mi[scc[i]] = i, scc[i] = i;
        }
    }

    bool seguir = false;
    int dummy = scc[1];
    for (int i = 1; i <= n; i++) {
        if (scc[i] != dummy) {
            seguir = true;
            break;
        }
    }

    if (!seguir) {
        cout<<0<<"\n";
        return 0;
    }

    vector<int> v_iG(MAXN, 0), v_oG(MAXN, 0);
    for (int a = 1; a <= n; a++) {
        for (int& b : g[a]) {
            if (scc[a] != scc[b]) {
                v_oG[scc[a]]++;
                v_iG[scc[b]]++;
            }
        }
    }

    set<int> iG, oG;
    for (int i = 1; i <= n; i++) {
        if (v_iG[scc[i]] == 0) {
            iG.insert(scc[i]);
        }
        if (v_oG[scc[i]] == 0) {
            oG.insert(scc[i]);
        }
    }

    cout<<max(iG.size(),oG.size())<<"\n";

    return 0;
}
