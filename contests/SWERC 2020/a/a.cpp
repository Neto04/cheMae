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
    int n, k; cin>>n>>k;
    set<string> gente;
    map<string, int> freq;
    map<string, int> last;
    string s;
    getline(cin, s);
    forn(i, 3*n) {
        getline(cin, s);
        freq[s]++;
        last[s]=i;
        ifd cout<<"last de "<<s<<" = "<<i<<endl;
        gente.insert(s);
    }


    vector<pair<ii, string>> v;
    for(auto u:gente) v.push_back({{freq[u], last[u]}, u});
    sort(v.begin(), v.end());
    int cN=v.size();
    for (int i=0; i<min(k, cN); i++) cout<<v[cN-1-i].second<<endl;
}
