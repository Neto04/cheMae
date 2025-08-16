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
        int a, b; char c; cin>>a>>c>>b;
        bool fine =0;
        if (c=='=') a=b;
        
        else if (c=='<') {
            if (a>=b) {
                if (b==0) {
                    if (a==9) {
                        c='>';
                    }
                    else b=a+1;
                } 
                else a=b-1;
            }
        }
        else {
            if (a<=b) {
                if (b>=9) {
                    if (a==0) c='<';
                    else b=a-1;


                }
                else a=b+1;
            }
        }

        
        cout<<a<<c<<b<<endl;
    }
}
