#include<bits/stdc++.h>

using namespace std;

int edges,vertices,iter=0,root,cnt=0;

unordered_map<int,vector<int> > graph;
unordered_map<int,int> dfs_low,dfs_num,parent;
unordered_map<int,bool> visited,articulation_pt;

void articulation(int x){
  iter++;
  dfs_low[x] = dfs_num[x] = iter;
  visited[x] = true;

  for(int i=0; i<graph[x].size(); i++){
    if(!visited[graph[x][i]]){
      parent[graph[x][i]] = x;

      if(x == root){
        cout<<"Found "<<x<<" and "<<graph[x][i]<<" as root and child\n";
        cnt++;
      }

      articulation(graph[x][i]);

      dfs_low[x] = min(dfs_low[x], dfs_low[graph[x][i]]);

      if(dfs_num[x] <= dfs_low[graph[x][i]]) articulation_pt[x] = true;
    }
    else if(parent[x] != graph[x][i]){
      dfs_low[x] = min(dfs_low[x],dfs_num[graph[x][i]]);
    }
  }

}

int main(){
  printf("Please add the number of vertices: ");
  scanf("%d",&vertices);
  printf("\nPlease add the number of edges in the graph: ");
  scanf("%d",&edges);
  printf("\n");
  for(int x=0; x<edges; x++){
    int f, t;
    scanf("%d %d", &f, &t);
    graph[f].push_back(t);
    graph[t].push_back(f);
  }

  for(int x=0; x<vertices; x++){
    if(!visited[x]){
      root = x;
      cnt=0;
      parent[x] = -1;
      articulation(x);
      if(cnt>1){
        cout<<"No of cnt for "<<x<<" is "<<cnt<<"\n";
        articulation_pt[x] = true;
      }
      else articulation_pt[x] = false;
    }
  }

  for(int x=0;x<vertices;x++){
    if(articulation_pt[x]) cout<<x<<" is a articulation point\n";
  }
  return 0;
}
