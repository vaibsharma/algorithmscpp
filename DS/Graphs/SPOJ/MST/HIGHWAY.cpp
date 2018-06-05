#include<bits/stdc++.h>

using namespace std;

int dp[100007];

struct edge{
  int t;
  int w;
};

unordered_map<int,vector<edge> > g;

int main(){
  int T,n,m,s,f,d;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d %d %d",&n,&m,&s,&d);

    priority_queue<pair<int,int> > edges;
    for(int i=1;i<=n;i++) dp[i] = INT_MAX;

    for(int x=0;x<m;x++){
      int t,f,w;
      scanf("%d %d %d",&t,&f,&w);
      edge e;
      e.t = t;
      e.w = w;
      g[f].push_back(e);
      e.t = f;
      g[t].push_back(e);
    }

    edges.push(make_pair(0,s));

    while(!edges.empty()){
      pair<int,int> p = edges.top();
      edges.pop();
      if(dp[p.second]>=-p.first){
        dp[p.second] = -p.first;
        for(int i=0;i<g[p.second].size();i++) edges.push(make_pair(p.first-g[p.second][i].w,g[p.second][i].t));
      }
    }

    if(dp[d]== INT_MAX) cout<<"NONE\n";
    else cout<<dp[d]<<"\n";

    for(int i=1;i<=n;i++) g[i].clear();
  }
  return 0;
}
