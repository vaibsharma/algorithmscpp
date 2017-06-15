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
  int T=1,n=1,i=1;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    while(n--){
      cout<<i<<" ";
      i = (((i % 500) * (2 % 500) )%500 + 1)%500;
    }
    cout<<"\n";
    i=1;
  }
  return 0;

}
