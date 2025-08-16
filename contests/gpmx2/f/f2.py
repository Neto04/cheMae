from functools import lru_cache

MOD = 10**9 + 7

def modinv(x):
    return pow(x, MOD - 2, MOD)

# contar (a, b) ∈ [0, A] × [0, B] con a ^ b ≤ K usando DP
def count_pairs_leq(A, B, K):
    @lru_cache(maxsize=None)
    # i el bit que revisa
    # ta si ya de fijo es menor
    # tb si ya de fijo es menor
    # tk si ya de fijo es menor
    def f(i, ta, tb, tk):
        if i < 0:
            return 1
        res = 0
        # se fija en el i-ésimo bit de A, de B y de K
        abit = (A >> i) & 1
        bbit = (B >> i) & 1
        kbit = (K >> i) & 1
        # para xa de 0 a 1
        for xa in (0, 1):
            # 
            if not ta and xa > abit: continue
            nta = ta or (xa < abit)
            for xb in (0, 1):
                if not tb and xb > bbit: continue
                ntb = tb or (xb < bbit)
                xk = xa ^ xb
                if not tk and xk > kbit: continue
                ntk = tk or (xk < kbit)
                res += f(i - 1, nta, ntb, ntk)
        return res
    if A < 0 or B < 0 or K < 0:
        return 0
    return f(30, False, False, False)

# Inclusion-Exclusion
def count_xor_leq(x1, y1, x2, y2, K):
    return (
        count_pairs_leq(y1, y2, K)
      - count_pairs_leq(x1 - 1, y2, K)
      - count_pairs_leq(y1, x2 - 1, K)
      + count_pairs_leq(x1 - 1, x2 - 1, K)
    )

def count_triplets_with_xor_zero(x1, y1, x2, y2, x3, y3):
    return count_xor_leq(x1, y1, x2, y2, y3) - count_xor_leq(x1, y1, x2, y2, x3 - 1)

def solve():
    L1, R1, L2, R2, L3, R3 = map(int, input().split())

    total = (R1 - L1 + 1) * (R2 - L2 + 1) % MOD
    total = total * (R3 - L3 + 1) % MOD

    losing = count_triplets_with_xor_zero(L1, R1, L2, R2, L3, R3) % MOD
    winning = (total - losing + MOD) % MOD
    print(winning * modinv(total) % MOD)

solve()