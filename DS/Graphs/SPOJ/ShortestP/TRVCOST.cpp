#include<bits/stdc++.h>

using namespace std;

struct edge{
  int t;
  int w;
};

vector<edge> gr[507];
int dp[507];

void solve(int u, int n){
  dp[u] = 0;
  priority_queue<pair<int,int> > q;
  q.push(make_pair(0,u));

  while(!q.empty()){
    pair<int,int> p = q.top();
    q.pop();
    dp[p.second] = min(dp[p.second],-p.first);
    for(edge i : gr[p.second]){
      if(dp[i.t] > dp[p.second] + i.w){
        //dp[i.t] = dp[p.second] + i.w;
        q.push(make_pair(-dp[p.second] - i.w,i.t));
      }
    }
  }
}

int main(){
  int n,u,q;
  scanf("%d",&n);

  for(int i=0;i<n;i++){
    edge e;
    int t;
    scanf("%d %d %d",&e.t,&t,&e.w);
    gr[t].push_back(e);
    //cout<<e.t<<" "<<e.w<<"\n";
    swap(e.t,t);
    gr[t].push_back(e);
    //cout<<e.t<<" "<<e.w<<"\n";
  }

  for(int x=0;x<=500;x++) dp[x] = INT_MAX;

  scanf("%d",&u);

  scanf("%d",&q);

  solve(u,n);

  for(int x=0;x<q;x++){
    int t;
    scanf("%d",&t);
    if(dp[t]==INT_MAX) cout<<"NO PATH\n";
    else cout<<dp[t]<<"\n";
  }
  return 0;
}
