#include<bits/stdc++.h>
using namespace std;
int const maxn=1e3+10;
int n,h,w,cou=0,ans=0,disx[4]={0,0,1,-1},disy[4]={1,-1,0,0};
string s[maxn];
struct node{
	int x,y;
	node(int a=0,int b=0):
		x(a),y(b){}  
};
queue <node> q[2];
void work(){
	int sh=h*w;
	bool flag=0,flag2=1;
	if(cou==sh)return ;
	node z;
	int nowx,nowy;
	while(cou<sh){
		while(!q[flag].empty()){
			z=q[flag].front();q[flag].pop();
			for(int i=0;i<4;i++){
				nowx=z.x+disx[i];nowy=z.y+disy[i];
				if(nowx>=0&&nowx<h&&nowy>=0&&nowy<w&&s[nowx][nowy]=='.'){
					s[nowx][nowy]='#';q[flag2].push(node(nowx,nowy));
					cou++;
				}
			}
		}
		ans++;
		flag=!flag;flag2=!flag2;
	}
}
int main(){
	scanf("%d%d",&h,&w);
	node z;
	for(int i=0;i<h;i++){
		cin>>s[i];
		for(int j=0;j<w;j++){
			if(s[i][j]=='#'){
				cou++;
				z.x=i;z.y=j;
				q[0].push(z);
			}
		}
	}
	work();
	cout<<ans<<endl;
	return 0;
}