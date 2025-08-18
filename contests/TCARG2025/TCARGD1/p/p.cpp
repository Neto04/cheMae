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
    int tC; cin>>tC;
    while (tC--) {
        int n; cin>>n;
        vector<int> freq(n+1);
        // dada una columna, le dice quién está arriba y quién abajo
        vector<vector<int>> colV(2, vector<int>(n));
        // dado un Valor, le dice las dos columnas en las que está
        vector<vector<int>> vCol(n+1, vector<int>(2, -1));
        bool error=false;
        forn(i,n) {
            int x;
            cin>>x; 
            colV[0][i]=x;
            freq[x]++;
            if (vCol[x][0]==-1) vCol[x][0]=i;
            else vCol[x][1]=i;
            
        }
        forn(i,n) {
            int x;
            cin>>x;
            colV[1][i]=x;
            freq[x]++;
            if (vCol[x][0]==-1) vCol[x][0]=i;
            else vCol[x][1]=i;
            
        }

        for(int i=1; i<=n&&!error; i++) if (freq[i]!=2) error=true;
        ifd {
            cout<<"la vara se ve: "<<endl;
            forn(i,n) cout<<vCol[i][0]<<" "; cout<<endl;
            forn(i,n) cout<<vCol[i][1]<<" "; cout<<endl;
        }
        ifd {
            cout<<"la tabla original se ve:"<<endl;
            forn(i,2) {
                forn(j, n) cout<<colV[i][j]<<" ";
                cout<<endl;
            }
        }
        if (error) {
            cout<<"-1\n";
            continue;
        }
        // 
        vector<int> color(n+1);
        int cColor =1;

        for(int i=0; i<n and !error; i++) {
            if (color[i]) continue;
            
            // está pintando de color (cColor + pint)
            color[i]=cColor;
            queue<int> q; q.push(i);
            while (!q.empty()&&!error) {
                // ahorita está en la columna x
                int x=q.front(); q.pop();
                ifd cout<<"estoy en "<<x<<" que tiene color "<<color[x]<<endl;
                forn(pos,2) {
                    int val=colV[pos][x];
                    ifd cout<<"me fijo en "<<val<<endl;
                    // si los dos están en la misma columna, todo bien
                    if (val==colV[(pos+1)%2][x]) {
                        ifd cout<<"vea que está en la misma columna que el otro "<<val<<endl;
                        break;
                    }
                    // revise la otra ocurrencia de ese mae
                    int otro=vCol[val][0];
                    if (vCol[val][0]==x) otro=vCol[val][1];
                    ifd cout<<"la otra ocurrencia de eso está en "<<otro<<endl;
                    bool abajO=true; 
                    // ahora averigue si la otra ocurrencia esta arriba o abajo
                    if (colV[0][otro]==val) abajO=false;

                    // si están en el mismo orientacion, deben tener colores difrentes
                    if (abajO==pos) {
                        ifd cout<<"estan en la misma pos"<<endl;
                        if (color[otro]) {
                            ifd cout<<"el otro mae ya estaba pintado de color "<<color[otro]<<endl;
                            if (color[otro]==color[x]) {
                                ifd cout<<"rip, no podemos estar en la misma fila y tener el mismo color "<<endl;
                                error=true;
                            }
                            continue;
                        }
                        
                        // si no estaba pintado, píntelo
                        if (color[x]%2) color[otro]=color[x]+1;
                        else color[otro]=color[x]-1;
                        ifd cout<<"por lo que lo pinto de color "<<color[otro]<<endl;
                        q.push(otro);
                    }

                    // si están en distinta orientación, tienen el mismo color
                    else {
                        ifd cout<<"estan en orientaciones distintas, por lo que queda con color "<<color[x]<<endl;
                        // si tiene color, vea que sea el correcto
                        if (color[otro]) {
                            if (color[otro]!=color[x]) error=true;
                            continue;
                        }
                        // si no estaba pintado, píntelo
                        color[otro]=color[x];
                        q.push(otro);
                    }

                }
            }
            cColor+=2;
        }
        if (error){
            cout<<-1<<endl;
            continue;
        }
        ifd {
            cout<<"COLORES"<<endl;
            forn(i, n) cout<<color[i]<<" ";
            cout<<endl;
        }
        vector<int> freqColor(2*n+1);


        for(int i=0; i<n; i++) freqColor[color[i]]++; 

        set<int> aCambiar;
        
        for(int i=1; i<=2*n; i+=2) {
            if (!(freqColor[i]&&freqColor[i+1])) continue;
            if (freqColor[i]>=freqColor[i+1]) aCambiar.insert(i+1);
            else aCambiar.insert(i);
        }
        queue<int> porCambiar;
        forn(i, n) 
            if (aCambiar.find(color[i])!=aCambiar.end()) porCambiar.push(i); 
        ifd cout<<"RESPUESTA FINAL:"<<endl;
        cout<<porCambiar.size()<<endl;
        while(!porCambiar.empty()) {
            cout<<porCambiar.front()+1<<" ";
            porCambiar.pop();
        }
        cout<<endl;
    }
}
