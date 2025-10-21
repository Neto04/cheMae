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
typedef pair<ll, ll> ii;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 0
#define ifd if (debug)

int T = 0;
int n;
string ans = "";
// {numero, cantidad de 1s que le he agregado}
set<pair<ii,int>> s;
vector<ii> v;

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    int unos = 0;
    forn(i,n) {
        int x; cin>>x;
        if (x == 1) unos++;
        else v.push_back({x,0});
    }

    if (unos == 4 and v.empty()) {
        cout<<"(1+1+1+1)"<<endl;
        return 0;
    }

    // Elimino los dos
    sort(v.begin(),v.end());
    reverse(v.begin(), v.end());
    for (int i = v.size()-1; i >= 0; i--) {
        if (unos > 0 and v[i].first == 2) {
            v.pop_back();
            i = v.size();
            v.push_back({3,1});
            unos--;
        }
    }

    // Agrupo los unos
    int grupos = unos/3;
    forn(i,grupos) {
        v.push_back({3,3});
        unos -= 3;
    }

    if (unos == 2) {
        v.push_back({2,2});
    } else if (unos == 1) {
        sort(v.begin(),v.end());
        reverse(v.begin(), v.end());
        int num = v[v.size()-1].first, count = v[v.size()-1].second;
        v.pop_back();
        v.push_back({num+1, count+1});
    }

    ifd cout<<"Ya me quede sin unos"<<endl;

    for (const ii& p : v) {
        int num = p.first, count = p.second;
        if (count == 0) {
            ans.append(to_string(num));
            ans.push_back('*');
        } else {
            ans.push_back('(');
            if (num-count != 0) {
                ans.append(to_string(num-count));
                ans.push_back('+');
            }
            forn(i,count) ans.append("1+");
            ans.pop_back();
            ans.push_back(')');
            ans.push_back('*');
        }
    }

    if (ans[ans.size()-1] == '*') ans.pop_back();

    cout<<ans<<"\n";

    return 0;
}
