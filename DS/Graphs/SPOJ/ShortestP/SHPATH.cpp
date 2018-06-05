#include<bits/stdc++.h>

using namespace std;

struct edge{
  int t;
  int w;
};

edge getEdge(int t, int w){
  edge e;
  e.t = t;
  e.w = w;
  return e;
}

unordered_map<int,vector<edge> > g;

int dist[10007];

int getShortestPath(int s, int d){
  priority_queue<pair<int,int> > q;
  bool v[10007];
  memset(v,false,sizeof(v));
  q.push(make_pair(0,s));
  while(!q.empty()){
    pair<int,int> p = q.top();
    q.pop();
    if(p.second==d) return -p.first;
    if(!v[p.second]){
      v[p.second] = true;
      for(int x=0;x<g[p.second].size();x++){
        q.push(make_pair(p.first-g[p.second][x].w,g[p.second][x].t));
      }
    }
  }
  //return dist[d];
  return INT_MAX;
}

int main(){
  int T,N,ed;
  string st,st1;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    unordered_map<string,int> m;
    for(int i=0;i<N;i++){
      cin>>st;
      cin>>ed;
      m[st] = i+1;
      for(int x=0;x<ed;x++){
        edge e;
        scanf("%d %d",&e.t,&e.w);
        g[i+1].push_back(getEdge(e.t,e.w));
        // g[e.t].push_back(getEdge(i+1,e.w));
      }
    }
    int r;
    scanf("%d",&r);
    for(int x=0;x<r;x++){
      cin>>st>>st1;
      cout<<getShortestPath(m[st],m[st1])<<"\n";
    }
    for(int i=0;i<=N;i++) g[i].clear();
  }
  return 0;
}
