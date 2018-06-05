#include<bits/stdc++.h>

using namespace std;

vector<int> gr[100007];
bool visit[100007];

void dfs(int u){
  visit[u] = true;
  for(int i: gr[u]){
    if(!visit[i]) dfs(i);
  }
}

int main(){
  int n,m;
  scanf("%d %d",&n,&m);

  memset(visit,false,sizeof(visit));

  for(int x=0;x<m;x++){
    int f,t;
    scanf("%d %d",&f,&t);
    gr[t].push_back(f);
  }

  int cnt=0,prev=0;
  vector<int> ans;
  while(true){
    bool flag = true;

    for(int i=prev+1;i<=n;i++){
      if(!visit[i]){
        prev = i;
        dfs(i);
      }
    }
    // memset(visit,false,sizeof(visit));
    for(int x=1;x<=n;x++){
      visit[x] = false;
    }
    dfs(prev);

    for(int i=1;i<=n;i++){
      if(!visit[i]) flag = false;
      visit[i] = false;
    }
    if(flag){
      ans.push_back(prev);
      //cout<<prev<<" ";
      cnt++;
    }
    else break;
    
    if(prev==n) break;
    for(int x=1;x<=n;x++){
      visit[x] = false;
    }
    // for(int x: ans) visit[x] = true;
  }
  cout<<cnt<<"\n";
  for(int i: ans) cout<<i<<" ";
  return 0;
}
