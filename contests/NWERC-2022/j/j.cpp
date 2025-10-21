#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)

typedef long long ll;
typedef pair<int, int> ii;
#define iii pair<ii, int> 
#define primero first.first
#define segundo first.second
#define tercero second
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)

struct Mono {
    ll val;
    static Mono zero() { return {0}; } // neutro de max
};
Mono operator+ (Mono a, Mono b) {
    return {max(a.val, b.val)};
}

struct Segtree {
    int len; vector<Mono> data;
    void init(vector<Mono>&a, int n) { 
        assert(n>0);
        len=1<<(32-__builtin_clz(n));  // smallest power of two ≥ n
        data.assign(len*2, Mono::zero());
        if (!a.empty()) forn(i, n) data[i+len] = a[i];
        dforr(i, 1, len) data[i] = data[i*2] + data[i*2+1];
    }
    void update(int i, Mono x) {
        i += len; data[i] = {max(data[i].val, x.val)};
        while (i /= 2) data[i] = data[i*2] + data[i*2+1];
    }
    int ql, qr;
    Mono q_(int i, int l, int r) {
        if (r <= ql || qr <= l) return Mono::zero();
        if (ql <= l && r <= qr) return data[i];
        int m = (l+r)/2;
        return q_(i*2,l,m) + q_(i*2+1,m,r);
    }
    Mono query(int l, int r) { ql = l; qr = r; return q_(1, 0, len); }
};

bool compi(iii a, iii b) {
    if (a.primero==b.primero) return a.segundo>b.segundo;
    return a.primero<b.primero;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin>>n;
    vector<ii> v(n);
    map<int, int> posR;
    forn(i, n) {
        cin>>v[i].first>>v[i].second;
        v[i].second=v[i].first+v[i].second; // convert to end time
    }
    set<int> finalSet;
    forn(i,n) finalSet.insert(v[i].second);
    vector<int> finales;
    for(auto u:finalSet) {
        posR[u]=finales.size();
        finales.push_back(u);
    }
    vector<iii> v2(n);
    forn(i, n) v2[i]={{v[i].first, posR[v[i].second]}, i};
    sort(v2.begin(), v2.end(), compi);
    
    vector<int> rank(n);
    vector<Mono> base(finales.size());
    Segtree st; st.init(base, finales.size());

    forn(i, n) {
        int a,b, indx;
        a=v2[i].primero, b=v2[i].segundo, indx=v2[i].tercero;
        // query from b to end of segtree
        rank[indx]=st.query(b, finales.size()).val+1;
        st.update(b, {rank[indx]});
    }
    forn(i,n) cout<<rank[i]-1<<" ";
    cout<<"\n";
}
