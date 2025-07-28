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

const int LETRAS = 26;
const int N = 105;
int n;
vector<string> palabras;
int G[LETRAS][LETRAS];
int estado[LETRAS];

vector<char> ans;
set<char> faltan;
/*
Estados
0: No procesado
1: En procesamiento
2: Procesado
*/
// Retorna si hay error
bool dfs(char v) {
    estado[v-'a'] = 1;
    bool error = false;
    for (char u = 'a'; u <= 'z'; u++) {
        if (u != v and G[v-'a'][u-'a']) {
            if (estado[u-'a'] == 2) continue;
            ifd cout<<"Hay una arista de "<<v<<" a "<<u<<endl;
            if (estado[u-'a'] == 1) return true; // Hay un ciclo
            error = dfs(u);
            if (error) return true;
        }
    }
    estado[v-'a'] = 2;
    ans.push_back(v);
    faltan.erase(v);
    ifd cout<<"Se agrega a "<<v<<" a ans"<<endl;
    return false;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for (int i = 0; i < n; i++) {
        string s; cin>>s;
        palabras.push_back(s);
    }

    for (char c = 'a'; c <= 'z'; c++) faltan.insert(c);

    // Agregar todos los nodos al grafo
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ifd cout<<"Comparando palabras "<<i<<" y "<<j<<endl;
            int letra = 0;
            bool letraDif = false;
            // Busco la primera letra diferentes y agrego la arista
            while (letra < palabras[i].size() and letra < palabras[j].size() and !letraDif) {
                if (palabras[i][letra] != palabras[j][letra]) {
                    ifd cout<<"Difieren en la letra "<<letra<<endl;
                    int letra1 = palabras[i][letra]-'a', letra2 = palabras[j][letra]-'a';
                    ifd cout<<"Se agrega arista de "<<letra1<<" a "<<letra2<<endl;
                    G[letra1][letra2] = 1;
                    letraDif = true;
                }
                letra++;
            }
            // Si todas las letras son iguales pero la de arriba es mas grande entonces esta mal
            if (!letraDif and palabras[i].size() > palabras[j].size()) {
                cout<<"Impossible\n";
                return 0;
            }
        }
    }

    ifd cout<<"Sali de las aristas"<<endl;

    for (int c = 'a'; c <= 'z'; c++) estado[c-'a'] = 0;
    for (int c = 'z'; c >= 'a'; c--) {
        if (estado[c-'a'] == 0) {
            bool error = dfs(c);
            if (error) {
                cout<<"Impossible\n";
                return 0;
            }
        }
    }

    reverse(ans.begin(), ans.end());

    ifd cout<<"Top sort"<<endl;
    for(char c : ans) cout<<c;
    ifd cout<<endl<<"Faltan"<<endl;
    for (char c : faltan) cout<<c;
    cout<<"\n";

    return 0;
}
