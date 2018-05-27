#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
  vector<pair<long long int,long long int>> a;
  long long int x=0,y=0;
  int count=0;
  for(int s=0;s<3;s++){
    scanf("%lld %lld",&x,&y);
    a.push_back(make_pair(x,y));
  }
  //sort(a.begin(),a.end());
  if((a[0].second-a[1].second)*(a[1].first-a[2].first) == (a[1].second-a[2].second)*(a[0].first-a[1].first)  || (pow(abs(a[0].second-a[1].second),2) + pow(abs(a[1].first - a[0].first),2) != (pow(abs(a[1].second - a[2].second),2) + pow(abs(a[2].first - a[1].first),2)))){
    printf("No");
  }
  else printf("Yes");
  return 0;
}

