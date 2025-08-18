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

// el window abarca de [l, r]
vector<int> solve(vector<int>& v, int l, int r) {
    ifd {
        cout<<"estoy solving window "<<l<<", "<<r<<endl;
        cout<<"sobre el vector"<<endl;
        for(auto u:v) cout<<u<<" ";
        cout<<endl;
    }
    vector<int> ans;
    // {v[i], i}
    deque<ii> dq;
    for(int i=l; i<=r; i++) {
        while (!dq.empty() and dq.back().first<=v[i]) dq.pop_back();
        
        dq.push_back({v[i],i});
    }

    ifd {
        cout<<"ahorita el window se ve"<<endl;
        for (auto u:dq) cout<<u.first<<" ";
        cout<<endl;
    }
    ans.push_back(dq.front().first);
    l++; r++;
    while (r<v.size()) {
        ifd cout<<"en "<<r<<" veo a "<<v[r]<<endl;
        while (!dq.empty() and (dq.back().first<=v[r] or (dq.back().second<l))) {
            ifd cout<<"saco a ("<<dq.back().first<<", "<<dq.back().second<<")"<<endl;
            dq.pop_back();
        }
        while (!dq.empty() and dq.front().second<l) {
            ifd cout<<"saco a ("<<dq.front().first<<", "<<dq.front().second<<")del frente porque ya no es relevante"<<endl;
            dq.pop_front();
        }

        dq.push_back({v[r], r});
        ans.push_back(dq.front().first);
        l++; r++;
    }
    ifd {
        
        cout<<"de donde ans se ve:"<<endl;
        for(auto u:ans) cout<<u<<" ";
        cout<<endl;
    }
    return ans;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    ifd cout<<"n = "<<n<<", m="<<m<<endl; 
    vector<vector<int>> v(n, vector<int> (m));
    forn(i, n) forn(j, m) cin>>v[i][j];
    int hor, ver;
    cin>>ver>>hor;
    // quiero que para cada fila saque el max tirando el window
    vector<vector<int>> ans1(n);
    forn(i, n) {
        ans1[i]=solve(v[i], 0, hor-1);
        ifd {
            cout<<"la fila "<<i<<" se ve "<<endl;
            for(auto u:ans1[i]) cout<<u<<" ";
            cout<<endl;
        }
    }
    int nn=n-ver+1, mm=m-hor+1; 
    ifd cout<<"vea que nn = "<<nn<<", mm = "<<mm<<endl;

    vector<vector<int>> ansF(nn, vector<int> (mm));

    forn(j, mm) {
        ifd cout<<"VIENDO LA COLUMNA "<<j<<endl;
        vector<int> curr;
        forn(i, n) curr.push_back(ans1[i][j]);
        
        ifd {
            cout<<"la columna "<<j<<" ahorita se ve: "<<endl;
            forn(i, n) cout<<curr[i]<<" ";
            cout<<endl;
        }
        vector<int> temp=solve(curr, 0, ver-1);
        ifd {
            cout<<"de donde la columna "<<j<<" ahora se ve:"<<endl;
            forn(i, nn) cout<<temp[i]<<" ";
            cout<<endl;
        }
        forn(i, nn) ansF[i][j]=temp[i];

    }
    ifd cout<<"DE DONDE EL RESULTADO FINAL ES "<<endl;
    forn(i, nn) {
        forn(j, mm) {
            cout<<ansF[i][j];
            if (j<mm-1) cout<<" ";
        }
        cout<<"\n";
    }


}
