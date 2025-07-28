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
    int tC; cin>>tC;
    while (tC--) {
        int n; cin>>n;
        // el papá de cada mae
        vector<int> p(n);
        bool unoSeen=0;
        // tiene al frente al max cuyo papá aún no conoce
        queue<int> q; q.push(n-1);
        int indx=n-2;
        // tiene 
        while (!q.empty()&&!unoSeen) {
            int x=q.front(); q.pop();
            if (x==2) {
                if (unoSeen) break;
                else {
                    p[2]=1;
                    break;
                }
            }
            bool ans;
            while (indx>0) {
                cout<<"? "<<x<<" "<<indx<<endl;
                // 1 si no es su papá, 0 si sí
                cin>>ans;
                // si es el papá, guárdelo como el papá, y jaleas
                if (!ans) {
                    p[x]=indx;
                    q.push(indx);
                    if (indx==1) {
                        unoSeen=true;
                        break;
                    }
                    indx--;
                    break;
                }

                else {
                    q.push(indx);
                    indx--;
                }
            }

        }
        cout<<"! ";
        forr(i,1, n) cout<<p[i]<<" ";
        cout<<endl;


    }




}
