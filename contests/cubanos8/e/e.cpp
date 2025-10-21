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


struct Hash {
    // usted va a tener:
    // el P primo por el que va a multiplicar las varas
    int P=1777771;
    // el MOD1 y MOD2 por el que va a modular todo
    int MOD[2];
    // el inverso modular de P en MOD 1, y en MOD 2
	int PI[2];
    // el prefixHash del string en MOD1 y el otro en MOD 2 (UNO INDEXADO)
	vector<int> h[2];
    // esto va a ser PI ^ i mod MOD1 y MOD2
    vector<int> pi[2];
	Hash(string& s){
        // usamos el mod1, y el mod2
		MOD[0]=999727999;MOD[1]=1070777777;
        // el inv mult de p en mod1, y el inv mult de p en mod2
		PI[0]=325255434;PI[1]=10018302;
        // métales el tamaño correcto a c/u
		forr(k,0,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
		forr(k,0,2){
            // el hash al inicio es cero
			h[k][0]=0;
            // inv Mult ^ 0 = 1
            pi[k][0]=1;
            // p es la potencia que lleva ahorita
			ll p=1;
            // legalmente, arme el prefix hash
			forr(i,1,s.size()+1){
				h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
				pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
				p=(p*P)%MOD[k];
			}
		}
	}
    // saca el hash de [s, ..., e)
	ll get(int s, int e){
        // PARA MOD1:
        // h0 es el hash hasta e-1, quitándole el hash hasta s-1
		ll h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
        // vuélese los ceros del fondo
		h0=(1LL*h0*pi[0][s])%MOD[0];

        // PARA MOD2:
        // h1 es el hash hasta e-1, quitándole el hash hasta s-1
		ll h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
        // vuélese los ceros del fondo
		h1=(1LL*h1*pi[1][s])%MOD[1];
		return (h0<<32)|h1;
	}
};
// el size de los strings
int n;
string a, b;



// una vara que recibe dos strings: uno que va [l1, r1], y el otro de [l2, r2]. 
// Busca el primer punto en el que los hashes difieren
ll search(int l1, int r1, int l2, int r2, Hash& hs) {
    // a es un punto en el que de fijo no difieren, y b un punto en el que de fijo difieren
    ll a =-1, b= (r1-l1+1);
    while (b-a>1) {
        ll c = (a+b)/2;
        if (hs.get(l1, l1+c+1)!=hs.get(l2, l2+c+2)) b=c;
        else a=c;
    }
    return b;
}

// le dice si el mae definido de [l1, r1] es > al de [l2, r2]
bool comparar(int l1, int r1, int l2, int r2, Hash& hs, string& cS) {
    int c = search(l1, r1, l2, r2, hs);
    return cS[l1+c]>cS[l2+c];
}







int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);




    int tC; cin>>tC;

    while (tC--) {
        int n; cin>>n;
        string a, b; cin>>a>>b;
        // suffix min desde i hasta n-1 (inclusivo)
        vector<char> sMin(a[n-1]);
        for(int i=n-2; i>=0; i--) sMin[i]=min(a[i], sMin[i+1]);
        bool done =false;
        int lastPos=0;
        char target;
        for(int i =0; i<n and !done; i++) {
            // si ese mae es < a lo que tenga b, gg
            if (a[i]<b[i]) {
                cout<<"Yes\n";
                done=true;
            }
            
            // si es >= de fijo quiere swappearlo con alguien
            if (a[i]>=b[i]) {
                // si puede cambiarlo con alguien menor a b[i], dele viaje con eso
                if (i+1<n and sMin[i+1]<b[i]) {
                    cout<<"Yes\n";
                    done=true;
                }
                // si lo puede cambiar por alguien que le genere un empate, 
                if (i+1<n and sMin[i+1]==b[i]) {
                    target=b[i];
                    lastPos=i;
                    break;
                }
                // si no lo puede cambiar con nadie (ya sea porque no tiene gente en frente, 
                // o porque nadie es menor) ripperoni
                else {
                    cout<<"No\n";
                    done=true;
                }
            }
        }
        // si ya encontró su respuesta, siga con su vida
        if (done) continue;
        // cuantos caracteres tiene al frente la vara que va a invertir
        int frente = n-(lastPos+1);
        // el punto hasta el cual quiere revisar 
        int end = n-1-lastPos;
        string a2=a;
        reverse(a2.begin(), a2.end());

















    }






}
