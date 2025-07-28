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
        string s; cin>>s;
        vector<int> v(n);
        int malP=0;
        forn(i,n) {
            cin>>v[i];
            if (v[i]!=i+1) malP++;
        }

        bool alice = s[0]=='A';
        if (n<=2) {
            cout<<"Alice\n";
            continue;
        }
        if (n==3) {
            if (malP==3) {
                if (!alice) cout<<"Alice\n";
                else cout<<"Bob\n";
            }
            if (malP==2) {
                if (!alice) cout<<"Bob\n";
                else cout<<"Alice\n";
            }
            else if (malP==0) {
                if (!alice) cout<<"Alice\n";
                else cout<<"Bob\n";
            }
            continue;
        }
        if (malP>2) {
            cout<<"Bob\n";
            continue;
        }
        if (malP==2) {
            if (alice) cout<<"Alice\n";
            else cout<<"Bob\n";
            continue;
        }

        if (malP==0) {
            if (alice) cout<<"Bob\n";
            else cout<<"Alice\n";
        }

    }


}
