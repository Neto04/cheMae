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

typedef pair<int,ll> il;

const int N = 1e6+5;
const ll MOD = 1e9+7;

vector<ll> F(2*N), I(2*N), v(2*N);

ll Exp(ll b, ll e, ll m) {
    ll r = 1;
    while (e) {
        if (e % 2) 
            r = r*b % m;
        b = b*b % m;
        e /=2;
    }
    return r;
}

ll Binom(ll n, ll k) {
    return ((F[n]*I[k] % MOD) * I[n-k]) % MOD;
}

ll catalan(ll x) {
    return ((Binom(x*2, x)*Exp(x+1, MOD-2, MOD))%MOD+MOD) % MOD;
}

il solve(int i) {
    ll gente = 1, res = 1;
    if (i == 0) return {-1,1LL};
    int j = i-1;
    while (j >= 0) {
        if (v[j] < v[i]) return {j, res*catalan(gente) % MOD};
        if (v[j] == v[i]) {
            gente++;
            j--;
            continue;
        }
        il temp = solve(j);
        j = temp.first;
        res *= temp.second;
        res %= MOD;
    }
    res *= catalan(gente);
    res %= MOD;
    return {-1, res};
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    F[0] = 1;
    for (ll i = 1; i < 2*N+5; i++) {
        F[i] = F[i-1]*i % MOD;
    }

    I[2*N-1] = Exp(F[2*N-1], MOD-2, MOD);
    for (ll i = 2*N-2; i >= 0; i--) {
        I[i] = I[i+1]*(i+1) % MOD;
    } 

    int n; cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }

    int i = n-1;
    ll ans = 1;
    while (i >= 0) {
        il temp = solve(i);
        i = temp.first;
        ans *= temp.second;
        ans %= MOD;
    }
    cout<<ans<<"\n";

    return 0;
}




hp_attack_legendary <- ggplot(na.omit(df), aes(attack, hp)) +
  geom_point(aes(color=is_legendary)) +
  geom_label_repel(data=subset(df, (attack > 150 | hp > 7.5) & is_legendary == 1), aes(label=name),
                   box.padding = 0.35, point.padding = 0.5, segment.color = 'grey50') +
  geom_smooth(method = "lm")
print(hp_attack_legendary)
