#include<bits/stdc++.h>

using namespace std;

bool visit[1007];
int dist[1007];
unordered_map<int,vector<int> > m;

void dfs(int x, int p, vector<int> cy, unordered_map<int,bool> v){
  v[x] = true;
  visit[x] = true;
  cy.push_back(x);
  for(int i=0;i<m[x].size();i++){
    if(m[x][i]!=p && v[m[x][i]]){
      //cout<<m[x][i]<<" ";
      dist[m[x][i]] = 0;
      while(cy.size()>0 && cy.back()!=m[x][i]){
        dist[cy.back()]=0;
        //cout<<cy.back()<<" ";
        cy.pop_back();
      }
      //cout<<"\n";
    }
    else if(!visit[m[x][i]]) dfs(m[x][i],x,cy,v);
  }
}

int main(){
  int T,n,f,t,cnt=1;
  scanf("%d",&T);
  while(T--){
    
    //bool v[1007];
    unordered_map<int,bool> v;
    memset(visit,false,sizeof(visit));
    //memset(v,false,sizeof(v));

    for(int x=0;x<1007;x++) dist[x] = INT_MAX;

    scanf("%d",&n);

    for(int x=0;x<n;x++){
      scanf("%d %d",&f,&t);
      m[f].push_back(t);
      m[t].push_back(f);
    }

    vector<int> cy;
    dfs(1,0,cy,v);

    memset(visit,false,sizeof(visit));

    for(int x=1;x<=n;x++){
      if(!visit[x] && dist[x]==0){
        queue<int> q;
        q.push(x);
        while(!q.empty()){
          int p = q.front();
          q.pop();
          visit[p] = true;
          for(int i=0;i<m[p].size();i++){
            dist[m[p][i]] = min(dist[p]+1,dist[m[p][i]]);
            if(!visit[m[p][i]]) q.push(m[p][i]);
          }
        }
      }
    }
    //cout<<"\n";
    cout<<"Case #"<<cnt<<": ";
    for(int x=1;x<=n;x++) cout<<dist[x]<<" ";
    cout<<"\n";
    cnt++;

    for(int x=0;x<1007;x++) m[x].clear();
  }
  return 0;
}
