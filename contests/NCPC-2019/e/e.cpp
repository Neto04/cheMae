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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);

    int blanks = 0;
    for (char c : s) if (c == ' ') blanks++;

    //cin>>s;

    int k = blanks+1;

    //ifd cout<<"k = "<<k<<endl;

    int n; cin>>n;
    map<int,string> nombre;
    forn(i,n) {
        cin>>s;
        nombre[i] = s;
    }

    if (n == 1) {
        cout<<1<<"\n";
        cout<<nombre[0]<<"\n";
        cout<<0<<"\n";
        return 0;
    } 

    ordered_set o;
    forn(i,n) o.insert(i);

    // Pos inicial esta 0 indexada
    int pos = k-1, equipo = 0;
    pos %= o.size();
    vector<int> e[2];
    while (o.size()) {
        pos %= o.size();
        equipo %= 2;

        // Busco el que esta en la siguiente pos
        auto it = o.find_by_order(pos);
        e[equipo].push_back(*it);

        pos += (k-1); 
        equipo++; 
        o.erase(it);
    }

    cout<<e[0].size()<<"\n";
    for (int x : e[0]) cout<<nombre[x]<<"\n";
    cout<<e[1].size()<<"\n";
    for (int x : e[1]) cout<<nombre[x]<<"\n";

    return 0;
}
