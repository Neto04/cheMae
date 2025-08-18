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
struct triple{
    int a, b, c, id, muere;
    ll score;
};

bool compi(triple a, triple b) {
    return a.score<b.score;
}


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int tC; cin>>tC;
    while (tC-- ){
        int n; cin>>n;
        vector<triple> v(n);
        vector<vector<int>> freq(3, vector<int> (1e5+5));
        forn(i, n) {
            cin>>v[i].a>>v[i].b>>v[i].c; v[i].id=i;
            freq[0][v[i].a]++;
            freq[1][v[i].b]++;
            freq[2][v[i].c]++;
        }
        forn(i,n) {
            int aa=freq[0][v[i].a]-1, bb=freq[1][v[i].b]-1, cc=freq[2][v[i].c]-1;
            v[i].score= max(aa, max(bb, cc));      
        }
        
        sort(v.begin(), v.end(), compi);
        
        vector<int> muertosEn(n);
        int indx=0;
        for(int k=0; k<n&&indx<n; k++) {
            while (indx<n and v[indx].score<k) {
                muertosEn[k]++;
                indx++;
            }
        }
        vector<ll> pSum(n+1);
        forr(i, 1,n) pSum[i]=muertosEn[i]+pSum[i-1];
        forn(i,n) cout<<pSum[i]<<" ";
        cout<<"\n"; 

    }




}
