#include<bits/stdc++.h>

using namespace std;

struct edgew{
  int t;
  int w;
};

struct edge{
  int f;
  int t;
  int w;
};

int uf[20008];
bool visit[20008];

unordered_map<int, vector<edgew> > g;

void dfs(int n){
  visit[n] = true;
  cout<<n<<" ";
  for(int x=0;x<g[n].size();x++){
    if(!visit[g[n][x].t]) dfs(g[n][x].t);
  }
}

edgew getEdge(int t, int w){
  edgew e;
  e.t = t;
  e.w = w;
  return e;
}


int unionf(int t){
  if(uf[t]==t) return t;
  return unionf(uf[t]);
}

bool cmp(edge a, edge b){
  return a.w<b.w;
}

int main(){
  int T,n,m,f;
  edge e;
  bool flag = true;
  scanf("%d",&T);
  while(T--){
    vector<edge> ed;
    flag = true;
    scanf("%d %d",&n,&m);

    for(int x=0;x<m;x++){
      scanf("%d %d %d",&e.f,&e.t,&e.w);
      g[e.f].push_back(getEdge(e.t,e.w));
      g[e.t].push_back(getEdge(e.f,e.w));
      ed.push_back(e);
    }

    memset(visit,false,sizeof(visit));

    for(int x=0;x<=n;x++) uf[x] = x;

    dfs(0);
    cout<<"\n";
    for(int x=0;x<n;x++) if(!visit[x]) flag = false;

    if(!flag) cout<<"NO\n";
    else{
      // sort(ed.begin(),ed.end(),cmp);
      // long long int ans = 0;

      // for(int x=0;x<ed.size();x++){
      //   int g,h;
      //   g = unionf(ed[x].t);
      //   h = unionf(ed[x].f);
      //   if(g!=u){
      //     ans+= ed[x].w;
      //     uf[g] = h;
      //   }
      // }

      cout<<"YES\n";
    }
    for(int x=0;x<n;x++) g[x].clear();
  }
  return 0;
}
