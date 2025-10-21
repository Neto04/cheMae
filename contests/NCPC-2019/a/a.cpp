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

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s; cin>>s;
    int n; cin>>n;
    vector<ii> words;
    vector<string> palabras(n);
    forn(i, n) {
        string cS; cin>>cS;
        palabras[i]=cS;
        words.push_back({cS[0]-'a', cS[cS.size()-1]-'a'});
    }
    vector<vector<ii>> empieza(26), termina(26);

    for(int i=0; i<words.size(); i++) {
        ii u = words[i];
        empieza[u.first].push_back({u.second, i});
        termina[u.second].push_back({u.first, i});
    }
    ifd cout<<"no me he caido"<<endl;
    if (empieza[s[s.size()-1]-'a'].empty()) cout<<"?\n";
    else {
    
        bool won =false;
        int start = s[s.size()-1]-'a';
        int cAns = empieza[start][0].second;
        // curr es la palabra actual que empieza en a
        for(ii& curr:empieza[start]) {
            ifd cout<<"me fijo en terminar en "<<curr.first<<endl;
            int fin = curr.first;
            int cant = (fin==start);
            ifd cout<<"quiero saber si "<<cant<<" gente empieza en "<<fin<<endl;
            if (empieza[fin].size()==cant) {
                cAns=curr.second;
                won=true;
                break;
            }
        }

    

        cout<<palabras[cAns];
        if (won) cout<<"!";
        cout<<"\n";
    }



}
