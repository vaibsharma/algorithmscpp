#include<bits/stdc++.h>

using namespace std;

vector<int> el,ne,b1,b2;
unordered_map<int,bool> v;

int main(){
  int n,i,p,q;
  scanf("%d",&n);
  for(int x=0;x<n;x++){
    scanf("%d",&i);
    el.push_back(i);
  }

  for(int x=0;x<n;x++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(el[j]!=0){
          p = (el[x]+el[i])*el[j];
          b1.push_back(p);
        }
        q = (el[x]*el[i] + el[j]);
        b2.push_back(q);
      }
    }
  }

  sort(b2.begin(),b2.end());
  sort(b1.begin(),b1.end());
  int ans = 0;

  for(int x : b1){
    vector<int>::iterator l,r;
    l = lower_bound(b2.begin(),b2.end(),x);
    r = upper_bound(b2.begin(),b2.end(),x);
    ans+= (r-l);
  }

  printf("%d",ans);
  return 0;
}
