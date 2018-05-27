#include<bits/stdc++.h>

using namespace std;
unordered_map<int,vector<int>> graph;
int main(){
  vector<int> edges;
  unordered_map<int,bool> visited;
  stack<int> sortedElements;
  void topologicalSorting(int,unordered_map<int,bool> &,stack<int> &);
  int p,i=0,f,t;
  cout<<"Enter the number of edges: ";
  scanf("%d",&p);
  printf("\n");
  while(i<p){
    printf("Enter Edge %d\n",i);
    scanf("%d %d",&f,&t);
    graph[f].push_back(t);
    if(!visited[f]){
      visited[f]=true;
      edges.push_back(f);
    }
    if(!visited[t]){
      visited[t]=true;
      edges.push_back(t);
    }
    i++;
  }
  for(int x=0;x<edges.size();x++){
    visited[edges[x]] = false;
  }
  for(int x=0;x<edges.size();x++){
    if(!visited[edges[x]]){
      visited[edges[x]] = true;
      topologicalSorting(edges[x],visited,sortedElements);
    }
  }
  while(!sortedElements.empty()){
    cout<<sortedElements.top()<<" ";
    sortedElements.pop();
  }
  return 0;
}

void topologicalSorting(int node, unordered_map<int,bool> &visited, stack<int> &sortedElements){
  vector<int> p = graph[node];
  for(int x=0;x<p.size();x++){
    if(!visited[p[x]]){
      visited[p[x]] = true;
      topologicalSorting(p[x],visited,sortedElements);
    }
  }
  sortedElements.push(node);
}
