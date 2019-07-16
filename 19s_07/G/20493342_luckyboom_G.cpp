#include<bits/stdc++.h>
using namespace std;
int const maxn=1005;
int ma[maxn][maxn],n,ans;
int fx, fy;
bool flag[maxn][maxn],ok;
inline int get_num(){
	char ch;
	int num=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
	return num;
}
void tian(int nowx,int nowy){
	for(int j=nowx;j>=fx;j--)
	for(int i=nowy;i>=fy;i--)
	{
		if(flag[j][i])return ;
		flag[j][i]=1;
	}
}
bool dfs(int nowx,int nowy,int si){
	if(si!=1) {
		if(nowx!=fx&&ma[nowx][nowy]!=ma[nowx-1][nowy]+1){ok=false;return 0;}
		if(nowy!=fy&&ma[nowx][nowy]!=ma[nowx][nowy-1]+1){ok=false;return 0;}
	}

	/*	if(ma[nowx][nowy]!=ma[nowx-1][nowy]+1||ma[nowx][nowy]!=ma[nowx][nowy-1]+1){
		ok=false;return 0;
	}*/
	if(nowx==si+fx-1&&nowy==fy&&ok){
		//cout<<"ok:"<<nowx<<' '<<nowy<<' '<<si<<endl;
		if(si>ans)ans=si;
		for(int i=fx;i<=fx+si;i++){
			if(dfs(i,fy+si,si+1)==0){tian(i-1,fy+si-1);
				//cout<<"tian"<<i-1<<' '<<fy+si-1<<' '<<endl;
			}
		}
		for(int i=fy+si;i>=fy;i--){
			if(dfs(fx+si,i,si+1)==0){tian(fx+si-1,i-1);
			//	cout<<"tian"<<fx+si-1<<' '<<i-1<<' '<<endl;
			}
		}
	}
	return 1;
}
int main(){
	n=get_num();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ma[i][j]=get_num();
	for(int i=1;i<=n;i++){
		ma[0][i]=ma[1][i]-1;ma[n+1][i]=-1;
		ma[i][0]=ma[1][i]-1;ma[i][n+1]=-1;
	}
	if(n==0)printf("0\n");
	else{
		ans=1;
		/*for(int i=2;i<=n+1;i++)
			for(int x=1;x<=n&&x<i;x++){
				int y=i-x;
				if(!flag[x][y]){
					ok=true;
					fx=x,fy=y;
					dfs(x,y,1);
				}
			}*/
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(!flag[j][i]){
					//cout<<"use:"<<j<<' '<<i<<endl;
					ok=true;
					fx=j,fy=i;
					dfs(j,i,1);
				}
			}
			for(int j=1;j<i;j++){
				if(!flag[i][j]){
					//cout<<"use:"<<i<<' '<<j<<endl;
					ok=true;
					fx=i,fy=j;
					dfs(i,j,1);
				}
			}
		}
		cout<<ans<<endl;
	}
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<flag[i][j]<<' ';
		cout<<endl;
	}*/
	
	return 0;
}