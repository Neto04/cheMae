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
#define iter list<int>::iterator
#define debug 1
#define ifd if (debug)
#define iii pair<int, ii>


ll hPair(int l, int r) {
    return l*1000 + r;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);


    int tC; cin>>tC;
    while (tC--) {
        
        int n, k; cin>>n>>k;
        // dado un id, me dice qué valor tiene
        vector<int> valor(1e6);
        // me tira el id del mae a la izq de un given id
        vector<int> idAnt(1e6, -1);
        // me tira el id del mae a la der de un given id
        vector<int> idSig(1e6, -1);
        // al inicio los ids van de 0 a n
        // dados [l, r], me dice los ids de los maes que forman [l, r]
        map<ii, set<ii>> mapota;
        // given [l, r] me dice la freq de ese pair
        // OJO: los estoy guardando negativos para que el orden ordene bien
        map<ii, int> freq;
        // set de (freq[l, r], l, r)
        set<iii> orden;
        // lea el valor de la gente vdd
        forn(i,n) cin>>valor[i];
        
        forn(i, n) {   
            // defina el idAnt de 
            idAnt[i]=i-1;
            if(i<n) {
                idSig[i]=i+1;
                mapota[{valor[i], valor[i+1]}].insert({i, i+1});
                if (freq[{valor[i], valor[i+1]}]) orden.erase({freq[{valor[i], valor[i+1]}], {valor[i], valor[i+1]}});
                orden.insert({--freq[{valor[i], valor[i+1]}], {valor[i], valor[i+1]}});
            }
        }
        
        int idN = n;
        // me dice cuantas operaciones exitosas se han realizado
        int nOp=0;
        vector<iii> ans;
        for(nOp; nOp<k; nOp++) {
            // sean l, r los maes que tiene ahorita
            int l, r; tie(l, r) = (*(orden.begin())).second;
            // esto es solo para ver si ya todo el mundo tiene freq 1
            int cFreq=(*(orden.begin())).first;
            orden.erase({cFreq, {l, r}});
            ans.push_back({cFreq, {l, r}});
            if (cFreq==-1) break;
            for(ii u:mapota[{l, r}]) {
                // sean idL y idR los ids respectivos de l y r
                int idL, idR; tie(idL, idR) = u;
                int cValor = 255+nOp, cId = idN++;
                // guarde que para ese id, su anterior es el anterior de l
                idAnt[cId]=idAnt[idL];
                // guarde que para ese id, su siguiente es el siguiente de r
                idSig[cId]=idSig[idR];


                // PENSAMOS PRIMERO EN [ANT, L]
                // si existía alguien antes de l
                if (idAnt[idL]!=-1) {
                    // la id del anterior
                    int ant = idAnt[idL];
                    // el valor del anterior
                    int vAnt = valor[idL];
                    // EMPEZAMOS QUITANDO A [ANT, L] DE TODOS LADOS
                    // saquelo de las ocurrencias de (vAnt, l)
                    mapota[{vAnt, l}].erase({ant, idL});
                    // actualice el orden
                    // primero saque de orden esa freq, valores
                    orden.erase({freq[{vAnt, l}], {vAnt, l}});
                    // actualice freq
                    freq[{vAnt, l}]++;
                    // si aun hay ocurrencias, vuelva a meterlo, con freq actualizado
                    if (freq[{vAnt, l}]) orden.insert({freq[{vAnt, l}], {vAnt, l}});

                    // AHORA VAMOS A METER [ANT, VALOR] EN TODOS LADOS
                    idSig[ant] = cId;
                    // meta en el mapa que mapea vAnterior, valor una ocurrencia de este mae
                    mapota[{vAnt, cValor}].insert({ant, cId});
                    // si había aparecido antes, sáquelo
                    if (freq[{vAnt, cValor}]) orden.erase({freq[{vAnt, cValor}], {ant, cId}});
                    // actualice freq
                    freq[{vAnt, cValor}]--;
                    // ahora sí, metalo con freq actualizado
                    orden.insert({freq[{vAnt, cValor}], {ant, cId}});
                }

                // AHORA SÍ, PURO PINCHE MEXICO, VAMOS CON [R, SIG]
                // si existía alguien desp de r
                if (idSig[idR]!=-1) {
                    // la id del siguiente
                    int sig = idSig[idR];
                    // el valor del siguiente
                    int vSig = valor[idR];
                    // EMPEZAMOS QUITANDO A [R, SIG] DE TODOS LADOS
                    // saquelo de las ocurrencias de (r, vSig)
                    mapota[{r, vSig}].erase({idR, sig});
                    // actualice el orden
                    // primero saque de orden esa freq, valores
                    orden.erase({freq[{r, vSig}], {r, vSig}});
                    // actualice freq
                    freq[{r, vSig}]++;
                    // si aun hay ocurrencias, vuelva a meterlo, con freq actualizado
                    if (freq[{r, vSig}]) orden.insert({freq[{r, vSig}], {r, vSig}});

                    // AHORA VAMOS A METER [VALOR, SIG] EN TODOS LADOS
                    idAnt[sig] = cId;
                    // meta en el mapa que mapea valor, vSig una ocurrencia de este mae
                    mapota[{cValor, vSig}].insert({cId, sig});
                    // si había aparecido antes, sáquelo
                    if (freq[{cValor, vSig}]) orden.erase({freq[{cValor, vSig}], {cId, sig}});
                    // actualice freq
                    freq[{cValor, vSig}]--;
                    // ahora sí, metalo con freq actualizado
                    orden.insert({freq[{cValor, vSig}], {cId, sig}});
                }
                
            }

        }

        cout<<ans.size()<<"\n";
        for(auto u:ans) 
            cout<<u.second.first<<" "<<u.second.second<<" "<<-u.first<<endl;
        
        

    }

}
