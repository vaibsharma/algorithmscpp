#include<bits/stdc++.h>

using namespace std;

struct edge{
  int f;
  int t;
  int weight;
};

int uf[10007];
bool comp(edge a, edge b){
  return a.weight<b.weight;
}

int findu(int i){
  if(uf[i]==i) return i;
  return findu(uf[i]);
}

int main(){

  int n,m;
  long long int ans = 0;
  vector<edge> edges;

  scanf("%d %d",&n,&m);

  for(int x=0;x<10007;x++) uf[x] = x;

  for(int x=0;x<m;x++){
    edge e;
    scanf("%d %d %d",&e.f,&e.t,&e.weight);
    edges.push_back(e);
  }

  sort(edges.begin(),edges.end(),comp);
  for(int i=0;i<edges.size();i++){
    int f,t;
    f = findu(edges[i].f);
    t = findu(edges[i].t);
    //cout<<f<<" "<<t<<"\n";
    if(f != t){
      uf[f] = t;
      ans += edges[i].weight;
    }
  }
  cout<<ans;
  return 0;
}
