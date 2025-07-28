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

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<pair<string, int>> cuartos(8), semis(4), final(2);
    for (int i = 0; i < 8; i++) {
        string s; int t;
        cin>>s>>t;
        cuartos[i] = {s, t};
    }

    int siguiente = 0;
    for (int i = 0; i < 8; i+= 2) {
        if (cuartos[i].second > cuartos[i+1].second) {
            semis[siguiente] = cuartos[i];
        } else {
            semis[siguiente] = cuartos[i+1];
        }
        siguiente++;
    }

    siguiente = 0;
    for (int i = 0; i < 4; i+= 2) {
        if (semis[i].second > semis[i+1].second) {
            final[siguiente] = semis[i];
        } else {
            final[siguiente] = semis[i+1];
        }
        siguiente++;
    } 

    if (final[0].second > final[1].second) {
        cout<<final[0].first<<" beats "<<final[1].first<<"\n";
    } else {
        cout<<final[1].first<<" beats "<<final[0].first<<"\n";
    }

    return 0;
}
