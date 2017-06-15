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
int a[10][10] = {{0}},T=0;
int n,m,s,g,move1=0;
void show(),swp(int &b,int &a);
void swp(int &x, int &y){
  int z;
  z=x;
  x=y;
  y=z;
  move1++;
}
void init(){
  char c=0;
  scanf("%d %d",&n,&m);
  for(int x=0;x<n;x++){
    for(int y=0;y<m;y++){
      scanf(" %c",&c);
      // cout<<c<<" ";
      if(c=='*'){
        a[x][y] = 1;
      }
      else{
        a[x][y]=0;
        s=x;
        g=y;
      }
    }
    //cout<<"\n";
  }
}

void getPos(){
  int sw;
  for(int x=s;x<n-1;x++){
    swp(a[x][g],a[x+1][g]);
    show();
    cout<<"changes made\n";
    //cout<<x<<" "<<g<<" "<<x+1<<" "<<g<<"\n";
  }
  for(int x=g;x<m-1;x++){
    swp(a[n-1][x],a[n-1][x+1]);
    show();
    cout<<"changes made\n";
    //cout<<n-1<<" "<<x<<" "<<n-1<<" "<<x+1<<"\n"; 
  }
  s=n-1;
  g=m-1;
}

void clean(int x){
    for(int z=0;z<m-1;z++){
      if(a[x][z]==1 && a[x][z+1]==0){
        swp(a[x][z],a[x][z+1]);


        show();
        cout<<"changes made\n";
      }
    }
    if(m%2==0){
      for(int y=m-1;y-2>=0;y-=2){
        for(int z=y;z>=y-2;z--){
          if(a[x][z] == 1){
            a[x][z]=0;
          }
          else{
            a[x][z] = 1;
          }
        }
        move1++;

        show();
        cout<<"changes made\n";
      }
      if(x>0){
        for(int z=0;z<=2;z++){
          if(a[x][z] == 1){
            a[x][z]=0;
          }
          else{
            a[x][z] = 1;
          }
        }
        move1++;
        show();
        cout<<"changes made\n";
        swp(a[x][2],a[x][1]);
        show();
        cout<<"changes made\n";
        swp(a[x][1],a[x][0]);
        show();
        cout<<"changes made\n";
      }
    }
    else{
      int l=2;
      if(x==0){
        l=4;
      }
      for(int y=m-1;y-l>=0;y-=2){
        for(int z=y;z>=y-2;z--){
          if(a[x][z] == 1){
            a[x][z]=0;
          }
          else{
            a[x][z] = 1;
          }
        }
        move1++;
        show();
        cout<<"changes made\n";
      }
      if(x==0){
        swp(a[0][2],a[0][1]);
        show();
        cout<<"changes made\n";
      }
    }
}
void align(int x){
  int sw;
  for(int y=0;y<m-1;y++){
    swp(a[x][y],a[x][y+1]);
    show();
    cout<<"changes made\n";
  }
}
void show(){
  for(int x=0;x<n;x++){
    for(int y=0;y<m;y++){
      cout<<a[x][y]<<" ";
    }
    cout<<"\n";
    }
  cout<<"\n\n";
}
int main(){
  // sqaure free numbers ?
  scanf("%d",&T);
  void init(),getPos(),clean(int),align(int);
  int sw;
  bool flag=true;
  while(T--){
    init();
    if(max(n,m)<=2){
      flag=false;
      cout<<"-1"<<"\n";
    }
    if(n<=2){
      swap(n,m);
    }
    if(flag){
      getPos();
      for(int x=n-1;x>=0;x--){
        for(int y=m-1;y-2>=0;y-=2){
          for(int z=y;z>=y-2;z--){
            if(a[x][z] == 1){
              a[x][z]=0;
            }
            else{
              a[x][z] = 1;
            }
          }
          move1++;
          show();
          cout<<"changes made\n";
        }

        if(m%2 == 0){
          if(a[x][0]==1 && a[x][1] ==0){
            swp(a[x][1],a[x][0]);
            show();
            cout<<"changes made\n";
          }
        }
        if(x-1>=0){
          swp(a[x][0],a[x-1][0]);
          show();
          cout<<"changes made\n";
          align(x-1);
        }
        clean(x);
      }
      cout<<move1<<"\n";
    }
    flag=true;
  }
  return 0;
}
 
