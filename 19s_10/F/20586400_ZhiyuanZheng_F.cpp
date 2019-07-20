#include <bits/stdc++.h>
using namespace std;
int gh[1100][1100];
int distx[1100],disty[1100];
bool vis[1100];
//int f[1100][1100];
int n,m,s,t;
queue <int> q;
void SPFA1(){
	memset(vis,0,sizeof vis);
	for (int i=1;i<=n;i++) distx[i]=1e5;
	distx[s]=0;
	vis[s]=1;
	while (!q.empty()) q.pop();
	q.push(s);
	while (!q.empty()){
		int x=q.front();
		q.pop();
		for (int i=1;i<=n;i++){
			if (gh[x][i]<1e5){
				if (distx[x]+gh[x][i]<distx[i]){
					distx[i]=distx[x]+gh[x][i];
					if (!vis[i]) {
						vis[i]=1;
						q.push(i);
					}
				}
			}
		}
		vis[x]=0;
	}
}
void SPFA2(){
	memset(vis,0,sizeof vis);
	for (int i=1;i<=n;i++) disty[i]=1e5;
	disty[t]=0;
	vis[t]=1;
	while (!q.empty()) q.pop();
	q.push(t);
	while (!q.empty()){
		int x=q.front();
		q.pop();
		for (int i=1;i<=n;i++){
			if (gh[x][i]<1e5){
				if (disty[x]+gh[x][i]<disty[i]){
					disty[i]=disty[x]+gh[x][i];
					if (!vis[i]) {
						vis[i]=1;
						q.push(i);
					}
				}
			}
		}
		vis[x]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>s>>t;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			gh[i][j]=1e5;
	}
		
	for (int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
			gh[a][b]=1;
			gh[b][a]=1;
	}
	//cout<<gh[0][0]<<endl;
	for (int i=1;i<=n;i++) gh[i][i]=0;
	SPFA1();
	SPFA2();
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++){
//			for (int k=1;k<=n;k++){
//				gh[i][j]=min(gh[i][j],gh[i][k]+gh[k][j]);
//			}
//		}
//	}
	
	int mind=disty[s];
	long long anss=0;
	for (int i=1;i<=n;i++){ 
		for (int j=1;j<=n;j++){
			if (gh[i][j]!=1&&i!=j){
				int s1=distx[i]+disty[j]+1;
				int s2=distx[j]+disty[i]+1;
				if (min(s1,s2)>=mind) anss++;
//				if (gh[s][i]+gh[j][t]+1>=gh[s][t]&&gh[s][j]+gh[i][t]+1>=gh[s][t]) anss++;
			}
		}
	}
	cout<<anss/2<<endl;
	return 0;
}