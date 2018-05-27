/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>

using namespace std;
int n,m,u,v;
long long int w;
map<pair<int,int>, long long int> weights;
unordered_map<int,bool> vis;
map<pair<int,int>,int> vi;
unordered_map<int,vector<int>> graph;
priority_queue<pair<long long int,int>, vector<pair<long long int,int> >, greater<pair<long long int,int> > > Q;
bool flag = false;
int main(){
    cin>>n>>m;
    for(int x=0;x<m;x++){
        cin>>u>>v>>w;
        graph[v].push_back(u);
        graph[u].push_back(v);
        weights[make_pair(u,v)] = w;
        weights[make_pair(v,u)] = w;
        if(vi[make_pair(u,v)]!=0 || vi[make_pair(v,u)]!=0 ){
          cout<<u<<" "<<v<<" line number "<<vi[make_pair(u,v)]<<" at line "<<x+2<<"\n";
          flag = true;
        }

        vi[make_pair(u,v)] = x+2;
        vi[make_pair(v,u)] = x+2;
    }
    if(flag) return 0;
    long long int dis=0;
    Q.push(make_pair(0,u));
    while(!Q.empty()){
        pair<long long int,int> parent = Q.top();
        Q.pop();
        if(!vis[parent.second]){
            vis[parent.second] = true;
            dis += parent.first;
            vector<int> child = graph[parent.second];
            for(int x=0;x<child.size();x++){
                if(!vis[child[x]]) Q.push(make_pair(weights[make_pair(parent.second,child[x])],child[x]));
            }
        }
    }
    cout<<dis;
    return 0;
}
