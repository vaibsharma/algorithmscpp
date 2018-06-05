#include<bits/stdc++.h>

using namespace std;

int getans(vector<int> L, int l, int r, int check){
  int ans=-1,mid;
  while(l<=r){
    mid = (r+l)/2;
    if(L[mid]<check){
      ans = mid;
      l = mid+1;
    }
    else r = mid-1;
  }
  return ans+1;
}

int main(){
  int n;
  while(true){
    vector<int> L;
    scanf("%d",&n);
    if(n==0) return 0;
    for(int x=0; x<n; x++){
      int i;
      scanf("%d",&i);
      L.push_back(i);
    }
    sort(L.begin(),L.end());
    int ans=0;
    for(int x=n-1;x>1;x--){
      //if(x>0 && L[x]==L[x-1]) continue;
      int i=0,j=x-1;
      while(i<j){
        if(L[x]>(L[i]+L[j])){
          ans+= (j-i);
          i++;
        }
        else j--;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
