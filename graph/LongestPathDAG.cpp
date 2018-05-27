#include<iostream>
#include<bits/stdc++.h>

using namespace std;
map<pair<int,int>,int> weight;
unordered_map<int,vector<int>> graph;
unordered_map<int,bool> visited;
unordered_map<int,int> dis;
int maxdis = INT_MIN;
int edges,start,u,v,w;

void startSearch(int start, int &maxdis){
  stack<int> dfs;
  dfs.push(start);
  while(!dfs.empty()){
    int parent = dfs.top();
    vector<int> child = graph[parent];
    visited[parent] = true;
    dfs.pop();
    for(int x=0;x<child.size();x++){
      if(!visited[child[x]]){
        dfs.push(child[x]);
        dis[child[x]] = max(dis[child[x]],dis[parent]+weight[make_pair(parent,child[x])]);
        maxdis = max(maxdis,dis[child[x]]);
        cout<<start<<" ---> "<<child[x]<<" = "<<dis[child[x]]<"\n";
      }
    }
  }

}
int main(){
   printf("Enter the number of edges: ");
  scanf("%d",&edges);
  printf("\nNext %d lines should have origin,destination and weight seperated by space\n",edges);
  while(edges--){
    scanf("%d %d %d",&u,&v,&w);
    graph[u].push_back(v);
    weight[make_pair(u,v)] = w;
    dis[u] = INT_MIN;
    dis[v] = INT_MIN;
  }

  printf("\n Enter the starting node: ");
  scanf("%d",&start);
  dis[start] = 0;
  startSearch(start,maxdis);
  cout<<"max distance from start = "<<start<<" is "<<maxdis;
  return 0;
}
