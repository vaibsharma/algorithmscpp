#include<bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int> > m;
int dist[10007];
int mod = 1000000007;
bool v[10007];

int dfs(int x, int f){
  if(dist[x]>0) return dist[x];
  int ans=0;
  for(int i=0;i<m[x].size();i++){
    ans += dfs(m[x][i],f)%mod;
    ans%=mod;
  }
  dist[x] = ans;
  return ans;
}
int main(){
  int T,C,B,S,F;
  scanf("%d",&T);
  while(T--){
    
    scanf("%d %d %d %d",&C,&B,&S,&F);
    for(int x=0;x<B;x++){
      int st,to;
      scanf("%d %d",&st,&to);
      m[st].push_back(to);
    }
    
    memset(dist,0,sizeof(dist));
    memset(v,false,sizeof(v));
    dist[F] = 1;
    int ans = dfs(S,F);
    
    cout<<ans<<"\n";
    for(int x=1;x<=C;x++) m[x].clear();
  }
  return 0;
}
