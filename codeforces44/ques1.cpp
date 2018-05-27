#include<bits/stdc++.h>

using namespace std;
bool cmp(int x, int y){
  return y<x;
}
int dp[2010][2010],k[2010][2010];
int main(){

  int n,m,l,i,k;
  scanf("%d %d %d",&n,&m,&l);
  vector<int> v;

  for(int x=0;x<n*m;x++){
    scanf("%d",&i);
    v.push_back(i);
  }

  sort(v.begin(),v.end());

  for(i=n-1;i<n*m;i++){
    k = v[i]-v[0];
    if(k>l) break;
  }

  i--;
  k=0;
  //cout<<i<<"\n";
  long long int sum=0;
  //p = 1
  for(int x=0;x<=i;x++){
    if(k<n){
      sum+=v[x];
      //cout<<v[x]<<"-"<<x<<" ";
      k++;
      if((i-x)-(m-1) >= (n-k)) x += m-1;
      else if(x<=(i-(n-k))) x = i-(n-k);
    }
  }

  if(k<n) sum=0;
  cout<<sum;
  return 0;
}
