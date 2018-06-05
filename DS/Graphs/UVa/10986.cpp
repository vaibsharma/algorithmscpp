#include<bits/stdc++.h>

using namespace std;

struct edge{
  int t;
  int w;
};

int dp[20007];
vector<edge> gr[20007];

void bfs(int s,int d){

  dp[s] = 0;
  priority_queue<pair<int,int> > q;
  q.push(make_pair(0,s));

  while(!q.empty()){
    pair<int,int> p = q.top();
    q.pop();
    dp[p.second] = min(dp[p.second],-p.first);
    if(p.second==d) return; 
    for(edge i: gr[p.second]){
      if(dp[i.t]>dp[p.second]+i.w){
        dp[i.t] = dp[p.second]+i.w;
        q.push(make_pair(-dp[p.second]-i.w,i.t));
      }
    }
  }

}
int main(){
  int T,n,m,s,d,cnt=1;
  scanf("%d",&T);
  while(T--){
    cout<<"Case #"<<cnt<<": ";
    cnt++;
    scanf("%d %d %d %d",&n,&m,&s,&d);

    for(int x=0;x<m;x++){
      edge e;
      int t;
      scanf("%d %d %d",&t,&e.t,&e.w);
      gr[t].push_back(e);
      swap(e.t,t);
      gr[t].push_back(e);
    }

    for(int x=0;x<=n;x++) dp[x] = INT_MAX;

    bfs(s,d);

    if(dp[d]==INT_MAX) cout<<"unreachable\n";
    else cout<<dp[d]<<"\n";

    for(int x=0;x<=n;x++) gr[x].clear();

  }
  return 0;
}
