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

    int n; cin>>n;
    vector<int> v1(n+1), v2(n+1), pos1(n+1), pos2(n+1);
    for (int i = 1; i <= n; i++) {
        cin>>v1[i];
        pos1[v1[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin>>v2[i];
        pos2[v2[i]] = i;
    }

    // Reviso si hay inversiones
    for (int i = 1; i <= n-1; i++) {
        if (pos1[i] < pos1[i+1] and pos2[i] > pos2[i+1]) {
            cout<<-1<<"\n";
            return 0;
        }
        if (pos1[i] > pos1[i+1] and pos2[i] < pos2[i+1]) {
            cout<<-1<<"\n";
            return 0;
        }
    }

    // Si no hay inversiones muevo a todos de izq a der
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (v1[i] == v2[i]) continue;
        // Pos en v1 del mae que quiero traer
        int pos = pos1[v2[i]];
        // Empiezo a traerlo desde pos-1 hasta i
        for (int j = pos-1; j >= i; j--) {
            ans.push_back(j);
            
            pos1[v1[j]]=j+1;
            swap(v1[j], v1[j+1]);
            // El mae que estaba en j ahora esta en j+1
        }
    }   
    if (ans.size()>20000) cout<<-1<<endl;
    else {
        cout<<ans.size()<<"\n";
        for(int& x : ans) cout<<x<<" ";
        if (ans.size())cout<<"\n";
    }

    return 0;
}
