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
map<ll, int> freq;

ll hashee(string&s) {
    const ll nS=s.size();
    ll res=0;
    for(ll i=0; i<nS; i++) {
        res*=31;
        res+=(s[i]-'a');
    }   
    
    return res;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, c; cin>>n>>c;

    vector<string> v(n);

    vector<ll> malPos(n);
    forn(i, n) {
        cin>>v[i];
        
        forn(j, c) if (v[i][j]=='*') malPos[i]=j;

        for(ll j=0; j<26; j++) {
            v[i][malPos[i]]='a'+j;
            freq[hashee(v[i])]++;
        }
    }

    pair<string, ll> bP={"zzzzzzzzzzz", -1};
    forn(i, n) {
        forn(j, 26) {
            v[i][malPos[i]]='a'+j;
            ll x=freq[hashee(v[i])];
            if (x>bP.second) bP={v[i], x};
            else if (x==bP.second) bP.first=min(bP.first, v[i]);
        }
    }

    cout<<bP.first<<" "<<bP.second<<"\n";

}
