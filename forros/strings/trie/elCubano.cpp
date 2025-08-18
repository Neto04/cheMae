// código fumado de Teruel
#include <bits/stdc++.h> 
#define ll long long
#define forr(i, a, b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i, 0, n)
#define debug 1
#define ifd if(debug)
using namespace std;


struct node {
    // nxt[x] me dice el nodo al que voy si 
    // estoy en mi nodo actual y me encuentro la letra x
    unordered_map<int, int> nxt;
    // me dice cuántas letras tiene de hijos x
    int tam;
    node():tam(0) {}  
};

void Add(vector<node> &trie, string &s) {
    int curr = 0;
    for(int i=0; i<s.size(); i++) {
        int c=s[i];
        if (!trie[curr].nxt.count(c)) {
            trie[curr].tam++;
            trie[curr].nxt[c]=trie.size();
            trie.emplace_back();
        }

        curr=trie[curr].nxt[c];
    }
}





int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    int n; cin>>n;
    vector<string> v(n);
    vector<node> trie(1);
    // usted ocupa meterle un caracter extra de final de palabra
    // al end de cada palabra
    forn(i, n) {
        cin>>v[i];
        v[i] += ('z' + 1);
        Add(trie, v[i]);
    }

}