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

    string s; 
    cin>>s;
    string s1 = "", s2 = "";
    s1 += s[0]; s1 += s[1];
    s2 += s[3]; s2 += s[4];

    int h1 = stoi(s1), m1 = stoi(s2);

    cin>>s;
    s1 = "", s2 = "";
    s1 += s[0]; s1 += s[1];
    s2 += s[3]; s2 += s[4];

    int h2 = stoi(s1), m2 = stoi(s2);

    int ans = 0;
    // Si mis minutos son mas grandes muevo primero los minutos
    if (m1 > m2) {
        while (m1 != m2) {
            m1++;
            ans++;
            if (m1 == 60) {
                m1 = 0;
                h1++;
                if (h1 == 24) h1 = 0;
            }
        }
        while (h1 != h2) {
            h1++;
            ans++;
            if (h1 == 24) h1 = 0;
        }
    } else {
        // Si no muevo primero las horas
        while (h1 != h2) {
            h1++;
            ans++;
            if (h1 == 24) h1 = 0;
        }
        while (m1 != m2) {
            m1++;
            ans++;
            if (m1 == 60) {
                m1 = 0;
                h1++;
                if (h1 == 24) h1 = 0;
            }
        }
    }

    cout<<ans<<"\n";

    return 0;
}
