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
    int tC; cin>>tC;
    while (tC--) {
        string s; cin>>s; int n=s.size();
        vector<int> freq(26);
        set<int> st;
        forn(i,n) {
            freq[s[i]-'a']++;
            st.insert(s[i]-'a');
        }
        bool won=false;
        string ans;
        forn(i, 26) {
            if (freq[i]==1) {
                won=true;
            
                ans.push_back(i+'a');
                for (char c:s) if (c-'a'!=i) ans.push_back(c);
                break;

            }
        }
        sort(s.begin(), s.end());

        if (!won) {
            // de fjio ocupa tener al menos tres letras
            if (st.size()>2) {
                won=true;
                ans.push_back(s[0]);
                
                for(char c:s) if (c!=s[0]) ans.push_back(c);
                for(int i=1; i<freq[s[0]-'a']; i++) ans.push_back(s[0]);
            }
        }

        if (won) cout<<"YES\n"<<ans<<"\n";
        else cout<<"NO\n";
        
    }


}
