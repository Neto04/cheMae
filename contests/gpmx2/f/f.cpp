#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;

#define debug 1
#define ifd if (debug)

// inverso modular usando peq. teorema de fermat
int modinv(int x) {
    ll res = 1, base = x;
    int exp = MOD - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// contar (a, b) en [0, A] x [0, B] con a^b <= K usando DP
int count_pairs_leq(int A, int B, int K) {
    vector<vector<vector<vector<int>>>> dp(31, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, -1))));

    function<int(int, bool, bool, bool)> f = [&](int i, bool ta, bool tb, bool tk) {
        if (i < 0) return 1;
        if (dp[i][ta][tb][tk] != -1) return dp[i][ta][tb][tk];
        
        int res = 0;
        int abit = (A >> i) & 1;
        int bbit = (B >> i) & 1;
        int kbit = (K >> i) & 1;
        
        for (int xa : {0, 1}) {
            if (!ta && xa > abit) continue;
            bool nta = ta || (xa < abit);
            for (int xb : {0, 1}) {
                if (!tb && xb > bbit) continue;
                bool ntb = tb || (xb < bbit);
                int xk = xa ^ xb;
                if (!tk && xk > kbit) continue;
                bool ntk = tk || (xk < kbit);
                res = (res + f(i - 1, nta, ntb, ntk)) % MOD;
            }
        }
return dp[i][ta][tb][tk] = res;
    };

    if (A < 0 || B < 0 || K < 0) return 0;
    return f(30, false, false, false);
}

// Inclusion-Exclusion para contar parejas con XOR menor o igual a K
int count_xor_leq(int x1, int y1, int x2, int y2, int K) {
    return (count_pairs_leq(y1, y2, K) - count_pairs_leq(x1 - 1, y2, K) - count_pairs_leq(y1, x2 - 1, K) + count_pairs_leq(x1 - 1, x2 - 1, K) + MOD) % MOD;
}

// contar tripletas (a, b, c) con a^b^c = 0
int count_triplets_with_xor_zero(int x1, int y1, int x2, int y2, int x3, int y3) {
    return count_xor_leq(x1, y1, x2, y2, y3) - count_xor_leq(x1, y1, x2, y2, x3 - 1);
}

void solve() {
    int L1, R1, L2, R2, L3, R3;
    cin >> L1 >> R1 >> L2 >> R2 >> L3 >> R3;

    int total = (ll)(R1 - L1 + 1) * (R2 - L2 + 1) % MOD;
    total = (ll)total * (R3 - L3 + 1) % MOD;

    int losing = count_triplets_with_xor_zero(L1, R1, L2, R2, L3, R3) % MOD;
    int winning = (total - losing + MOD) % MOD;
    
    cout << (ll)winning * modinv(total) % MOD << endl;
}

int main() {
    solve();
    return 0;
}