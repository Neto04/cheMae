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
vector<int> freq(3*1e6);
int maxFreq=0;
struct node {
    // nxt[x] me dice el nodo al que voy si
    // estoy en mi nodo actual y me encuentro la letra x
    unordered_map<int, int> nxt;
    // me dice cuántas letras tiene de hijos x
    // OJO: la raíz tiene tam =0, y finales =0
    int tam;
    // me dice cuántos maes terminan en ese nodo
    int finales;
    node() : tam(0), finales(0) {}
};


bool isFinal(node& nodo) {return nodo.finales==nodo.tam;}
void Add(vector <node> &trie, string &s) {
    int curr = 0;
    for (int i = 0; i < s.size(); i++) {
        freq[curr]++;
        maxFreq=max(maxFreq, freq[curr]);
        int c = s[i];
        if (!trie[curr].nxt.count(c)) {
            trie[curr].nxt[c] = trie.size();
            trie.emplace_back();
        }
        curr = trie[curr].nxt[c];
        trie[curr].tam++;
    }
    trie[curr].finales++;
}







int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vector<node> trie(1);
    forn(i, n) {
        string s; cin>>s;
        Add(trie, s);
    }
    int ans=0;
    for(int i=1; i<=3*1e6; i++) if (freq[i]==n) ans++;
    cout<<ans<<endl;




}
