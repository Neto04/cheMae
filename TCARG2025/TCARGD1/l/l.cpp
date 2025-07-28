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

        vector<tuple<int,int,int>> papa(n+1);

        cout<<"? 1 2 3"<<endl;
        int x; cin>>x;
        papa[x]= {1, 2, 3};
        queue<int> q; q.push(x);
        // FALTA VER SI X =0
        if (x==0) {
            cout<<"! 1 2 3"<<endl;
            continue;
        }
        bool won=false;
        while (!q.empty()&&!won) {
            x=q.front(); q.pop();
            int ps[3];
            tie(ps[0], ps[1], ps[2]) =papa[x];
            forn(i, 3) {
                cout<<"? "<<x<<" "<<ps[i]<<" "<<ps[(i+1)%3]<<endl;
                int y; cin>>y;
                papa[y] = {x, ps[i], ps[(i+1)%3]};
                if (y==0) {
                    cout<<"! "<<x<<" "<<ps[i]<<" "<<ps[(i+1)%3]<<endl;
                    won=true;
                    break;
                }
                q.push(y);
                
            }
        }

    }


}
