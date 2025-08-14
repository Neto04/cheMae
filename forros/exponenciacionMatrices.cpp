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
#define SIZE 200
int NN=200;
vector<vector<double> > res(200, vector<double> (200));
void mul(vector<vector<double> >& a, vector<vector<double> >& b){ 
    vector<vector<double> > tmp(200, vector<double> (200));
    forn(i, NN) forn(j, NN) forn(k, NN) tmp[i][j]+=a[i][k]*b[k][j];
    forn(i, NN) forn(j, NN) a[i][j]=tmp[i][j]; 
    forn(i, NN) forn(j, NN) if (a[i][j]>1) a[i][j]-=1;
}

void powmat(vector<vector<double> > &a, int exp){ 
    forn(i, NN) forn(j, NN) res[i][j]=(i==j);
    while(exp){
        if(exp&1) mul(res, a), exp--;
        else mul(a, a), exp/=2;
    }
}