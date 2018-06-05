#include<bits/stdc++.h>

using namespace std;

vector<int> a,b,d1,d2;

int bsrch(int s, vector<int> b){
  int ans =-1,mid=0,l=0,r=b.size()-1;

  while(l<=r){
    mid = (l+r)/2;
    if(b[mid]==s) return mid;
    else if(b[mid]<s) l = mid+1;
    else r = mid-1;
  }
  return -1;
}

int main(){
  int n1,n2;
  while(true){
    scanf("%d",&n1);
    if(n1==0) return 0;

    for(int x=0;x<n1;x++){
      int i;
      scanf("%d",&i);
      a.push_back(i);
    }

    scanf("%d",&n2);

    for(int x=0;x<n2;x++){
      int i;
      scanf("%d",&i);
      b.push_back(i);
    }

    d1.push_back(0);
    d2.push_back(0);

    int i=0,j=0;
    while(i<n1 && j<n2){
      if(a[i]<b[j]){
        int k = bsrch(a[i],b);

        if(k==-1) d1.push_back(a[i]+d1.back());
        else d1.push_back(a[i]+max(d1.back(),d2[k]));

        i++;
      }
      else{
        int k = bsrch(b[j],a);

        if(k==-1) d2.push_back(b[j]+d2.back());
        else d2.push_back(b[j]+max(d2.back(),d1[k]));
        j++;
      }
      //cout<<d1.back()<<" "<<d2.back()<<"\n";
    }

    while(i<n1){
      int k = bsrch(a[i],b);

      if(k==-1) d1.push_back(a[i]+d1.back());
      else d1.push_back(a[i]+max(d1.back(),d2[k]));

      i++;
      //cout<<d1.back()<<" "<<d2.back()<<"\n";
    }

    while(j<n2){
      int k = bsrch(b[j],a);

      if(k==-1) d2.push_back(b[j]+d2.back());
      else d2.push_back(b[j]+max(d2.back(),d1[k]));
      j++;
      //cout<<d1.back()<<" "<<d2.back()<<"\n";
    }

    cout<<max(d1.back(),d2.back())<<"\n";

    a.clear();
    b.clear();
    d1.clear();
    d2.clear();
  }

  return 0;
}
