#include<bits/stdc++.h>

using namespace std;

vector<int> gr[10007];
bool visit[10007],ar_pt[10007];
int dfs_low[10007],dfs_num[10007],parent[10007];
int root=0,scc=0,cnt=0;

void dfs(int x){
  visit[x] = true;
  dfs_low[x] = dfs_num[x] = ++scc;
  for(int i: gr[x]){
    if(!visit[i]){
      parent[i] = x;
      if(x == root) cnt++;

      dfs(i);

      if(dfs_low[i]>=dfs_num[x])
        ar_pt[x] = true;

      dfs_low[x] = min(dfs_low[x],dfs_low[i]);
    }
    else if(parent[x]!=i){
      dfs_low[x] = min(dfs_low[x],dfs_num[i]);
    }
  }
}

int main(){
  int n,m;

  while(true){
    scanf("%d %d",&n,&m);
    if(n==0 && m==0) break;
    scc=0;
    for(int x=1;x<=n;x++){
      dfs_low[x] = dfs_num[x] = parent[x] = -1;
    }

    memset(visit,false,sizeof(visit));
    memset(ar_pt,false,sizeof(ar_pt));

    for(int x=0;x<m;x++){
      int f,t;
      scanf("%d %d",&f,&t);
      gr[f].push_back(t);
      gr[t].push_back(f);
    }

    for(int x=1;x<=n;x++){
      if(!visit[x]){
        root = x;
        cnt=0;
        dfs(x);
        ar_pt[x] = (cnt>1);
      }
    }

    cnt=0;

    for(int i=1;i<=n;i++) if(ar_pt[i]) cnt++;

    cout<<cnt<<"\n";

    for(int i=1;i<=n;i++) gr[i].clear();
  }

  return 0;
}
