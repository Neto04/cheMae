def min_steps(a, b):
    n = len(a)
    m = len(b)
    a = a.zfill(max(n, m))
    b = b.zfill(max(n, m))

    # scan from rightmost digit
    i = len(a) - 1
    last_carry_pos = -1
    for j in range(i, -1, -1):
        if int(a[j]) + int(b[j]) >= 10:
            last_carry_pos = len(a) - j  # position from right
            break

    if last_carry_pos == -1:
        return 0

    # now compute how many steps needed
    k = last_carry_pos
    while (k < len(a) and int(a[-k-1]) + int(b[-k-1]) == 9):
        k += 1

    mod = 10**k  # careful: only small k, otherwise rethink
    # but instead of pow, slice the string
    a_tail = int(a[-k:])
    b_tail = int(b[-k:])
    return min(mod - a_tail, mod - b_tail)



a=input()
b=input()

print(min_steps(a, b))