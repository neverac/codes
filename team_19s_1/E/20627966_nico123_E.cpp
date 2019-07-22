#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL A[30],M[80][80],SS[80],S[80];
int main()
{
	LL T,i,N,cursor,j,L,Q,X0,Y0,X1,Y1,ql,qr,l,r,len,SS1,ans;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&L);
		for(i=0;i<L;i++)scanf("%lld",&A[i]);
		if(L%2==0)N=2LL*L;
		else N=L;
		cursor = 0;
		for (i = 0;i<2*N ; ++i) {
		    for (j = 0; j <= i; ++j) { 
		        M[j][i - j] = A[cursor];
		        cursor = (cursor + 1) % L;
		    }
		}
		memset(SS,0,sizeof(SS));
		for(i=0LL;i<N;i++)
		{
			for(j=0LL;j<N;j++)
			{
				SS[i]=SS[i]+M[i][j];
			}
		}
		scanf("%lld",&Q);
		while(Q--)
		{
			scanf("%lld %lld %lld %lld",&X0,&Y0,&X1,&Y1);
			ql=Y0;qr=Y1;ans=0LL;
			SS1=0LL;
			for(i=0;i<N;i++)
			{
				S[i]=0LL;
				if(ql%N==0)l=ql;
				else l=(ql/N+1LL)*N;
				if((qr+1LL)%N==0LL)r=qr;
				else r=(qr/N)*N-1LL;
				len=r-l+1LL;
				S[i]=SS[i]*(len/N);
				for(j=ql;j<=l-1;j++)S[i]+=M[i][j%N];
				for(j=r+1;j<=qr;j++)S[i]+=M[i][j%N];
				SS1+=S[i];
			}
			
			ql=X0;qr=X1;
			if(ql%N==0)l=ql;
			else l=(ql/N+1LL)*N;
			if((qr+1LL)%N==0LL)r=qr;
			else r=(qr/N)*N-1LL;
			len=r-l+1LL;
			ans=SS1*(len/N);
			for(j=ql;j<=l-1;j++)ans+=S[j%N];
			for(j=r+1;j<=qr;j++)ans+=S[j%N];
			printf("%lld\n",ans);
		}
	}
;;;
	return 0;
}
