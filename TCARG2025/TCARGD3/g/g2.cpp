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

#define debug 0
#define ifd if (debug)


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
        i+=len; data[i].val+=x.val;
        while (i/=2) data[i]=data[i*2]+data[i*2+1];
    }


    int ql, qr;
    Mono q_ (int i, int l, int r) {
        if (r<=ql||qr<=l) return Mono::zero();
        if (ql<=l&&r<=qr) return data[i];

        int m=(l+r)/2;
        return q_(i*2, l, m)+q_(i*2+1, m, r);
    }
    // update de [l, r)
    void rUpdt(int l, int r, Mono x) {
        update(l, x);
        x.val=-x.val;
        update(r, x);
    }

    Mono query(int l, int r) {ql=l; qr=r; return q_(1,0, len);}

    Mono pQuery(int i) {return query(0, i+1);}
};

vector<Mono> a;
Segtree st;
// LA PARTE DE LOS BLOQUES
// bloque: tiene id y longitud
struct bloque {
    ll length;
    int inicio;
    int end;
};
// hay n casillas
int n; 
// hay m bloques
int m;

vector<bloque> bloques;

bool armarEscalera() {
    int lastSt=0;
    bool error=false;
    // pase por todos los bloques
    for(int i=0; i<m&&!error; i++) {
        ifd cout<<"intento poner el bloque "<<i<<" en "<<lastSt<<endl;
        if (bloques[i].length-1+lastSt>=n) {
            error=true;
            continue;
        }
        bloques[i].inicio=lastSt;
        bloques[i].end=bloques[i].inicio+bloques[i].length-1;
        ifd cout<<"esa vara abarca desde "<<bloques[i].inicio<<" hasta "<<bloques[i].end<<endl;
        // haga update de que ahora tiene alguien de [start, end+1)
        ifd cout<<"hago un update de "<<bloques[i].inicio<<" a "<<bloques[i].end+1<<endl;
        st.rUpdt(bloques[i].inicio, bloques[i].end+1, {1});
        lastSt++;
    }
    return error;
}





int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // n la fila, m el numero de bloques
    cin>>n>>m;
    ifd cout<<"n="<<n<<endl;
    bloques.resize(m);
    forn(i, m) cin>>bloques[i].length;
    
    st.init(a, n+1);
    

    // Se arma la escalera
    if (armarEscalera()) {
        cout<<-1<<"\n";
        return 0;
    }
    bool error=false;
    int escIndx=m-1;
    // Segment tree
    ifd cout<<"holi, n = "<<n<<endl;
    for(int i=n-1; i>=0&&!error; i--) {
        ifd cout<<"estoy revisando si la columna "<<i<<" esta vacía"<<endl;
        // si ahorita esa columna NO está vacía, siga con su vida
        if (st.pQuery(i).val!=0) {
            ifd cout<<"tiene "<<st.pQuery(i).val<<endl;
            ifd cout<<"nope, está llena"<<endl;
            continue;
        }
        // si ya no tiene bloques que mover, riiip
        if (escIndx==-1) {
            error=true;
            continue;
        }
        // l0 es la nueva pos en la que inicia el bloque, r0 es el nuevo fin
        int  l0=i-bloques[escIndx].length+1, r0=i;
        // haga update de [lOg, rOg+1), -1
        st.rUpdt(bloques[escIndx].inicio, bloques[escIndx].end+1, {-1});
        // updatee l y r del bloque
        bloques[escIndx].inicio=l0;
        bloques[escIndx].end=r0;
        // haga update de [l0, r0+1), +1
        st.rUpdt(bloques[escIndx].inicio, bloques[escIndx].end+1, {1});
        escIndx--;

    }

    if (!error) forn(i, m) cout<<bloques[i].inicio+1<<" ";
    else cout<<-1;
    cout<<endl;
    return 0;

}
