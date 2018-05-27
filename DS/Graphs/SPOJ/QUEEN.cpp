#include<bits/stdc++.h>

using namespace std;

char board[1005][1005];
int dp[1005][1005];
bool visit[1005][1005];

int check(pair<int,int> a, pair<int,int> b){
  if(a==b) return 0;
  else return 1;
}

int main(){
  int T,n,m,sx,sy,fx,fy;
  char ch;
  string s;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d",&n,&m);
    //printf("%d %d\n",n,m);
    //memset(board,'.',sizeof(board));
    memset(visit,false,sizeof(visit));
    for(int x=0;x<n;x++){
      cin>>s;
      for(int i=0;i<s.size();i++){
        dp[x][i] = 5007;
        //cout<<s[i]<<" ";
        board[x][i] = s[i];
        if(s[i]=='S'){
          sx= x;
          sy = i;
        }
        else if(s[i] == 'F'){
          fx = x;
          fy = i;
        }
        else if(s[i]=='X'){
          visit[x][i] = true;
        }
      }
      //cout<<"\n";
    }
    dp[sx][sy] = 0;
    queue<pair<int,int> > q,d;

    q.push(make_pair(sx,sy));
    d.push(make_pair(-2,-2));
    while(!q.empty()){
      pair<int,int> p = q.front();
      pair<int,int> d1 = d.front();
      //cout<<p.first<<" "<<p.second<<" "<<d1.first<<" "<<d1.second<<" == "<<dp[p.first][p.second]<<"\n";
      q.pop();
      d.pop();
      //visit[p.first][p.second] = true;
      for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
          if(i==0 && j==0) continue;
          if((p.first+i)>=0 && (p.first+i)<n && (p.second+j)>=0 && (p.second+j)<m && !visit[p.first+i][p.second+j]){
            if(dp[p.first+i][p.second+j] >= dp[p.first][p.second] + check(make_pair(i,j),d1)){
              dp[p.first+i][p.second+j] = dp[p.first][p.second] + check(make_pair(i,j),d1);
              q.push(make_pair(p.first+i,p.second+j));
              d.push(make_pair(i,j));
            }
          }
        }
      }
    }
    if(dp[fx][fy]>=5007)cout<<"-1\n";
    else cout<<dp[fx][fy]<<"\n";
  }
  return 0;

}
