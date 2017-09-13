/**
 * @author Vaibhav Sharma
 * @rollNo 2k15/EP/070
 * @submissionDate 7 Sept 2017
 * @mailID vaibhav_bt2k15@gmail.com
 * @problemStatement Implement Depth First Search
 */

#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<stack>

using namespace std;

int main(){
  unordered_map<int,stack<int>> graph;
  unordered_map<int,bool> visited;
  stack <int> dfs;
  int edges=0,q=0,f=0,t=0;
  printf("Enter the no. of edges: ");
  scanf("%d",&edges);
  printf("\nEnter the pairs in next %d lines\n\n",edges);

  // Preparing Edges of the Graph

  while(q<edges){
    scanf("%d %d",&f,&t);
    printf("\n");
    graph[f].push(t);
    q++;
  }

  // Getting the start node

  printf("Enter the starting node: ");
  scanf("%d",&f);     // f is the from node
  dfs.push(f);
  while(!dfs.empty()){
    t = dfs.top();  // t is the to node
    dfs.pop();
    if(!visited[t]){
      visited[t] = true;

      // Finding all the child nodes from t node

      stack<int> p = graph[t];

      while(!p.empty()){
        if(!visited[p.top()]){
          printf("From %d to %d\n",t,p.top());
          dfs.push(p.top());
        }
        p.pop();
      }
    }
  }
  return 0;
}
