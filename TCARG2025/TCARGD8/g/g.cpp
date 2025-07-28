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

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s1, s2; cin>>s1>>s2;
    int n = s1.size();
    int A[2][n];
    for (int i = 0; i < n; i++) {
        if (s1[i] == '0') A[0][i] = 0;
        else A[0][i] = 1;

        if (s2[i] == '0') A[1][i] = 0;
        else A[1][i] = 1;
    }

    ifd for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout<<A[i][j];
        }
        cout<<endl;
    }

    // Voy revisando ventanas de 2
    ll ans = 0;
    for (int i = 0; i < n-1; i++) {
        // |_
        if (A[0][i] == 0 and A[1][i] == 0 and A[1][i+1] == 0) {
            ifd cout<<"Puedo poner la forma "<<1<<" con i = "<<i<<endl;
            ans++;
            A[0][i] = A[1][i] = A[1][i+1] = 1;
        }
        // |-
        else if (A[1][i] == 0 and A[0][i] == 0 and A[0][i+1] == 0) {
            ifd cout<<"Puedo poner la forma "<<2<<" con i = "<<i<<endl;
            ans++;
            A[1][i] = A[0][i] = A[0][i+1] = 1;
        }
        // _|
        else if (A[1][i] == 0 and A[1][i+1] == 0 and A[0][i+1] == 0) {
            ifd cout<<"Puedo poner la forma "<<3<<" con i = "<<i<<endl;
            ans++;
            A[1][i] = A[1][i+1] = A[0][i+1] = 1;
        }
        // -|
        else if (A[0][i] == 0 and A[0][i+1] == 0 and A[1][i+1] == 0) {
            ifd cout<<"Puedo poner la forma "<<4<<" con i = "<<i<<endl;
            ans++;
            A[0][i] = A[0][i+1] = A[1][i+1] = 1;
        }
    }

    cout<<ans<<"\n";

    ifd for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout<<A[i][j];
        }
        cout<<endl;
    }

    return 0;
}
