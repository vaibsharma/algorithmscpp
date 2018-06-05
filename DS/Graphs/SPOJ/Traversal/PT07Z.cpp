#include<bits/stdc++.h>

using namespace std;

unordered_map<int,vector<int> > m;
int path[10007];

int dfs(int x, int f, int p){
  int ans=0,j,mx = 0;
  vector<int> sum = {p};
  path[x] = p;
  for(int i=0;i<m[x].size();i++){
    if(m[x][i]!=f){
      j = dfs(m[x][i],x,p+1);
      sum.push_back(j);
      mx = max(j,mx);
    }
  }
  for(int i=0;i<sum.size();i++){
    for(int j=i+1;j<sum.size();j++){
      path[x] = max(path[x],sum[i]+sum[j]);
    }
  }
  return mx+1;
}

int main(){
  int n,f,t;
  scanf("%d",&n);
  for(int x=0;x<n-1;x++){
    scanf("%d %d",&f,&t);
    m[f].push_back(t);
    m[t].push_back(f);
  }
  dfs(1,-1,0);
  int ans=0;
  for(int x=1;x<=n;x++){
    //cout<<"path of "<<x<<" is "<<path[x]<<"\n";
    ans = max(ans,path[x]);
  }
  cout<<ans;
  return 0;
}
