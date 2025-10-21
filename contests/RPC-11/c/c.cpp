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
int n;
bool valid(int a, int b) {
    ifd cout<<"checking "<<a<<" "<<b<<", con n = "<<n<<endl;
    return (a>=0 and b>=0 and a<n and b<n);
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int m; cin>>n>>m;
    vector<int> diagIzq(2*n+5), diagDer(2*n+5), fila(2*n+5), col(2*n+5);
    vector<vector<int>> v(n, vector<int>(n));
    stack<pair<ii, char>> gente;
    forn(i, m) {
        char c; int a, b;
        cin>>c>>a>>b;
        a--, b--;
        gente.push({{a, b}, c});
        ifd cout<<"leo "<<a<<", "<<b<<" -"<<c<<endl;
    } 

    while (!gente.empty()) {
        int a, b; char c;
        pair<ii, char> curr = gente.top(); gente.pop();
        tie(a, b) = curr.first;c=curr.second;
        ifd cout<<"saco "<<a<<", "<<b<<endl;
        ifd cout<<"vea que estan en la diagIzq "<<a-b+n<<", y diagDer "<<a+b<<endl;
        v[a][b]++;

        if (c=='R') {
            fila[a]++;
            col[b]++;
        }
        else if (c=='Q') {
            fila[a]++;
            col[b]++;
            diagIzq[a-b+n]++;
            diagDer[a+b]++;
        }

        else {
            ifd cout<<"tengo un caballo!"<<endl;
            int cI[8]={-1,-1, -2,-2, 1, 1, 2, 2};
            int cJ[8]={-2, 2, -1, 1, -2, 2, -1, 1};
            forn(k, 8) {
                int r = a+cI[k], c=b+cJ[k];
                ifd cout<<"intento marcar "<<r<<", "<<c<<endl;
                if (valid(r, c)) {
                    ifd cout<<"es valido"<<endl;
                    v[r][c]++;
                }
            }            
        }
    }
    ifd {
        cout<<"v se ve"<<endl;
        forn(i,n) {
            forn(j,n) cout<<v[i][j]<<" ";
            cout<<endl;
        }
        
    }
    ll ans =0;
    forn(i, n) forn(j,n) 
        if (v[i][j] or fila[i] or col[j] or diagIzq[i-j+n] or diagDer[i+j]) ans++;
    cout<<ans<<endl;

}
