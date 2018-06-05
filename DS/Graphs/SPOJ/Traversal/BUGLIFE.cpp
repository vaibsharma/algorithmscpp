#include<bits/stdc++.h>

using namespace std;

int colour[2019];

int main(){
  int T,V,E,f,t,c=0;
  scanf("%d",&T);
  while(T--){
    c++;
    cout<<"Scenario #"<<c<<":\n";
    unordered_map<int,vector<int> > m;
    unordered_map<int, bool> visited;
    scanf("%d %d",&V,&E);
    for(int x=1;x<=V;x++) colour[x] = -1;
    for(int x=0;x<E;x++){
      scanf("%d %d",&f,&t);
      m[f].push_back(t);
      m[t].push_back(f);
    }

    bool flag = true;
    for(int x=1;x<=V;x++){
      queue<int> q;
      q.push(x);
      if(!visited[x]){
        colour[x] = 0;
        while(!q.empty()){
          int p = q.front();
          q.pop();
          visited[p] = true;
          for(int i=0;i<m[p].size();i++){
            if(colour[m[p][i]] == -1){
              colour[m[p][i]] = 1 - colour[p];
              q.push(m[p][i]);
            }
            else if(colour[m[p][i]] == colour[p]){
              flag = false;
            }
          }

        }
      }
    }

    if(flag) cout<<"No suspicious bugs found!\n";
    else cout<<"Suspicious bugs found!\n";

  }

  return 0;
}
