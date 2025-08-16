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
const int MAX = 1e5+2;
ll a[MAX], st[4*MAX];

void build(int x, int l, int r) {
    if (l==r) {st[x] = a[l]; return;}

    int m = (r-l)/2 +l;

    build(2*x, l, m);

    build (2*x+1, m+1, r);
    st[x] = st[2*x] + st[2*x+1];

}

int query(int x, int l, int r, int lo, int hi) {
    if (lo>r||hi<l) return 0;
    if (lo<=l&&r<=hi) return st[x];
    int m = (r-l)/2+l;
    int izq = query(2*x, l, m, lo, hi);
    int der = query(2*x+1, m+1, r, lo, hi);
    return izq+der;
}

void update(int x, int l, int r, int p, ll v) {
    if (l==r) {
        st[x] = v;
        return;
    }
    int m = (l+r)/2;
    if (p<=m) update(2*x, l, m, p, v);
    else update(2*x+1, m+1, r, p, v);
    st[x] = st[2*x]+st[2*x]+1;

}



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; 
    cin>>n>>m; 

    forn(i, n) cin>>a[i];

    build(1, 1, n);
    int inst, x1, x2;
    while (m--) {
        cin>>inst>>x1>>x2;


        if (inst==1) {
            x1++;
            update(1, 1, n, x1, x2);
        }

        else {
            x1++; x2++;

            cout<<query(1, 1, n, x1, x2-1)<<"\n";
        }
    }



}
