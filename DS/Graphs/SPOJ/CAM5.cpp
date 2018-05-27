#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
  int T,n,e,f,t,c;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d",&n,&e);
    unordered_map<int,vector<int> > m;
    unordered_map<int, bool> v;
    for(int x=0;x<e;x++){
      scanf("%d %d",&f,&t);
      m[f].push_back(t);
      m[t].push_back(f);
    }
    c = 0;
    for(int x=0;x<n;x++){
     
      if(!v[x]){
        c++;
        v[x] = true;
        stack<int> s;
        s.push(x);
        while(!s.empty()){
          int p = s.top();
          s.pop();
          v[p] = true;
          for(int i=0;i<m[p].size();i++){
            if(!v[m[p][i]]) s.push(m[p][i]);
          }
        }
      }
    }
    cout<<c<<"\n";
  }
  return 0;
}
