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


bool isLower(char c) {
    return (c>='a' and c<='z');
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    getline(cin, s);

    cout<<"What is the name of your team?"<<endl;
    cout<<"Our name is "<<s<<"."<<endl;
    cout<<"My apologies, I did not understand. What is your team name?"<<endl;
    cout<<"We are team "<<s<<"."<<endl;
    cout<<"I am really sorry. Could you please repeat it once again?"<<endl;
    cout<<"WE ARE TEAM ";
    for(char c:s) {

        if (isLower(c)) {
            c=toupper(c);
            cout<<c;
        }
        else cout<<c;
    }

    cout<<"!!!"<<endl;
    cout<<"Oh, now I see. Here are your badges. Good luck!"<<endl;




}
