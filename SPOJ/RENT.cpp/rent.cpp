#include<bits/stdc++.h>

using namespace std;
int dp[1000007];
bool cmp(vector<int> a, vector<int> b){
  if(a[0]!=b[0]) return a[0]<b[0];
  if(a[1]!=b[1]) return a[1]<b[1];
  return a[2]>b[2];
}

int main(){
  int T,n;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    vector<vector<int> > rec;
    for(int x=0;x<n;x++){
      int ti;
      vector<int> p;
      for(int i=0;i<3;i++){
        scanf("%d",&ti);
        p.push_back(ti);
      }
      rec.push_back(p);
    }
    sort(rec.begin(),rec.end(),cmp);
    // for(int x=0;x<n;x++){
    //   cout<<rec[x][0]<<" "<<rec[x][1]<<" "<<rec[x][2]<<"\n";
    // }
    cout<<find(0,n-1,rec);
  }
  return 0;
}
