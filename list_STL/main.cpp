#include <iostream>
#include <list>
#include <map>
#include <cstdlib>
#include <cstdio>
using namespace std;
class graph{
    int V ;
    map<int,list<int> > graphM;
    map<int,bool> visited ;
    list<int> Queue;
    public :
        graph(int V);
        void addEdge(int,int);
        void BFS(int);
};
graph::graph(int V){
    this->V = V ;
}

void graph::addEdge(int v,int w){
    graphM[v].push_back(w);
    visited[v] = false;
}

void graph::BFS(int s){
    int start=0,init=0,top=0;
    list<int>::iterator iter;
    printf("Enter the number to start with : ");
    scanf("%d",&start);
    if(graphM.find(start)->second.at(0) > -1){
        Queue.push_back(s);
    visited[s] = true;
    while(!Queue.empty()){
        top = Queue.front();
        printf("%d ",s);
        Queue.pop_front();

        for(iter = graphM.find(s)->second.begin();iter != graphM.find(s)->second.end();iter++){
            if(visited.find(*iter) == false){
                visited[*iter] = true;
                Queue.push_back(*iter);
            }

        }
    }

    }
    else{
         printf("\n Vertex is not in the map");
        getchar();
        exit(0);
    }



}

int main()
{
    cout << "Hello world!" << endl;

    return 0;
}
