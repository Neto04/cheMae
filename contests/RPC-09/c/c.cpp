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
typedef double T;
struct pt {

    T x,y;
    pt operator+(pt p) {return {x+p.x, y+p.y};}
    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(T d) {return {x*d, y*d};}
    pt operator/(T d) {return {x/d, y/d};} // only for floating-
    bool operator==(pt b) {return x == b.x && y == b.y;}
    bool operator!=(pt b) {return !(*this== b);}
    T sq(pt p) {return p.x*p.x + p.y*p.y;}
    double abs(pt p) {return sqrt(sq(p));}
    ostream& operator<<(ostream& os) {
        return os << "("<< x << "," << y << ")";
    }
    
};

template <typename T> int sgn(T x) {
return (T(0) < x) - (x < T(0));
}
pt translate(pt v, pt p) {return p+v;}
pt scale(pt c, double factor, pt p) {
return c + (p-c)*factor;
}
pt rot(pt p, double a) {
return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)};
}
pt perp(pt p) {return {-p.y, p.x};}
T dot(pt v, pt w) {return v.x*w.x + v.y*w.y;}

bool isPerp(pt v, pt w) {return dot(v,w) == 0;}

T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}


struct line {
    pt v; T c;
    // From direction vector v and offset c
    line(pt v, T c) : v(v), c(c) {}
    // From equation ax+by=c
    line(T a, T b, T c) : v({b,-a}), c(c) {}
    // From points P and Q
    line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
    // Will be defined later:
    // - these work with T = int
    T side(pt p);
    double dist(pt p);
    line perpThrough(pt p);
    bool cmpProj(pt p, pt q) {
     return dot(v,p) < dot(v,q);
    }
    line translate(pt t);
    // - these require T = double
    void shiftLeft(double dist);
    pt proj(pt p);
    pt refl(pt p);
};



double segPoint(pt a, pt b, pt p) {
    if (a != b) {
        line l(a,b);
        if (l.cmpProj(a,p) && l.cmpProj(p,b)) // if closest to projection
        return l.dist(p); // output distance to line
    }
    return min(abs(p-a), abs(p-b)); // otherwise distance to A or B
}



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);


}
