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

#define l 0
#define r 1

vector<ll> g = {0, 0};
vector<ll> p = {0, 0};
ll server = l, receiver = r;

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s; cin>>s;
    for (char c : s) {
        if (c == 'S') {
            // Le sumo los puntos al server
            p[server]++;
            // Reviso si gano
            if (p[server] == 10 or (p[server] >= 5 and p[server]-p[receiver] >= 2)) {
                g[server]++;
                p[l] = p[r] = 0;
            }
        } else if (c == 'R') {
            // Le sumo los puntos al receiver
            p[receiver]++;
            // Reviso si gano
            if (p[receiver] == 10 or (p[receiver] >= 5 and p[receiver]-p[server] >= 2)) {
                g[receiver]++;
                p[l] = p[r] = 0;
            }
            // Cambio server y receiver
            swap(server, receiver);
        } else {
            if (g[l] == 2) {
                cout<<g[l]<<" (winner) - "<<g[r]<<"\n";
            } else if (g[r] == 2) {
                cout<<g[l]<<" - "<<g[r]<<" (winner)\n";
            } else { // Nadie ha ganado
                if (server == l) cout<<g[l]<<" ("<<p[l]<<"*) - "<<g[r]<<" ("<<p[r]<<")\n";
                else cout<<g[l]<<" ("<<p[l]<<") - "<<g[r]<<" ("<<p[r]<<"*)\n";
            }
        }
    }

    return 0;
}
