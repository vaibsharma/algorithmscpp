#include<bits/stdc++.h>

using namespace std;;

struct edge{
  int t;
  int f;
  int w;
  bool operator < (const edge & e) const{
    return this->w > e.w;
  }
};

edge getedge(int t, int w){
  edge e;
  e.t = t;
  e.w = w;
  return e;
}

void bfs(int s, vector<edge> *gr, int *dp){
  dp[s] = 0;
  priority_queue<edge> q;
  q.push(getedge(s,0));
  while(!q.empty()){
    edge e = q.top();
    q.pop();
    dp[e.t] = min(dp[e.t],e.w);
    for(edge i: gr[e.t]){
      if(dp[i.t]> e.w + i.w){
        dp[i.t] = e.w + i.w;
        q.push(getedge(i.t,dp[i.t]));
      }
    }
  }
}

vector<edge> gr1[10006], gr2[10007];
int dp1[10007], dp2[10007];

int main(){
  int T,n,m,s,t,p;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d %d %d %d",&n,&m,&s,&t,&p);
    for(int x=0;x<=n;x++){
      dp1[x] = dp2[x] = INT_MAX;
    }

    vector<edge> edges;
    for(int x=0;x<m;x++){
      edge e;
      scanf("%d %d %d",&e.f,&e.t,&e.w);
      edges.push_back(e);
      gr1[e.f].push_back(e);
      swap(e.f,e.t);
      gr2[e.f].push_back(e);
    }

    dp1[s] = 0;
    bfs(s,gr1,dp1);
    dp2[t] = 0;
    bfs(t,gr2,dp2);
    int ans = -1,toll=-1;
    for(edge i: edges){
      if(dp1[i.f] != INT_MAX && dp2[i.t] != INT_MAX && (dp1[i.f]+i.w+dp2[i.t])<=p)
        toll = max(toll,i.w);
    }
    cout<<toll<<"\n";

    for(int x=0;x<=n;x++){
      gr1[x].clear();
      gr2[x].clear();
    }
  }
  return 0;
}
