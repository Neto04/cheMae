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

    vector<int> freq(15,4);

    int n; cin>>n;
    int M = 0, J = 0;
    int carta;

    cin>>carta; freq[carta]--; J += min(carta, 10);
    cin>>carta; freq[carta]--; J += min(carta, 10);
    cin>>carta; freq[carta]--; M += min(carta, 10);
    cin>>carta; freq[carta]--; M += min(carta, 10);
    for (int i = 0; i < n; i++) {
        cin>>carta; freq[carta]--; 
        J += min(carta, 10);
        M += min(carta, 10);
    }

    for (int i = 1; i <= 13; i++) {
        if (freq[i]) {
            int valor = i; if (valor > 10) valor = 10;
            if (M + valor == 23 or (M+valor <= 23 and J+valor > 23)) {
                cout<<min(i, 10)<<"\n";
                return 0;
            }
        }
    }
    cout<<-1<<"\n";

    return 0;
}
