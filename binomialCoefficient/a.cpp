#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include<ctime>

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
lli c[1001000] = {0};
int main(){
  int n,k,count=1,multfac=1,T=0;
scanf("%d",&T);
while(T--){

	scanf("%d %d",&n,&k);
  c[0] = 1;
	k = min(n-k,k);
  for(int i = 1;i<=n;i++){
    for(int j = k;j>=1;j--){
      c[j] = c[j] + c[j-1];
	//count++;
    }
  }
  for(int i=0;i<=k;i++){
    cout<<c[i]<<" ";
  }
  cout<<"\n";
  cout<<c[k]<<"\n";
}
  return 0;
}
