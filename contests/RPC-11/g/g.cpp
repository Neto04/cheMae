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

ll hashsillo(string&s) {
    s[0]=tolower(s[0]);
    ll ans =0;
    ll MOD = 999727999;
    ll P = 1777771;
    forn(i, s.size()) {
        ans = (ans *P)%MOD;
        ans =(ans + (s[i]-'a'))%MOD;
    }

    return ans;
}

const int N = 1e5+1;
vector<ll> link(N), tamano(N);

ll find(ll a) {
    if (link[a] != a) link[a] = find(link[a]);
    return link[a];
}

bool same(ll a, ll b) {
    return (find(a) == find(b));
}

void unite(ll a, ll b) {
    if (same(a,b)) return;
    a = find(a), b = find(b);
    if (tamano[a] == tamano[b]) {
        tamano[a]++;
    }
    if (tamano[a] > tamano[b]) link[b] = a;
    else link[a] = b;
}


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    set<ll> papas, hijos;
    set<ll> hashes;
    map<ll, ll> seen;
    vector<ll> v(n);
    int indx=0;

    
    map<ll, ll> rep;
    forn(i, n) {
        string a; cin>>a; a.pop_back();
        string trash; cin>>trash>>trash;
        string b; cin>>b;
        ifd cout<<"lei "<<a<<" "<<b<<endl;
        ll hA = hashsillo(a), hB=hashsillo(b);
        if (rep[hA]==0) rep[hA]=indx++;
        if (rep[hB]==0) rep[hB]=indx++;
        papas.insert(hB);
        ll rA=rep[hA];
        ll rB = rep[hB];
        if (hashes.find(rA)==hashes.end()) {
            link[rA] = rA;
            tamano[rA] = 1;
        }
        if (hashes.find(rB)==hashes.end()) {
            link[rB] = rB;
            tamano[rB] = 1;
        }
        hashes.insert(rA), hashes.insert(rB);
        unite(rA, rB);

        if (a!=b) hijos.insert(hA);
    }
    // if (papa.size()==1) 
    ifd cout<<"no me he caido"<<endl;
    int malos=0;
    for(ll u:papas) {
        if (hijos.find(u)==hijos.end()) malos++;
        if (malos>1) break;
    }

    ll x = -1;
    for (ll h : hashes) {
        if (x == -1) x = find(rep[h]);
        else {
            if (find(rep[h]) != x) {
                malos = 100;
                break;
            }
        }
    }
    
    if (malos>1) cout<<"im";
    cout<<"possible"<<endl;
}
