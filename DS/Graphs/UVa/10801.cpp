#include<bits/stdc++.h>

using namespace std;

struct edge{
  int t;
  int i;
  int w;
  bool operator < (const edge & e) const{
    return this->w > e.w;
  }
};

edge getedge(int t, int i, int w){
  edge e;
  e.t = t;
  e.i = i;
  e.w = w;
  return e;
}


int dp[107];
vector<edge> gr[107];
int stops[107];

int main(){
  int n, k, j;
  string line;

  while(scanf("%d %d",&n,&k)==2){
    vector<int> wgt;
    for(int i=0;i<n;i++){
      int x;
      scanf("%d",&x);
      wgt.push_back(x);
    }

    getline(cin,line);

    for(int i=0;i<n;i++){
      getline(cin,line);
      istringstream iss(line);

      int ind=0;
      while(iss >> stops[ind++]);

      ind--;

      for(int x=0;x<ind;x++){
        for(int y=x+1;y<ind;y++){
          gr[stops[x]].push_back(getedge(stops[y],i,abs(stops[x]-stops[y])*wgt[i]));
          gr[stops[y]].push_back(getedge(stops[x],i,abs(stops[x]-stops[y])*wgt[i]));
        }
      }
    }

    for(int x=0;x<=99;x++) dp[x] = INT_MAX;

    priority_queue<edge > q;
    for(edge i: gr[0]) q.push(getedge(0,i.i,0));
    dp[0]= 0;
    
    while(!q.empty()){
      edge p = q.top();
      q.pop();
      //dp[p.t] = min(dp[p.t],p.w);
      if(p.t==k) break;
      //cout<<"currently at "<<p.t<<" elevator "<<p.i<<" at t = "<<p.w<<"\n";
      for(edge i: gr[p.t]){
        int alt = 0;
        if(i.i != p.i) alt = 60;
        if(dp[i.t] > p.w + i.w + alt){
          dp[i.t] = p.w +i.w + alt;
          q.push(getedge(i.t,i.i,dp[i.t]));
        }
      }
    }

    //cout<<"\n";
     if(dp[k]==INT_MAX) cout<<"IMPOSSIBLE\n";
    else cout<<dp[k]<<"\n";

    for(int i=0;i<=100;i++) gr[i].clear();
  }
  return 0;
}
