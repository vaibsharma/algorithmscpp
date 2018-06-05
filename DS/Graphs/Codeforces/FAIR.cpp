#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> dk[105];
vector<int> gr[100005];
int dp[105][100005];

void bfs(int k, int n){
  queue<int> q;
  for(int x=1;x<=n;x++) dp[k][x] = INT_MAX;

  for(int x=0;x<dk[k].size();x++){
    q.push(dk[k][x]);
    dp[k][dk[k][x]] = 0;
  }

  while(!q.empty()){
    int p = q.front(); q.pop();
    for(int x=0;x<gr[p].size();x++){
      if(dp[k][gr[p][x]] > dp[k][p]+1){
        dp[k][gr[p][x]] = dp[k][p]+1;
        q.push(gr[p][x]);
      }
    }
  }
}

int main(){
  int n,m,k,s;
  scanf("%d %d %d %d",&n,&m,&k,&s);

  for(int x=0;x<n;x++){
    int i;
    scanf("%d",&i);
    dk[i].push_back(x+1);
  }

  for(int x=0;x<m;x++){
    int f,t;
    scanf("%d %d",&f,&t);
    gr[f].push_back(t);
    gr[t].push_back(f);
  }

  for(int x=1;x<=k;x++)
    bfs(x,n);

  long long int ans=0;
  for(int x=1;x<=n;x++){
    vector<int> v;
    ans=0;
    for(int i=1;i<=k;i++){
      v.push_back(dp[i][x]);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<s;i++) ans+=v[i];
    cout<<ans<<" ";
  }
  
  return 0;
}
