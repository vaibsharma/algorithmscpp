#include<bits/stdc++.h>

using namespace std;

struct edge{
  int f;
  int t;
  edge() {}
  edge(int _f, int _t) : f(_f),t(_t) {}
};

int strength[105], dp[105];
vector<int> gr[105];
vector<edge> edges;
bool visit[105];

const int INF = 1e8+7;

bool check(int s, int d){
  if(s==d) return true;
  visit[s] = true;
  for(int i: gr[s]){
    if(!visit[i] && check(i,d)) return true;
  }
  return false;
}

int main(){
  int n;
  while(true){
    scanf("%d",&n);
    if(n==-1) return 0;
    memset(visit,false,sizeof(visit));
    for(int x=1;x<=n;x++){
      int l;
      scanf("%d %d",&strength[x],&l);
      for(int y=0;y<l;y++){
        int j;
        scanf("%d",&j);
        gr[x].push_back(j);
        edges.push_back(edge(x,j));
      }
    }

    for(int x=0;x<=100;x++) dp[x] = -INF;
    dp[1] = 100;

    for(int x=0;x<n-1;x++){
      for(edge i: edges){
        if(dp[i.f]<=0) continue;
        dp[i.t] = max(dp[i.t],dp[i.f]+strength[i.t]);
      }
    }

    bool cycle = false;
    for(edge i: edges){
      if(dp[i.f]<=0) continue;
      cycle = cycle || ((dp[i.f]+strength[i.t] > dp[i.t]) && check(i.t,n));
    }

    if(dp[n]>0 || cycle) cout<<"winnable\n";
    else cout<<"hopeless\n";
    
    for(int x=0;x<=100;x++) gr[x].clear();
    edges.clear();
    
  }
  return 0;
}
