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

const int N = 1e5;
const int p = 269;
const int q = 7487;

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> freq(N,0);

    forn(i,n) {
        int x; cin>>x;
        freq[x]++;
    }

    if (freq[2] >= 3 and freq[p] >= 1 and freq[q] >= 1) {
        cout<<"5\n";
        cout<<"2 2 2 269 7487\n";
        return 0;
    }

    if (freq[2] >= 1 and freq[4] >= 1 and freq[p] >= 1 and freq[q] >= 1) {
        cout<<"4\n";
        cout<<"2 4 269 7487\n";
        return 0;
    }

    if (freq[8] >= 1 and freq[p] >= 1 and freq[q] >= 1) {
        cout<<"3\n";
        cout<<"8 269 7487\n";
        return 0;
    }

    if (freq[2] >= 2 and freq[2*p] >= 1 and freq[q] >= 1) {
        cout<<"4\n";
        cout<<"2 2 "<<2*p<<" 7487\n";
        return 0;
    }

    if (freq[4] >= 1 and freq[2*p] >= 1 and freq[q] >= 1) {
        cout<<"3\n";
        cout<<"4 "<<2*p<<" 7487\n";
        return 0;
    }

    if (freq[2] >= 1 and freq[4*p] >= 1 and freq[q] >= 1) {
        cout<<"3\n";
        cout<<"2 "<<4*p<<" 7487\n";
        return 0;
    }

    if (freq[8*p] >= 1 and freq[q] >= 1) {
        cout<<"2\n";
        cout<<8*p<<" 7487\n";
        return 0;
    }

    cout<<"0\n";

    return 0;
}
