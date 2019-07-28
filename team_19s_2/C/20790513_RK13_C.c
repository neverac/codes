T = input()
T = int(T)
sum = []
sum.append(1)
sum.append(1)
for i in range(2, 302):
    sum.append(sum[i - 1] * i)

for i in range(0, T):
    str = input()
    t = str.split(' ')
    n = int(t[0])
    k = int(t[1])
    d = int(t[2])
    ss = sum[n] // (sum[n - k] * sum[k])
    tt = int(ss)
    ans = []
    b = []
    a = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'A', 'b', 'C', 'D', 'E', 'F']
    while True:
        s = tt // d  # 商
        y = tt - (s * d) # 余数
        b = b + [y]
        if s == 0:
            break
        tt = s
    b.reverse()
    for i in b:
        print(a[i], end='')
    print()