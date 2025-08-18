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

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        int n; cin>>n;
        char old; cin>>old;
        int avan; cin>>avan;
        queue<int>avances;
        queue<char> direcciones;
        char start =old;
        char nuev;
        direcciones.push(start);
        avances.push(avan);
        forn(i,n-1) {
            char dir;
            cin>>nuev>>avan;
            if (nuev=='E') {
                if (old=='N') dir='R';
                else dir='L';
            }

            if (nuev=='W') {
                if (old=='N') dir='L';
                else dir='R';
            }

            if (nuev=='N') {
                if (old=='E') dir ='L';
                else dir = 'R';
            }
            if (nuev=='S') {
                if (old=='W') dir = 'L';
                else dir = 'R';
            }
            old=nuev;
            avances.push(avan);
            direcciones.push(dir);
        }

        cout<<avances.size()+direcciones.size()-1<<" ";
        while (!avances.empty()&&!direcciones.empty()) {
            cout<<direcciones.front()<<"\n"<<"Z "<<avances.front()<<"\n";
            direcciones.pop(); avances.pop();
        }
    }


}
