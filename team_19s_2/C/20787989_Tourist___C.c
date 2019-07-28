C=[]
for i in range(0,500):
    C.append([])
    for j in range(0,500):
        C[i].append(0)
C[1][0]=1
C[1][1]=1
for i in range(2,305):
    C[i][0]=1
    C[i][i]=1
    for j in range(1,i):
        C[i][j]=C[i-1][j-1]+C[i-1][j]

s=input().split()
t=int(s[0])
for i in range(0,t):
    s=input().split()
    n=int(s[0])
    m=int(s[1])
    d=int(s[2])
    ans=C[n][m]
    ttt=[]
    while ans>0:
        ttt.append(ans%d)
        ans=ans//d
    p=len(ttt)
    for s in range(0,p):
        print(ttt[p-s-1],end="")
    print("")
