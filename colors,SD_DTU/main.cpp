#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
  // Declare the variable
  int T=0,count=0,R=0,G=0,B=0;
  string Red,Green,Blue;
  cin>>T;
  string change(int a);
  while(T--){
      count++;
      scanf("%d %d %d",&R,&G,&B);
      Red = change(R);
      Green = change(G);
      Blue = change(B);
      printf("Case %d : ",count);
      cout<<Red<<" "<<Green<<" "<<Blue<<"\n";

  }


//   // Read the variable from STDIN
//   cin >> a;

//   // Output the variable to STDOUT
//   cout << a;

  return 0;
}

string change(int a){
    string x = "";
    char first=' ',second=' ';
    int i = a/16;
    if(i>9){
        i=15-i;
        first = 'Z' - i;

    }
    else{
        first = '0'+i;
    }

    int y = a%16;
    if(y>9){
        y = 15-y;
        second = 'Z' - y;
    }
    else{
        second = '0' + y;
    }
    x.push_back(first);
    x.push_back(second);


    // printf("integer value of 0 %d",Z);
    return x;
}
