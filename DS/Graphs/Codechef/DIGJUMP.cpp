#include<bits/stdc++.h>

using namespace std;

unordered_map<char,vector<int> > g;

int dist[100005];
//bool visit[100005];

int main(){
  string s;
  int n;
  queue<int> q;

  cin>>s;
  n = s.size();
  //memset(visit,false,sizeof(visit));

  for(int x=0;x<n;x++) dist[x] = INT_MAX;
  for(int x=0;x<n;x++){
    g[s[x]].push_back(x);
  }

  //visit[n-1] = true;
  dist[n-1] = 0;
  q.push(n-1);

  while(!q.empty()){
    int p = q.front();
    q.pop();

    if(p==0){
      printf("%d \n",dist[0]);
      break;
    }

    if(p-1>=0 && dist[p-1]>dist[p]+1){
      q.push(p-1);
      dist[p-1] = min(dist[p-1],dist[p]+1);
    }

    if(p+1<n && dist[p+1]>dist[p]+1){
      q.push(p+1);
      dist[p+1] = min(dist[p+1],dist[p]+1);
    }

    for(int x=0;x<g[s[p]].size();x++){
      int c = g[s[p]][x];
      if(dist[c]>dist[p]+1){
        dist[c] = min(dist[c],dist[p]+1);
        q.push(c);
      }
    }
    g[s[p]].clear();
  }
  return 0;
}
