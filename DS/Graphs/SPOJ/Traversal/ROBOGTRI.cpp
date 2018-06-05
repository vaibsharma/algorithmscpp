#include<bits/stdc++.h>

using namespace std;

char board[1005][1005];
long long int dp[1007][1007];
long long int mod = 2147483647;
bool visit[1007][1007]; 

long long int dfs(int sx, int sy, int n){
  if(sx<0 || sy<0 || sx>n || sy>n || board[sx][sy]=='#') return 0;
  if(sx==n && sy==n) return 1;
  if(dp[sx][sy]!=-1) return dp[sx][sy];

  long long int ans=0;
  ans+=dfs(sx+1,sy,n)%mod;
  ans%=mod;
  ans+=dfs(sx,sy+1,n)%mod;
  ans%=mod;
  dp[sx][sy] = ans;
  return ans;
}

void vdfs(int sx, int sy,int n){
  if(sx<0 || sy<0 || sx>n || sy>n || board[sx][sy]=='#' || visit[sx][sy]) return;
  visit[sx][sy] = true;
  vdfs(sx,sy+1,n);
  vdfs(sx+1,sy,n);
  vdfs(sx-1,sy,n);
  vdfs(sx,sy-1,n);
}

int main(){
  int n;
  string st;
  scanf("%d",&n);

  for(int x=0;x<1006;x++){
    for(int i=0;i<1006;i++) dp[x][i]=-1;
  }

  for(int x=0;x<n;x++){
    cin>>st;
    for(int i=0;i<st.size();i++){
      board[x][i] = st[i];
    }
  }

  dp[n-1][n-1] = 1;

  long long int ans = dfs(0,0,n-1);

  if(ans!=0) cout<<ans<<"\n";
  else{
    vdfs(0,0,n-1);
    if(visit[n-1][n-1]){
      cout<<"THE GAME IS A LIE\n";
    }
    else cout<<"INCONCEIVABLE\n";
  }
  // for(int x=0;x<n;x++){
  //   for(int i=0;i<n;i++){
  //     if(visit[x][i]) cout<<dp[x][i]<<" ";
  //     else cout<<"# ";
  //   }
  //   cout<<"\n";
  // }
  
  return 0;
}
