#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#define ll long long
#define M 
using namespace std;int stop;
int n,m;
int people[2000];
bool shuchu[2000];
string duiyou[2000][10];
string s,s1,s2,s3,s4,s5;
struct Node{
  int hp,team;
};
queue<int>three;
queue<int>two;
map<string,Node> mp;


int main(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      cin>>s;
      Node a;a.hp = 3;a.team = -1;
      mp[s] = a;
    }
    scanf("%d",&m);
    int total = 0;
    for(i=1;i<=m;i++){
      cin>>s1>>s2;
      int t1,t3;
      switch (s2[0])
      {
      case 'H':
        cin>>s3>>s4>>s5;
        if(mp[s1].hp <=1){//倒了的人不能动
          printf("FAKE\n");
          return 0;
        }
        if(s5[0] == 'B'){
          mp[s3].hp = max(mp[s3].hp-1,0);
        }else{
          mp[s3].hp = max(mp[s3].hp-2,0);
        }
        break;
      case 'R':
        cin>>s3;
        if(mp[s1].hp <=1){//倒了的人不能动
          printf("FAKE\n");
          return 0;
        }
        if(mp[s3].hp != 1){
          printf("FAKE\n");
          return 0;
        }else{
          //扶起来
          mp[s3].hp = 2;
          //判断是不是队友
          t3 = mp[s3].team,t1 = mp[s1].team;
          if(t1 == -1 && t3 == -1){
            total++;mp[s3].team = mp[s1].team = total;
            people[total]++;
            duiyou[total][people[total]] = s1;
            people[total]++;
            duiyou[total][people[total]] = s3;
          }else if(t1 == -1 && t3 != -1){
            if(people[t3] != 4){
              people[t3]++;
              mp[s1].team = t3;
              duiyou[t3][people[t3]] = s1;
            }else{
              printf("FAKE\n");
              return 0;
            }
          }else if(t3 == -1 && t1 != -1){
            if(people[t1] != 4){
              people[t1]++;
              mp[s3].team = t1;
              duiyou[t1][people[t1]] = s3;
            }else{
              printf("FAKE\n");
              return 0;
            }
        }else if(t3 != -1 && t1 != -1){
          if(t3 != t1){
            printf("FAKE\n");
            return 0;
          }
        }
        }
        break;

      default :
        cin>>s3;
        if(mp[s1].hp <=1){//倒了的人不能动
          printf("FAKE\n");
          return 0;
        }
        if(mp[s1].hp <= 1){
          printf("FAKE\n");
          return 0;
        }else{
          mp[s1].hp = 3;
        }
        break;
      }
    }


    for(i=1;i<=total;i++){
      if(people[i] == 3){
        three.push(i);
      }else if(people[i] == 2){
        two.push(i);
      }
    }

    map<string, Node>::iterator it;
    int jishu = 0;
    for(it = mp.begin();it!= mp.end();it++){
      if(it->second.team == -1){
        jishu++;
      }
    }
    
    if(jishu < three.size()){
      printf("FAKE\n");
      return 0;
    }

    printf("CORRECT\n");

    while (!two.empty())
    {
      if(two.size()>=2){
        int x = two.front();two.pop();
        int y = two.front();two.pop();
        cout<<duiyou[x][1]<<" "<<duiyou[x][2]<<" "<<duiyou[y][1]<<" "<<duiyou[y][2]<<" "<<endl;
      }else{
        break;
      }
      
    }
    
    for(i=1;i<=total;i++){
      if(people[i] == 4){
        for(j=1;j<4;j++){
          cout<<duiyou[i][j]<<" ";
        }
        cout<<duiyou[i][4]<<endl;
      }
    }

    jishu = 0;
    for(it = mp.begin();it!= mp.end();it++){
      if(it->second.team == -1){
        if(!three.empty()){
          int k = three.front();three.pop();
          cout<<duiyou[k][1]<<" "<<duiyou[k][2]<<" "<<duiyou[k][3]<<" "<<it->first<<endl;
        }else if(!two.empty()){
          if(jishu == 0){
            int k = two.front();two.pop();
            cout<<duiyou[k][1]<<" "<<duiyou[k][2]<<" "<<it->first<<" ";
            jishu = 3;
          }else{
            cout<<it->first<<endl;
            jishu = 0;
          }
        }else{
          cout<<it->first<<" ";
          jishu++;
          if(jishu == 4){
            cout<<endl;
            jishu = 0;
          }
        }
        
      }
    }
    return 0;
}