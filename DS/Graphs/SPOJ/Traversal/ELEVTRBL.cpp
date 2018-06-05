#include<bits/stdc++.h>

using namespace std;
bool visit[1000007];
int main(){
  int f,s,g,u,d,k;
  cin>>f>>s>>g>>u>>d;
  queue<pair<int,int> > q;
  memset(visit,false,sizeof(visit));
  bool flag = false;
  //unordered_map<int,bool> visit;
  q.push(make_pair(s,0));
  while(!q.empty() && !flag){
    pair<int,int> p = q.front();
    q.pop();
    if(p.first==g){
      cout<<p.second;
      flag = true;
      break;
    }
    if(p.first+u<=f && !visit[p.first+u]){
      q.push(make_pair(p.first+u,p.second+1));
      visit[p.first+u] = true;
    }
    if(p.first-d>=1 && !visit[p.first-d]){
      q.push(make_pair(p.first-d,p.second+1));
      visit[p.first-d] = true;
    }
  }
  if(!flag) cout<<"use the stairs";
  //else cout<<dp[g]<<"\n";
  return 0;
}
