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
    int n; cin>>n;
    string s; cin>>s;
    int count=0;
    int indx =0;
    queue<char> ans;
    while (indx<n) {
        if (s[indx]=='.') {
            indx++;
            continue;
        }
    
        // coma 4 letras
        indx+=4;
        // si ya no tiene nada al frente, de fijo se comió una V
        if (indx==n) {
            ans.push('v');
            break;
        }

        char next = s[indx];
        // si lo que tiene al frente es un punto, es una v, siga con su vida
        if (next=='.') {
            ans.push('v');
            indx++;
        }
        else {
            ans.push('w');
            indx+=4;
        }
    }
    // esto alch no importa
    cin>>s;

    while (!ans.empty()){
        cout<<ans.front();
        ans.pop();
    }
    cout<<endl;
 }
