// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())

#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;
#define dforr(i, a, b) for(int i=int(b)-1; i>=int(a); --i)

#define debug 1
#define ifd if (debug)

int n, m;
vector<int> eles;
//vector<pair<int,int>> eles;
vector<pair<int,int>> escalera;
//vector<int> ele_de_escalera;


struct Mono {
    ll val;
    static Mono zero() {return {0};}
};
Mono operator + (Mono a, Mono b) {
    return {a.val+b.val};
}

struct Segtree {
    int len; vector<Mono> data;
    void init(vector<Mono>&a, int n) {
        assert(n>0);
        len=1<<(31-__builtin_clz(2*n-1));
        data.assign(len*2, Mono::zero());
        if (!a.empty()) forn(i, n) data[i+len]=a[i];
        dforr(i, 1, len) data[i]=data[i*2]+data[i*2+1];

    }

    void update(int i, Mono x) {
        i+=len;; data[i]=x;
        while (i/=2) data[i]=data[i*2]+data[i*2+1];
    }


    int ql, qr;
    Mono q_ (int i, int l, int r) {
        if (r<=ql||qr<=l) return Mono::zero();
        if (ql<=l&&r<=qr) return data[i];

        int m=(l+r)/2;
        return q_(i*2, l, m)+q_(i*2+1, m, r);
    }


    Mono query(int l, int r) {ql=l; qr=r; return q_(1,0, len);}
};

vector<Mono> a;
Segtree st;
bool construir_escalera() {
    int inicio = 0;
    for (int i = 0; i < m; i++) {
        int l = eles[i];
        // Si todavia me caben los colores pinto
        if (inicio + l - 1 < n) {
            escalera[i] = {inicio, inicio+l-1};
            st.update(inicio, {1});
            st.update(inicio+l, {-1});
            
            //ele_de_escalera[i] = l;
            // Actualizo el inicio a la ultima casilla que pinte
            inicio++;
        } else {
            return false;
        }
    }
    return true;
}

bool cmp(pair<int,int>& a, pair<int,int>& b) {
    return a.first > b.first;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // n la fila, m el numero de bloques
    cin>>n>>m;
    eles.resize(m), escalera.resize(m);
    //ele_de_escalera.resize(m);
    for(int& x : eles) cin>>x;
   
    st.init(a, n);
    //sort(eles.begin(), eles.end(), cmp);

    // Se arma la escalera
    bool error = !construir_escalera();
    
    if (error) {
        cout<<-1<<"\n";
        return 0;
    }
    
    int escIndx=escalera.size()-1;
    // Segment tree
    for(int i=n-1; i>=0&&!error; i--) {
        if (st.query(0, i).val==0) {
            if (escIndx==-1) {
                error=true;
                continue;
            }
            // de [l, r] del último mae de la escalera reste 1
            st.update(escalera[escIndx].first,{-1});
            st.update(escalera[escIndx].second+1,{1});
            ll rango =eles[escIndx];
            escalera[escIndx]={i-rango+1, i};
            st.update(i-rango+1, {1});
            st.update(i+1, {-1});
            escIndx--;
        }
    }

    if (!error) forn(i, m) cout<<escalera[i].first+1<<" ";
    else cout<<-1;
    cout<<endl;
    return 0;

}
