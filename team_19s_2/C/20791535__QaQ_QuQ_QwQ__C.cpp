#include<bits/stdc++.h>
using namespace std;
int const maxn=305;
int n,d,k,c[maxn][maxn][100];
inline int get_num(){
	char ch;
	int num=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
	return num;
}
void print(int const a[]){
	int i=a[0];
	while(a[i]<=0)i--;
	for( ;i>0;i--)printf("%d",a[i]);
	printf("\n");
}
void fu(int x,int y,int z){
	int u=0;
	while(z){
		u++;
		c[x][y][u]=z%10;
		z/=10;
	}
	c[x][y][0]=u;
}
void add(int const  a[],int const b[],int c[]){
	c[0]=max(a[0],b[0]);
	for(int i=1;i<=c[0];i++)c[i]=a[i]+b[i];
	for(int i=1;i<=c[0];i++){
		c[i+1]+=c[i]/10;c[i]%=10;
	}
	if(c[c[0]+1]>0)c[0]++;
}
void getc(){
	for(int i=0;i<maxn;i++){
		fu(i,0,1);fu(i,i,1);fu(i,1,i);
	}
	for(int i=2;i<maxn;i++){
		//int u=i/2;
		for(int j=2;j<i;j++){
			add(c[i-1][j-1],c[i-1][j],c[i][j]);
			
			//for(int q=1;q<=c[i][j][0];q++)
			//	c[i][i-j][q]=c[i][j][q];
			//c[i][i-j][0]=c[i][j][0];
			//if(i<30){printf("%d %d :",i,j);
			//print(c[i][j]);}
		}
	}
}
//int a[maxn],b[maxn];
/*
int cmp(int a[],int b[]){
	if(a[0]>b[0])return 1;
	if(b[0]>a[0])return -1;
	for(int i=a[0];i>0;i--){
		if(a[i]>b[i])return 1;
		if(a[i]<b[i])return -1;
	}
	return 0;
}*/

int res[maxn],shang[maxn],a[105];
void solve(int b[]){
	memset(res,0,sizeof res);
	int q=0,p;
	bool flag=1;
	a[0]=b[0];a[a[0]+1]=0;
	for(int i=1;i<=b[0];i++)a[i]=b[i];
	//print(a);
	while(a[0]){
		flag=1;
		p=0;
		for(int i=a[0];i>=1;i--){
			a[i]=a[i]+10*a[i+1];
			shang[i]=(a[i])/d;
			if(flag&&shang[i]){flag=0;p=i;}
			a[i]%=d;
		}
		res[++q]=a[1];
		//int p=0;
		for(int i=1;i<=p;i++)a[i]=shang[i];
		a[0]=p;a[p+1]=0;
	}
	res[0]=q;
	//cout<<q<<endl;
	print(res);
}
int main(){
	getc();
	int t;
	t=get_num();

//	print(c[300][150]);
//	cout<<c[300][150][0]<<endl;
	while(t--){
		n=get_num(),k=get_num(),d=get_num();
		solve(c[n][k]);
	}
	return 0;
}

