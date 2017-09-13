/**
 * @author Vaibhav Sharma
 * @submissionDate 7 Sept 2017
 * @mailID vaibhav_bt2k15@gmail.com
 * @problemStatement Implement Breadth First Search
 */

#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<deque>

using namespace std;

int main(){
  unordered_map<int,deque<int>> graph;
  unordered_map<int,bool> visited;
  deque <int> bfs;
  int edges=0,q=0,f=0,t=0;
  printf("Enter the no. of edges: ");
  scanf("%d",&edges);
  printf("\nEnter the pairs in next %d lines\n\n",edges);

  // Preparing Edges of the Graph

  while(q<edges){
    scanf("%d %d",&f,&t);
    printf("\n");
    graph[f].push_back(t);
    q++;
  }

  // Getting the start node

  printf("Enter the starting node: ");
  scanf("%d",&f);     // f is the from node
  bfs.push_back(f);
  while(!bfs.empty()){
    t = bfs.front();  // t is the to node
    bfs.pop_front();
    if(!visited[t]){
      visited[t] = true;

      // Finding all the child nodes from t node

      deque<int> p = graph[t];

      while(!p.empty()){
        if(!visited[p.front()]){
          printf("From %d to %d\n",t,p.front());
          bfs.push_back(p.front());
        }
        p.pop_front();
      }
    }
  }
  return 0;
}
