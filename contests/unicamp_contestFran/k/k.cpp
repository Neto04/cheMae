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
vector<string> v(2);
int n, m;
string answer;

// retorna cuántos caracteres hasta el último (inclusivo, de derecha a izq) en el que suman >=10 
int disMatch() {
    int last=0, count=1;
    int i1=n-1, i2=m-1;
    while (i1>=0 and i2>=0) {
        
        if (v[0][i1]-'0' + v[1][i2]-'0' >=10) last=count;
        count++;
        i1--, i2--;
    }
    i1=n-1, i2=m-1;
    // last <=min(n, m), entonces no se puede salir
    forn(i, last) i1--, i2--;
    // si entra en esto, es porque de fijo, count<= min(n, m)
    while (i1>=0 and i2>=0 and (v[0][i1]-'0')+(v[1][i2]-'0')>=9){
        last=count;
        count++;
        i1--, i2--;
    }
    // entonces solo retorna cosas <= min(n, m)
    return last;


}

void res (int count) {
    ifd cout<<"count = "<<count<<endl;
    // la respuesta de la resta para c/u
    vector<deque<char>> ans(2);
    // la respuesta para c/u en forma de strings
    vector<string> fAns(2);
    forn(curr, 2) {
        int avail = (curr ? m : n);
        int use = min(count, avail);   // never consume more than length

        bool seenPos = false;
        int cIndx = avail - 1;

        for (int i=0; i<use; i++) {
            if (seenPos) ans[curr].push_front(9-(v[curr][cIndx]-'0')+'0');
            else {
                seenPos = (v[curr][cIndx] != '0');
                ans[curr].push_front((10-(v[curr][cIndx]-'0'))%10+'0');
            }
            cIndx--;
        }

        for(char c: ans[curr]) fAns[curr].push_back(c);
    }
    answer = min(fAns[0], fAns[1]);
    
}










int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>v[0]>>v[1];
    ifd cout<<"a = "<<v[0]<<", b = "<<v[1]<<endl;
    n=v[0].size(), m=v[1].size();
    int k=disMatch();
    ifd cout<<"vea que matchean "<<k<<" digitos"<<endl;
    res(k);
    
    bool pos=false;
    
    for(char c:answer) {
        if (c!='0') {
            pos=true;
            cout<<c;
        }
        else {
            if (pos) cout<<c;
        }
    }

    if (!pos) cout<<0;
    cout<<endl;


}
