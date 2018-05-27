#include<bits/stdc++.h>

using namespace std;

bool prime[10007];
//bool visit[10007];
unordered_map<int, vector<int> > m;
int dp[10007];

void sieve(int n){
  prime[4] = prime[6] = prime[8] = prime[9] = false;
  int count=0;
  for(int x=8;x<=n;x++){
    for(int i=2;i<=sqrt(x);i++){
      if(x%i==0) prime[x] = false;
    }
  }
  // for(int x=2;x<=n;x++){
  //   if(prime[x]){
  //     cout<<x<<" ";
  //     count++;
  //   }
  // }
  
}

int check(int f, int s){
  int count=0;
  while(f && s){
    if(f%10 != s%10) count++;
    f/=10;
    s/=10;
  }
  return count;
}

void generate_g(int s, int e){
  for(int x=s;x<=e;x++){
    for(int i=x+1;i<=e;i++){
      if(prime[x] && prime[i] && check(i,x)==1){
        //cout<<x<<" and "<<i<<"\n";
        m[x].push_back(i);
        m[i].push_back(x);
      }
    }
  }
}

void sieveoferatosthenis(int n){
  int s = sqrt(n);
  int c = s+1;
  while(c<=n){
    int f = min(c+s,n);
    for(int x=2;x<=s;x++){
      int ch = (c/x)*x;
      if(ch<c) ch+=x;
      for(int i=ch;i<=f;i++){
        if(i%x==0) prime[i] = false;
      }
    }
    c+=s;
  }
  int count=0;
  for(int x=2;x<=n;x++){
    if(prime[x]){
      //cout<<x<<" ";
      count++;
    }
  }
  //cout<<"\nThere are total "<<count;
}

int bfs(int s, int f, int pr,unordered_map<int,bool> visit){
  if(s==f) return 0;
  if(dp[s]!=0) return dp[s];
  visit[s] = true;
  int ans = 10007;
  //cout<<s<<" "<<f<<"-->"<<dp[s]<<"\n";
  for(int x=0;x<m[s].size();x++){
    if(m[s][x]!=pr && !visit[m[s][x]]){
      ans = min(ans,dp[m[s][x]]);
      //else ans = min(ans,bfs(m[s][x],f,s));
    }
  }
  dp[s] = ans+1;
  visit[s] = false;
  return dp[s];
}

int main(){
  int T,s,f;
  scanf("%d",&T);
  memset(prime,true,sizeof(prime));
  sieve((int)sqrt(10006));
  sieveoferatosthenis(10006);
  generate_g(1000,9999);
  while(T--){
    //memset(dp,0,sizeof(dp));
    //memset(visit,false,sizeof(visit));
    unordered_map<int,bool> visit;
    for(int x=1000;x<=9999;x++) dp[x] = INT_MAX;
    scanf("%d %d",&s,&f);
    //cout<<s<<" "<<f<<"\n";
    //dp
    dp[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
      int p = q.front();
      q.pop();
      visit[p] = true;
      for(int x=0;x<m[p].size();x++){
        if(m[p][x]!=p && !visit[m[p][x]]){
          dp[m[p][x]] = min(dp[m[p][x]],dp[p]+1);
          q.push(m[p][x]);
        }
      }
    }
    //int ans = bfs(min(s,f),max(s,f),-1,visit);
    if(dp[f]==INT_MAX) cout<<"Impossible/n";
    else cout<<dp[f]<<"\n";
  }
  return 0;
}
