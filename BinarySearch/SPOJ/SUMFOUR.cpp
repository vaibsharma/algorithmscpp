#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  vector<int> a,b,c,d,n1,n2;
  scanf("%d",&n);

  for(int x=0;x<n;x++){
    int u,v,i,j;
    scanf("%d %d %d %d",&u,&v,&i,&j);
    a.push_back(u);
    b.push_back(v);
    c.push_back(i);
    d.push_back(j);
  }

  for(int i:a){
    for(int j: b){
      n1.push_back(i+j);
    }
  }

  for(int i:c){
    for(int j:d){
      n2.push_back(i+j);
    }
  }

  //sort(n1.begin(),n2.end());
  sort(n2.begin(),n2.end());

  int ans=0;

  for(int x:n1){
    vector<int>::iterator l,r;
    l = lower_bound(n2.begin(),n2.end(),-x);
    r = upper_bound(n2.begin(),n2.end(),-x);
    ans += r-l;
  }
  cout<<ans;
  return 0;
}
