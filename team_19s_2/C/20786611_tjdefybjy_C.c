C=[]
def setup():
    global C
    n=300
    C=[[0 for i in range(n+1)] for i in range(n+1)]
    for i in range(0,n+1):
        C[i][0]=1
        C[i][i]=1
        if i>=1:
            C[i][1]=i
        for j in range(2,i):
            C[i][j]=C[i-1][j-1]+C[i-1][j]
    '''
    for i in range(0,10):
        for j in range(0,i+1):
            print(C[i][j],end=' ')
        print()
    '''
def doing():
    n,k,d=map(int,input().split())
    x=C[n][k]+0
    a=[]
    while x!=0:
        a.append(str(x%d))
        x//=d
    a.reverse()
    print(''.join(a))
setup()
T=int(input())
for t in range(T):
    doing()
