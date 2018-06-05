#include<bits/stdc++.h>

using namespace std;

void getsubset(int start, int n, vector<int> ar, vector<int> &r){
  int sum=0;
  // for(int i=0;i<n;i++) cout<<start+i<<" ";
  for(int x=0;x<(1<<n);x++){
    sum=0;
    for(int i=0;i<n;i++){
      if(x&(1<<i)) sum+= ar[i+start];
    }
    r.push_back(sum);
  }
}

int main(){
  int n,lo,up;
  vector<int> a,b,ar;
  scanf("%d %d %d",&n,&lo,&up);
  for(int x=0; x<n;x++){
    int i;
    scanf("%d",&i);
    ar.push_back(i);
  }

  getsubset(0,n/2,ar,a);
  getsubset(n/2,n-(n/2),ar,b);
  sort(b.begin(),b.end());
  long long int ans=0;
  for(int x:a){
    vector<int>::iterator l,r;
    l = lower_bound(b.begin(),b.end(),lo-x);
    r = upper_bound(b.begin(),b.end(),up-x);
    ans += (r-l);
  }
  cout<<ans;
  return 0;
}
