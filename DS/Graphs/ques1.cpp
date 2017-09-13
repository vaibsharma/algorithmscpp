// Make a simple graph and return all the routes

#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<list>

using namespace std;

struct graph{
  int V;
  int E;
  list<int> Edges;
  unordered_map <int,list<int>> Adjacency;
};

int main(){
  graph *p = new graph;
  int vertices,d,f,s;
  list<int> j;
  printf("please enter the no. of vertices: ");
  scanf("%d",&vertices);
  p->V = vertices;
  for(int x=0;x<vertices;x++){
    printf("enter %d vertex : ",x+1);
    scanf("%d",&d);
    p->Edges.push_back(d);
    cout<<"\n";
  }
  cout<<"Please enter the number of edges:\n";
  scanf("%d",&p->E);
  for(int x=0;x<p->E;x++){
    printf("\nThe front is : ");
    scanf("%d",&f);
    printf("\n the second is : ");
    scanf("%d",&s);
    p->Adjacency[f].push_back(s);
  }
  for(auto a:p->Edges){
    j= p->Adjacency[a];
    printf("%d->",a);
    for(auto x:j){
      printf("%d,",x);
    }
    printf("\n");
  }
  return 0;
}
