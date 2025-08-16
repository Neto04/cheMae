#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define sz(x) (int)((x).size())

mt19937 rng(time(nullptr));

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash {
  const uint64_t C = ll(4e18 * acos(0)) + 71;
  const int RANDOM = rng();
  ll operator()(ll x) const { 
    return __builtin_bswap64((x ^ RANDOM) * C); 
  }
};
template <class K, class V> 
using ht = gp_hash_table<K, V, chash>;
template <class K, class V>
V get(ht<K, V>& u, K x) {
  auto it = u.find(x);
  return it == end(u) ? 0 : it->second;
}

using ul = uint64_t;

ul rand64() {
  return uniform_int_distribution<int64_t>(0, INT64_MAX)(rng);
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);

  int tt; cin >> tt;

  while (tt--) {
    string a, b; cin >> a >> b;

    vector<ul> chash(26);
    for (int i = 0; i < 26; i++)
      chash[i] = rand64();
    
    vector<ul> hashB(sz(b));
    for (int i = 0; i < sz(b); i++) {
      hashB[i] = chash[b[i] - 'a'];
      if (i != 0) hashB[i] += hashB[i - 1];
    }

    vector<ul> hashA(sz(b));
    for (int i = 0; i < sz(b); i++) {
      hashA[i] = chash[a[i] - 'a'];
      if (i != 0) hashA[i] += hashA[i - 1];
    }

    ht<ul, int> cnt;
    for (int i = 0; i < sz(b); i++) {
      for (int j = i; j < sz(b); j++) {
        auto current = hashB[j] - (i ? hashB[i - 1] : 0);
        cnt[current] = get(cnt, current) + 1;
      }
    }

    ul res = 0;
    for (int i = 0; i < sz(a); i++) {
      for (int j = i; j < sz(a); j++) {
        auto current = hashA[j] - (i ? hashA[i - 1] : 0);
        res += get(cnt, current);
      }
    }

    cout << res << "\n";
  }
}
