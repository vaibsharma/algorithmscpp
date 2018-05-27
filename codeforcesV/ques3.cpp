#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
  int n;
  float p = 1;
  bool checkPrime(int);
  scanf("%d",&n);
  for(int x=1;x<n;n++){
    if(checkPrime(x)){
      if(checkPrime(n-x)){
        if(p<min((n-x)/x,x/(n-x)))
          p = min((n-x)/x,x/(n-x));
      }
    }
  }
  return 0;
}

bool checkPrime(int key){
  bool ans = true;
  for(int x=1;x<=pow(key,0.5)&&!flag;x++){
    if(key%x == 0) flag = false;
  }
  return flag;
}
