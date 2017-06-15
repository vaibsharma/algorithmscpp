#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <vector>
#include <map>

typedef long long int lli;
typedef long long ll;

#define nn 100100
#define modulo 1000000007
#define UMAX 2147483647 
#define MAX 1073741823
#define pb push_back
#define mp make_pair
#define sort(a) sort(a.begin(),a.end())
#define fi first
#define sec second
using namespace std;
int main()
{
  vector<int> a,b,c,ans,d;
  c.resize(nn,0);
  bool flag=true; 
  int n=0,count=0,aa;
  scanf("%d",&n);
  a.resize(n,0);
  b.resize(n,0);
  ans.resize(n,0);
  for(int x=0;x<n;x++){
    scanf("%d",&aa);
    a[x] = aa;
  }
  for(int x=0;x<n;x++){
    scanf("%d",&aa);
    b[x] = aa;
    if(b[x]==a[x]){
      ans[x] = a[x];
      c[a[x]] =1;
    }
    else{
      d.pb(x);
    }
  }
  if(d.size()==1){
    for(int x=0;x<n;x++){
      if(!ans[x]){
      for(int y=1;y<=n;y++){
        if(c[y]==0){
          ans[x]=y;
          break; 
        }
      }
      }
    }
  }
  else if(d.size()==2){
    if(c[a[d[0]]]==0 && c[a[d[1]]]==0){
      ans[d[1]] = b[d[1]];
      ans[d[0]] = a[d[0]];
    }
    else{
      ans[d[1]] = a[d[1]];
      ans[d[0]] = b[d[0]];
    }
  }
    for(int x=0;x<n;x++){
        cout<<ans[x]<<" ";
    }
    return 0;
}
