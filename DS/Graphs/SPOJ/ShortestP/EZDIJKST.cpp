#include<bits/stdc++.h>

using namespace std;

struct edge{
  int t;
  int w;
};

int dp[10007];
unordered_map<int, vector<edge> > g;

int main(){
  int T,V,K,s,d;
  scanf("%d",&T);
  while(T--){
    int a;
    edge e;
    scanf("%d %d",&V,&K);
    for(int x=0;x<K;x++){
      scanf("%d %d %d",&a,&e.t,&e.w);
      g[a].push_back(e);
    }

    for(int i=0;i<=V;i++) dp[i]=INT_MAX;

    priority_queue<pair<int,int> > q;

    scanf("%d %d",&s,&d);

    q.push(make_pair(0,s));
    while(!q.empty()){
      pair<int,int> p = q.top();
      q.pop();
      if(dp[p.second]>-p.first){
        dp[p.second] = -p.first;
        for(int x=0;x<g[p.second].size();x++) q.push(make_pair(p.first-g[p.second][x].w,g[p.second][x].t));
      }
    }

    if(dp[d]==INT_MAX) cout<<"NO\n";
    else cout<<dp[d]<<"\n";

    for(int i=0;i<=V;i++) g[i].clear();
  }
  return 0;
}
