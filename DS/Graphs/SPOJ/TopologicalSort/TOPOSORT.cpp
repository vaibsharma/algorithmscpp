#include<bits/stdc++.h>

using namespace std;

unordered_map<int,vector<int> > g;

bool visit[10008];
int indegree[10008];
//stack<int> s;

// void dfs(int x, stack<int> &s){
//   visit[x] = true;
//   //cout<<x<<" ";
//   //bool flag = false;
//   for(int i=0;i<g[x].size();i++){
//     if(!visit[g[x][i]]) dfs(g[x][i],s);
//   }
//   s.push(x);
//   //else visit[x] = false;
// }

bool isCycle(int x, unordered_map<int, bool> v){
  if(v[x]){
    //cout<<"Cycle detected at "<<x<<"\n";
    return true;
  }
  v[x] = true;
  visit[x] = true;
  bool flag = false;
  for(int i=0;i<g[x].size();i++){
     flag = flag || isCycle(g[x][i],v);
  }

  return flag;
}

int main(){
  int n,m;
  stack<int> s;
  //vector<int> ans;
  unordered_map<int, bool> v;

  scanf("%d %d",&n,&m);
  memset(visit,false,sizeof(visit));
  memset(indegree,0,sizeof(indegree));

  for(int x=0;x<m;x++){
    int f,t;
    scanf("%d %d",&f,&t);
    g[f].push_back(t);
    indegree[t]++;
  }

  //for(int x=1;x<=n;x++) sort(g[x].begin(),g[x].end());
  bool flag = false;

  // for(int x=1;x<=n;x++){
  //   if(!visit[x]) flag = flag || isCycle(x,v);
  // }

  vector<int> ans;
    set<int> q;
    for(int x=1;x<=n;x++) if(indegree[x]==0) q.insert(x);

    while(!q.empty()){
      int p = *q.begin();
      ans.push_back(p);
      q.erase(q.begin());
      for(int x=0;x<g[p].size();x++){
        indegree[g[p][x]]--;
        if(indegree[g[p][x]]==0) q.insert(g[p][x]);
      }
    }

    if(ans.size() != n){
      printf("Sandro fails.\n");
    }
    else {
      for(int x=0;x<ans.size();x++) printf("%d ",ans[x]);
      printf("\n");
    }

  return 0;
}
