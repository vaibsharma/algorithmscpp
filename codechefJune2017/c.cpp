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
  vector<ll> arr;
  int T;
  lli count=0,allias=0,size=0;
  lli sump=0,sumn=0;
  scanf("%d",&T);
  while(T--){
    scanf("%lld",&size);
    arr.resize(1,0);
    arr.resize(size,0);
    for(lli i=0;i<size;i++){
      scanf("%lld",&allias);
      if(allias>=0){
        count++;
        sump+=allias;
      }
      else{
        sumn+=allias;
      }
    }
    cout<<(sump)*count + sumn<<"\n";
    sump=0;
    sumn=0;
    count=0;
  }
  return 0;
}
