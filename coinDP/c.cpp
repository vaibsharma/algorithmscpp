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


#define modo 1000000007
#define UMAX 2147483647 
#define MAX 1073741823
#define pb push_back
#define mp make_pair
#define sort(a) sort(a.begin(),a.end())
#define fi first
#define sec second
using namespace std;

int main(){
  vector <int> a;
  int n=0,Total=0,find(vector<int>,int);
  scanf("%d",&n);
  scanf("%d",&Total);
  a.resize(n,0);
  for(int x=0;x<n;x++){
    scanf("%d",&a[x]);
  }
  sort(a);
  int last = find(a,Total);
  last++;
  int chances = pow(2,last)-1;
  int y=0,sum=0,count=0,f=0,nu=0;
  for(int i=0;i < chances;i++){
    y= i;
    sum=0;
    cout<<"---- new scope ---"<<y<<"\n";
    while(y){
      f = y&(-y);
      while(f){
        f/=2;
        nu++;
      }
      sum+=a[nu-1];
      cout<<"checking indexx at "<<nu-1<<"\n";
      y-= y&(-y);
      nu=0;
    }
    if(sum == Total) count++;
  }
  cout<<count;
  return 0;
}

int find(vector<int> a,int N){
  int length = a.size(),index=0;
  for(int i=0;i<length;i++){
    if(a[i]<N){
      index = i;
    }
  }
  return index;
}
