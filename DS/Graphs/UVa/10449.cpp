#include<bits/stdc++.h>

using namespace std;

struct edge{
  int f;
  int t;
  int w;
};

edge getedge(int f, int t, int w){
  edge e;
  e.f = f;
  e.t = t;
  e.w = w;
  return e;
}

int dp[205],ind[205];
vector<edge> gr[205];
bool visit[205];

const int INF = 1e8+7;
int main(){
  int n,in,m,cnt=1,q;
  while(scanf("%d",&n)==1){
    cout<<"Set #"<<cnt<<"\n";
    for(int x=0;x<n;x++){
      scanf("%d",&in);
      ind[x+1] = in;
      //cout<<ind[x+1]<<" ";
    }
    //cout<<"\n";

    memset(visit,false,sizeof(visit));

    scanf("%d",&m);
    vector<edge> edges;

    for(int x=0;x<m;x++){
      int f,t;
      scanf("%d %d",&f,&t);
      edge e;
      e.f = f;
      e.t = t;
      e.w = (ind[t]-ind[f])*(ind[t]-ind[f])*(ind[t]-ind[f]);
      edges.push_back(e);
    }
    for(int x=0;x<=n;x++) dp[x] = INF;

    dp[1] = 0;

    for(int v=1;v<n;v++){
      for(edge e: edges){
        if(dp[e.f]!=INF){
          dp[e.t] = min(dp[e.t],dp[e.f]+e.w);
        }
      }
    }

    scanf("%d",&q);
    for(edge u : edges){
      //continue;
      //int w = (ind[t]-ind[f])*(ind[t]-ind[f])*(ind[t]-ind[f]);
      if(dp[u.t]>dp[u.f]+u.w && dp[u.f] != INF) dp[u.t] = -1e8+7;
    }

    for(int x=0;x<q;x++){
      int t;
      scanf("%d",&t);
      if(dp[t]<3 || dp[t]==INF) cout<<"?";
      else cout<<dp[t];
      cout<<"\n";
    }

    cnt++;

    for(int x=0;x<=n;x++) gr[x].clear();

  }
  return 0;
}
