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


#define modulo 1000000007
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
  vector <int> a,b,c;
  int T=0,all=0,k=0,n=0,k1=0;
  ll mul=1,sum=0;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d",&n,&k);
    cout<<n<<" "<<k<<"\n";
    a.resize(k+1,1);
    a[0]=0;
    while(n--){
      b.clear();
      b.resize(k+1,0);
      c.clear();
      c.resize(k+1,0);
      scanf("%d",&k1);
      for(int i=0;i<k1;i++){
        scanf("%d",&all);
        b[all] = 1;
        c[all]+=1;
      }
       if(b==a){
        // cout<<"found all the elements"<<"\n";
        for(int i=0;i<k;i++){
          mul*= c[i+1];
        }
        sum+=mul;
        mul=1;
      }
    }
    // cout<<sum<<" ";
    mul=1;sum=0;
    }
  return 0;
}
