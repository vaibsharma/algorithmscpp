#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main(){
  long int n,k,t;
  scanf("%ld %ld %ld",&n,&k,&t);
  if(t<k){
    printf("%d",t);
  }
  else if(t>=k && t<=n){
    printf("%ld",k);
  }
  else printf("%ld",abs(k-(t-n)));
  return 0;
}

