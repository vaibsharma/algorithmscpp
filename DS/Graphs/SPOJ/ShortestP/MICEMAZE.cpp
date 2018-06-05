#include<bits/stdc++.h>

using namespace std;

struct edge{
  int t;
  int w;
};

vector<edge> gr[105];
int dp[105];

void solve(int e){
  priority_queue<pair<int,int> > q;
  q.push(make_pair(0,e));

  while(!q.empty()){
    pair<int,int> p = q.top();
    q.pop();
    dp[p.second] = min(dp[p.second],-p.first);
    for(edge i: gr[p.second]){
      if(dp[i.t]>dp[p.second]+i.w){
        q.push(make_pair(-dp[p.second]-i.w,i.t));
      }
    }
  }
}

int main(){
  int n,e,t,m;
  scanf("%d %d %d",&n,&e,&t);
  scanf("%d",&m);

  for(int x=0;x<m;x++){
    edge e;
    int f;
    scanf("%d %d %d",&e.t,&f,&e.w);
    gr[f].push_back(e);
  }

  for(int x=0;x<=100;x++) dp[x] = INT_MAX;
  dp[e] = 0;

  solve(e);
  int count=0;
  for(int x=1;x<=n;x++){
   if(dp[x]<=t) count++;
  }
  cout<<count;

  return 0;
}
