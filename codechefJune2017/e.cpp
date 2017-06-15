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


#define mdl 1000000007
#define UMAX 2147483647
#define MAX 1073741823
#define pb push_back
#define mp make_pair
#define sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define sec second
using namespace std;

int main(){
  int T=0;
  vector <lli> x,y,z;
  int x1=0,y1=0,z1=0,count=0;
  bool flag=false;
  lli all,sum=0;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d %d",&x1,&y1,&z1);
    x.clear();
    y.clear();
    z.clear();
    for(int i=0;i<x1;i++){
      scanf("%lld",&all);
      x.pb(all);
    }
    sort(x);
    for(int i=0;i<y1;i++){
      scanf("%lld",&all);
      y.pb(all);
    }
    sort(y);
    for(int i=0;i<z1;i++){
      scanf("%lld",&all);
      z.pb(all);
    }
    sort(z);
    for(int y2=y1-1;y2>=0;y2--){
      for(int x2=0;x2<x1;x2++){
        if(y[y2]<x[x2])
          {
            x1=x2;
          }
        else{
          for(int z2=0;z2<z1;z2++){
            if(y[y2]<z[z2]){
              z1=z2;
            }
            else{
              sum+=( ((y[y2]%mdl + x[x2]%mdl)%mdl) * ((y[y2]%mdl + z[z2]%mdl)%mdl) )%mdl;
              //count++;
            }
          }
        }
      }
  }
    // for(int x2=0;x2<x.size();x2++){
    //   cout<<x[x2]<<" ";
    // }
    // cout<<"\n";
    // for(int z2=0;z2<z.size();z2++){
    //   cout<<z[z2]<<" ";
    // }
    // cout<<"\n";
    // for(int y2=0;y2<y.size();y2++){
    //   cout<<y[y2]<<" ";
    // }
    // cout<<"\n";
    cout<<sum<<"\n";
    sum=0;
  }
  return 0;
}
