#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=a; i<b; i++)
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

//#define EPS 1e-9
typedef long double ld;

const ld EPS = 1e-9;
//const ld INF = DBL_MAX;
const ld INF = 1.7976931348623157e+308;

struct pt {  // for 3D add z coordinate
    // los puntos tienen coordenadas double
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
    // retorna la norma del punto ^ 2
	ld norm2(){return *this**this;}
    // retorna la norma con la raiz
	ld norm(){return sqrt(norm2());}
    // retorna si los puntos pretty much son iguales
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
    // suma de puntos
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
    // resta puntos
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
    // producto escalar
	pt operator*(ld t){return pt(x*t,y*t);}
    // dividir por escalar
	pt operator/(ld t){return pt(x/t,y/t);}
    // producto punto
	ld operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
    // me tira el ángulo entre usted y el punto p
    // como cos(cita) = a*b/(||a||*||b||)
    // el mae hace arccos a ambos lados para sacar cita
	ld angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
    // el vector unitario en la misma dirección que usted
	pt unit(){return *this/norm();}
    // producto cruz
    // >0 si p a su izq
    // <0 si p a su der
    // ==0 si p y ud colineales
	ld operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on

    // moralmente es como ordenar un pair
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
    // me dice si está a la izq de la línea (DIRIGIDA) pqs
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>EPS;}
    // rota con respecto a un punto
	pt rot(pt r){return pt(*this%r,*this*r);}
    // rota con respecto a un ángulo (EN RADIANES)
	pt rot(ld a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);

// CCW order
// Includes collinear points (change sign of EPS in left to exclude)
vector<pt> chull(vector<pt> p){
	if(p.size()<3)return p;
	vector<pt> r;
	sort(p.begin(),p.end()); // first x, then y
	forr(i,0,p.size()){ // lower hull
		while(r.size()>=2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.push_back(p[i]);
	}
	r.pop_back();
	int k=r.size();
	for(int i=p.size()-1;i>=0;--i){ // upper hull
		while(r.size()>=k+2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.push_back(p[i]);
	}
	r.pop_back();
	return r;
}

int n;

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cout<<setprecision(2)<<fixed;

    int tC; cin>>tC;
    while (tC--) {
        cin>>n;
        vector<pt> p;

        vector<pt> extremos(8);
        // min x min y, min x max y, max x min y, max x max y
        extremos[0] = pt(INF, INF);
        extremos[1] = pt(INF, -INF);
        extremos[2] = pt(-INF, INF);
        extremos[3] = pt(-INF, -INF);
        // min y min x, min y max x, max y min x, max y max x
        extremos[4] = pt(INF, INF);
        extremos[5] = pt(INF, -INF);
        extremos[6] = pt(-INF, INF);
        extremos[7] = pt(-INF, -INF);

        forn(i,n) {
            int x, y; cin>>x>>y;
            pt nuevo = pt(ld(x), ld(y));
            p.push_back(nuevo);

            // Primero x
            if (nuevo.x < extremos[0].x) extremos[0] = nuevo;
            else if (abs(nuevo.x - extremos[0].x) < EPS) {
                if (nuevo.y < extremos[0].y) extremos[0] = nuevo;
            }

            if (nuevo.x < extremos[1].x) extremos[1] = nuevo;
            else if (abs(nuevo.x - extremos[1].x) < EPS) {
                if (nuevo.y > extremos[1].y) extremos[1] = nuevo;
            }

            if (nuevo.x > extremos[2].x) extremos[2] = nuevo;
            else if (abs(nuevo.x - extremos[2].x) < EPS) {
                if (nuevo.y < extremos[2].y) extremos[2] = nuevo;
            }
        
            if (nuevo.x > extremos[3].x) extremos[3] = nuevo;
            else if (abs(nuevo.x - extremos[3].x) < EPS) {
                if (nuevo.y > extremos[3].y) extremos[3] = nuevo;
            }

            // Primero y
            if (nuevo.y < extremos[4].y) extremos[4] = nuevo;
            else if (abs(nuevo.y - extremos[4].y) < EPS) {
                if (nuevo.x < extremos[4].x) extremos[4] = nuevo;
            }

            if (nuevo.y < extremos[5].y) extremos[5] = nuevo;
            else if (abs(nuevo.y - extremos[5].y) < EPS) {
                if (nuevo.x > extremos[5].x) extremos[5] = nuevo;
            }

            if (nuevo.y > extremos[6].y) extremos[6] = nuevo;
            else if (abs(nuevo.y - extremos[6].y) < EPS) {
                if (nuevo.x < extremos[6].x) extremos[6] = nuevo;
            }
        
            if (nuevo.y > extremos[7].y) extremos[7] = nuevo;
            else if (abs(nuevo.y - extremos[7].y) < EPS) {
                if (nuevo.x > extremos[7].x) extremos[7] = nuevo;
            }
        }

        // Calcular area de convex hull
        vector<pt> ch = chull(p);
        ld areaCH = 0.0;
        for (int i = 0; i < ch.size(); i++) {
            areaCH += (ch[i].x * ch[(i+1)%(ch.size())].y - ch[i].y * ch[(i+1)%(ch.size())].x);
        }
        areaCH = abs(areaCH);
        areaCH /= 2.0;

        // Calcular r como max dist entre extremos
        ld d = -INF, r=-INF;
        for (int i = 0; i < 8; i++) {
            pt a = extremos[i];
            if (abs(a.x-INF) < EPS or abs(a.y-INF) < EPS) continue;
            for (int j = i+1; j < 8; j++) {
                pt b = extremos[j];
                if (abs(b.x-INF) < EPS or abs(b.y-INF) < EPS) continue;
                d = max(r, sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)));
            }
        }
        r = d/2.0;

        
        ld pi = 3.14159265358979323846264338327950288;
        ld areaCirc = pi*r*r, areaCuad = 4.0*r*r;
        ld diffCirc = abs(areaCirc - areaCH), diffCuad = abs(areaCuad - areaCH);

        ifd {
            cout<<"r = "<<r/100000<<endl;
            cout<<"areaCH = "<<areaCH/10000000000<<endl;
            cout<<"areaCirc = "<<areaCirc/10000000000<<endl;
            cout<<"Area areaCuad = "<<areaCuad/10000000000<<endl;
        }

        string ans = "circle";
        if (diffCirc>diffCuad) ans = "square";
        
        cout<<ans<<"\n"; 
    }

    return 0;
}
