#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E5+10;
const int INF=~0U>>1;
int sqr=sqrt(MAXN);
int input() {
	int x;scanf("%d",&x);
	return x;
}
const int _rx[4][4] ={
	{0,1,2,3},
	{-1,0,1,2},
	{-2,-1,0,1},
	{-3,-2,-1,0}
};
const int _ry[4][4] ={
	{3,2,1,0},
	{2,1,0,-1},
	{1,0,-1,-2},
	{0,-1,-2,-3}
};
char turn(int x) {
	if(10<=x&&x<16)return x-10+'A';
	else return x+'0';
}
struct block{
	char m[4][4];
	block() {memset(m,0,sizeof m);}
	void show() {
		for(int i=0;i<4;++i) {
			for(int j=0;j<4;++j) {
				if(10<=m[i][j]&&m[i][j]<16)printf("%c",m[i][j]-10+'A');
				else printf("%c",m[i][j]+'0');
			}printf("\n");
		} printf("\n");
	}
}w[4][4],rot[4][4][4];
block rotate(const block&x) {
	block c;
	for(int i=0;i<4;++i) {
		for(int j=0;j<4;++j) {
			c.m[i+_rx[i][j]][j+_ry[i][j]]=x.m[i][j];
		}
	}return c;
}
typedef std::vector<int> vec;
typedef std::vector<vec> vic;
bool checkC(int i) {
	int _c=0;
	for(int ik=0;ik<4;++ik) {
		int tong[16] ={0},cnt=0;
		for(int j=0;j<4;++j) {
			for(int jk=0;jk<4;++jk) {
				if(tong[w[i][j].m[ik][jk]]==0) {
					++cnt;
				}
				++tong[w[i][j].m[ik][jk]];
			}
		}
		if(cnt==16)++_c;
	}return _c==4;
}

bool checkR() {
	int _=0;
	for(int j=0;j<4;++j) {
		for(int jk=0;jk<4;++jk) {
			int tong[16]={0},cnt=0;
			for(int i=0;i<4;++i) {
				for(int ik=0;ik<4;++ik) {
					if(tong[w[i][j].m[ik][jk]]==0) {
						++cnt;
					}++tong[w[i][j].m[ik][jk]];
				}
			}if(cnt==16)++_;
		}
	}return _==16;
}
void push(vic&x,int a,int b,int c,int d) {
	vec z(4);
	z[0]=a;z[1]=b;z[2]=c;z[3]=d;
	x.push_back(z);
}
void show(const vec&x) {
	for(int i=0;i<4;++i) {
		printf("%d ",x[i]);
	}printf("\n");
}

void show() {
	for(int i=0;i<4;++i) {
		for(int ik=0;ik<4;++ik) {
			for(int j=0;j<4;++j) {
				for(int jk=0;jk<4;++jk) {
					printf("%c",turn(w[i][j].m[ik][jk]));
				}
			}printf("\n");
		}
	}printf("\n");
}
int doing() {
	for(int i=0;i<4;++i) {
		for(int ik=0;ik<4;++ik) {
			char str[32];
			scanf("%s",str);
			for(int j=0;j<4;++j) {
				for(int jk=0;jk<4;++jk) {
					char c=str[j*4+jk];
					if('A'<=c&&c<='F')w[i][j].m[ik][jk]=c-'A'+10;
					else w[i][j].m[ik][jk]=c-'0';
				}
			}
		}
	} 
	for(int i=0;i<4;++i) {
		for(int j=0;j<4;++j) {
			rot[i][j][0]=w[i][j];
			for(int k=1;k<4;++k) {
				rot[i][j][k]=rotate(rot[i][j][k-1]);
			}
		}
	}
	//rot[0][0][1].show();
	//rot[0][0][2].show();
	vic could[4];int size[4]={0};
	for(int i=0;i<4;++i) {
		for(int _0=0;_0<4;++_0) {
		w[i][0]=rot[i][0][_0];
		for(int _1=0;_1<4;++_1) {
		w[i][1]=rot[i][1][_1];
		for(int _2=0;_2<4;++_2) {
		w[i][2]=rot[i][2][_2];
		for(int _3=0;_3<4;++_3) {
		w[i][3]=rot[i][3][_3];
		if(checkC(i)) {
			push(could[i],_0,_1,_2,_3);
			++size[i];
		}
		}
		}
		}
		}
	}
	int ans=INF;
	for(int _0=0;_0<size[0];++_0) {
		for(int i=0;i<4;++i) {
			w[0][i]=rot[0][i][could[0][_0][i]];
		}
	for(int _1=0;_1<size[1];++_1) {
		for(int i=0;i<4;++i) {
			w[1][i]=rot[1][i][could[1][_1][i]];
		}
	for(int _2=0;_2<size[2];++_2) {
		for(int i=0;i<4;++i) {
			w[2][i]=rot[2][i][could[2][_2][i]];
		}
	for(int _3=0;_3<size[3];++_3) {
		for(int i=0;i<4;++i) {
			w[3][i]=rot[3][i][could[3][_3][i]];
		}
	if(checkR()) {
		int cnt=0;
		for(int i=0;i<4;++i){
			cnt+=could[0][_0][i]+could[1][_1][i]+could[2][_2][i]+could[3][_3][i];
		}ans=std::min(ans,cnt);
		int ptr[4]={_0,_1,_2,_3};
	//	for(int i=0;i<4;++i) {
	//		show(could[i][ptr[i]]);
	//	}printf("\n");
	//	show();
		
	}
	}
	}
	}
	}
	printf("%d\n",ans);
	return 0;
}
int main() {
	int T=input();
	while(T-->0)doing(); 
	return 0;
}