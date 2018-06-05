#include<bits/stdc++.h>

using namespace std;

int dp[9999];

int main(){
  int l,u,r,cnt=1;
  while(true){
    
    vector<int> options;
    scanf("%d %d %d",&l,&u,&r);
    if(u==0 && l==0 && r==0) return 0;
    cout<<"Case "<<cnt<<": ";
    cnt++;
    for(int x=0;x<r;x++){
      int j;
      scanf("%d",&j);
      options.push_back(j);
    }

    for(int x=0;x<10000;x++) dp[x] = INT_MAX;
    dp[l] = 0;
    queue<int> q;
    q.push(l);
    while(!q.empty()){
      int t = q.front();
      q.pop();
      if(t==u) break;
      for(int i:options){
        int g = (i+t)%10000;
        if(dp[g]>dp[t]+1){
          dp[g] = dp[t]+1;
          q.push(g);
        }
      }
    }
    if(dp[u]==INT_MAX) cout<<"Permanently Locked\n";
    else cout<<dp[u]<<"\n";
  }
  return 0;
}
