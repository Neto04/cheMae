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

int get(int a, int b, int c) {
    if (a == b) return a;
    else if (a == c) return a;
    else if (b == c) return c;
    return max(a, max(b, c));
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;

    deque<int> a, b, c;
    cin>>s;
    for (char x : s) {
        if ((x-'0') == 1) a.push_back(1);
        else if ((x-'0') == 2) a.push_back(2);
        else if ((x-'0') == 3) a.push_back(3);
    }
    cin>>s;
    for (char x : s) {
        if ((x-'0') == 1) b.push_back(1);
        else if ((x-'0') == 2) b.push_back(2);
        else if ((x-'0') == 3) b.push_back(3);
    }
    cin>>s;
    for (char x : s) {
        if ((x-'0') == 1) c.push_back(1);
        else if ((x-'0') == 2) c.push_back(2);
        else if ((x-'0') == 3) c.push_back(3);
    }

    vector<int> ans;
    while (!a.empty() or !b.empty() or !c.empty()) {
        int x = -1, y = -2, z = -3;
        if (!a.empty()) x = a.front();
        if (!b.empty()) y = b.front();
        if (!c.empty()) z = c.front();

        int next = get(x, y, z);
        ans.push_back(next);

        if (!a.empty()) if (a.front() == next) a.pop_front();
        if (!b.empty()) if (b.front() == next) b.pop_front();
        if (!c.empty()) if (c.front() == next) c.pop_front();
    }

    for (int& x : ans) cout<<x;
    cout<<"\n";

    return 0;
}
