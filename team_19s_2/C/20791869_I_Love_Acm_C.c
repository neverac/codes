n = int(input())
for i in range(1,n+1):
    s, k, d = map(int,input().split())
    x = 1
    for j in range(s-k+1,s+1):
        x = x * j
    for j in range(1,k+1):
        x = x // j
    q = []
    while x != 0:
        q += [int(x % d)]
        x = x // d
    for j in range(0,len(q)):
        print(q[len(q)-j-1],end='')
    print()

