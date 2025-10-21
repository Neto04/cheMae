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

int n, m;
set<ll> allowed, denied;

// Transformar direccion a ll
pair<ll,ll> get(string& s) {
    string t = "";
    // xxx.xxx.xxx.xxx
    // 1e9, 1e6, 1e3, 1e1
    ll num = 0, ceros = 1e9, cant = -1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '.') {
            num += (ll)stoi(t)*ceros;
            ceros /= 1e3;
            t = "";
        } else if (c == '/'){
            num +=  (ll)stoi(t);
            t = "";
            for (int j = i+1; j < s.size(); j++) t += s[j];
            cant = (ll)stoi(t);
            break;
        } else {
            t += c;
        }
    }
    if (cant == -1) num += (ll)stoi(t);
    return {num,cant};
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    forn(i,n) {
        string tipo, s; 
        cin>>tipo;
        cin>>s>>s;
        pair<ll,ll> cosas = get(s);
        ll num = cosas.first, cant = (cosas.second == -1 ? -1 : 32-cosas.second);

        if (tipo == "allow") {
            // Si no esta baneado entonces lo permito
            if (denied.find(num) == denied.end()) {
                allowed.insert(num);
            }
            forn(k,cant-1) {
                num++;
                if (denied.find(num) == denied.end()) {
                    allowed.insert(num);
                }
            }
        } else {
            // Si no esta permitido entonces lo baneo
            if (allowed.find(num) == allowed.end()) {
                denied.insert(num);
            }
            forn(k,cant-1) {
                num++;
                if (allowed.find(num) == allowed.end()) {
                    denied.insert(num);
                }
            }
        }
    }

    ifd {
        cout<<"Permitidos"<<endl;
        for (auto x : allowed) cout<<x<<endl;
        cout<<"Baneados"<<endl;
        for (auto x : denied) cout<<x<<endl;
    }

    string ans = "";
    cin>>m;
    forn(i,m) {
        string s; cin>>s;
        pair<ll,ll> cosas = get(s);
        ll ip = cosas.first;
        if (denied.find(ip) != denied.end()) {
            ans += 'D';
            continue;
        }
        ans += 'A';
    }

    cout<<ans<<"\n";

    return 0;
}
