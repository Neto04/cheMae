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

const int SIZE=1000005;

#define debug 1
#define ifd if (debug)

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    freopen("deposits.in", "r", stdin);
    freopen("deposits.out", "w", stdout);

    int n1; cin>>n1;
    vector<int> a(n1); forn(i,n1) cin>>a[i];
    int n2; cin>>n2;
    vector<int> b;
    vector<int> freq(SIZE);
    forn(i, n2) {
        int x; cin>>x;
        if (!freq[x]) b.push_back(x);
        freq[x]++;
    }

    vector<int> criba(SIZE);
    for(int x:b) 
        for(int j = x; j<SIZE; j+=x) criba[j]+=freq[x];

    ll ans =0;
    for(int x:a) ans +=criba[x];
    cout<<ans<<endl;

}   
