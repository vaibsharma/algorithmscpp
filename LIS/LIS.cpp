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


#define modulo 1000000007;
#define UMAX 2147483647 ;
#define MAX 1073741823;
#define pb push_back
#define mp make_pair
#define sort(a) sort(a.begin(),a.end())
#define rsort(a) reverse(a.begin(),a.end())
#define fi first
#define sec second
using namespace std;

int main() {
  int calLIS(vector<int>,int);
  vector<int> a;
  int n=0,allias=0;
  printf("Please enter The number of elements : ");
  scanf("%d\n",&n);
  for(int x=0;x<n;x++){
    scanf(" %d",&allias);
    a.pb(allias);
  }
  printf("The Longest common subsequence length is: %d",calLIS(a,n-1));
  return 0;
}
int calLIS(vector<int> a,int n){
  if(n<0){
    return  0;
  }
  int x = n-1,maximum=0;
  while(a[n]<a[x] && x>=0){
    int p= calLIS(a,x);
    if(p>maximum){
      maximum=p;
    }
    x--;
  }
  return max(calLIS(a,x)+1,maximum);
}
