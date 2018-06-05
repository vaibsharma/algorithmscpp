#include<bits/stdc++.h>

using namespace std;

//#define pi 3.14159265358979

vector<double> v;

bool check(double mid, int u){
  int f=0;
  for(double x: v){
    double td = x;
    while(td>=mid){
      f++;
      td-=mid;
    }
  }
  return f>=u;
}

int main(){
  int T,n,f;
  double pi = acos(-1);
  scanf("%d",&T);
  cout<<fixed;
  while(T--){
    double l=0,r=1e8+7,mx=0,ans=-1;
    scanf("%d %d",&n,&f);
    for(int x=0;x<n;x++){
      double r;
      scanf("%lf",&r);
      //cout<<r<<" ";
      v.push_back(pi*r*r);
      mx+= pi*r*r;
    }
    //cout<<endl;

    r = (mx>r)?mx:r;

    while(abs(r-l)>=0.0000001){
      double mid = (r+l)/2;
      if(check(mid,f+1)){
        ans = mid;
        l = mid;
      }
      else r = mid;
    }
    cout<<setprecision(4)<<ans<<"\n";
    v.clear();
  }
  return 0;
}
