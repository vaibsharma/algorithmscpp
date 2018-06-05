#include<bits/stdc++.h>

using namespace std;

struct edge{
  int f;
  int t;
  int weight;
};

bool visit[400007];
int unif[400007];
unordered_map<int, vector<int> > g;

bool comp(edge a, edge b){
  return a.weight<b.weight;
}

void dfs(int x){
  visit[x] = true;
  for(int i=0;i<g[x].size();i++){
    if(!visit[g[x][i]]) dfs(g[x][i]);
  }
}

int unionf(int t){
  if(unif[t]==t) return t;
  return unionf(unif[t]);
}

int main(){
  int T,n,m,ctzn;
  edge e;
  scanf("%d",&T);
  while(T--){

    scanf("%d %d",&n,&m);
    vector<edge> edges;
    bool flag = true;
    bool v[400007];

    memset(visit,false,sizeof(visit));
    memset(v,false,sizeof(v));

    for(int x=1;x<=n;x++) unif[x] = x;

    for(int x=1;x<=n;x++){
      scanf("%d",&ctzn);
      if(ctzn==1){
        visit[x] = true;
        v[x] = true;
      }
    }

    for(int x=0;x<m;x++){
      scanf("%d %d %d",&e.f,&e.t,&e.weight);
      g[e.f].push_back(e.t);
      g[e.t].push_back(e.f);
      edges.push_back(e);
    }

    for(int x=1;x<=n;x++){
      if(visit[x]) dfs(x);
    }

    sort(edges.begin(),edges.end(),comp);

    for(int x=1;x<=n;x++){
      if(!visit[x]) flag = false;
    }

    if(!flag) cout<<"impossible\n";
    else{
      long long int ans =0;
      for(int x=0;x<edges.size();x++){
        int t1,t2;
        t1 = unionf(edges[x].f);
        t2 = unionf(edges[x].t);
        if(t1!=t2 && (!v[t1] || !v[t2])){
          if(v[t1]){
            unif[t2] = t1;
          }
          else if(v[t2]){
            unif[t1] = t2;
          }
          else unif[t1] = t2;

          //v[t1] = v[t2] = true;
          ans += edges[x].weight;
        }
      }
      cout<<ans<<"\n";
    }

    for(int x=1;x<=n;x++) g[x].clear();
  }
  return 0;
}
