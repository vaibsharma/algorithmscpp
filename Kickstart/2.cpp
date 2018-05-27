#include<bits/stdc++.h>

using namespace std;

int dp[100006],a[100006],b[100006];
int T,n,k,x,y,c,d,e1,e2,f;
int fx(int i){
  if(i==1) return ((((c%f)*(x%f))%f + ((d%f)*(y%f))%f)%f + e1%f)%f;
  if(a[i]!=-1) return a[i];

  int ans = ((((c%f)*(fx(i-1)%f))%f + ((d%f)*(yx(i-1)%f))%f)%f + e1%f)%f;
  a[i] = ans;
  return a[i];
}

int yx(int i){
  if(i==1) return ((((d%f)*(x%f))%f + ((c%f)*(y%f))%f)%f + e1%f)%f;
  if(b[i]!=-1) return b[i];

  int ans = ((((d%f)*(fx(i-1)%f))%f + ((c%f)*(yx(i-1)%f))%f)%f + e2%f)%f;
  b[i] = ans;
  return b[i];
}

int main(){

  scanf("%d",&T);
  long long int mod = 1000000007;
  while(T--){
    cin>>n>>k>>x>>y>>c>>d>>e1>>e2>>f;
    for(int x=1;x<=n;x++){
      dp[x] = (a[x] + b[x])%f;
    }
    long long int ans=0;
    for(int i=1;i<=k;x++){
      for(int x=1;x<=n;x++){
        for(int j=x;j<=n;j++){
          for(int l=x;l<=j;l++){
            ans+= (dp[l]*(pow(l-x+1,i)%mod))%mod;
            ans%=mod;
          }
        }
      }
    }
    cout<<ans<<"\n";
  }
  return 0;

}
