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
  int n=0,k=0,p=0,start=0,flag=true;
  scanf("%d %d",&n,&k);
  vector <int> a,b;
  a.resize(n,0);
  b.resize(k,0);
  for(int x=0;x<n;x++){
    scanf("%d",&p);
    a[x] = p;
  }
  for(int x=0;x<k;x++){
    scanf("%d",&p);
    b[x]=p;
  }
  sort(b);
  rev(b);
  for(int x=0;x<n;x++){
    if(a[x]==0){
      a[x] = b[start];
      start++;
    }
  }
  vector<int> check = a;
  sort(check);
  if(check!=a){
    cout<<"Yes";
  }
  else{
    cout<<"No";
  }
  
  return 0;
}

