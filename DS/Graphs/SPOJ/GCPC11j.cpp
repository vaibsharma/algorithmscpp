#include<bits/stdc++.h>

using namespace std;

unordered_map<int,vector<int> > m;

int dfs(int x, int a){
  int ans=0;
  for(int i=0;i<m[x].size();i++){
    if(m[x][i] != a) ans = max(ans,dfs(m[x][i],x));
  }
  return ans+1;
}

int main(){
  int T, n,f,t;
  scanf("%d",&T);
  while(T--){
    unordered_map<int,vector<int> > m;
    unordered_map<int,int> c;
    scanf("%d",&n);
    int idg=0;
    for(int x=0;x<n-1;x++){
      scanf("%d %d",&f,&t);
      c[f]++;
      c[t]++;
      if(c[idg]<c[f]) idg = f;
      if(c[idg]<c[t]) idg = t;
      m[f].push_back(t);
      m[t].push_back(f);
    }

    int ans = INT_MAX;
    vector<int> s;

    
      for(int i=0;i<m[idg].size();i++){
        int j = dfs(m[idg][i],idg);
        //cout<<m[idg][i]<<" is: "<<j<<"\n";
        s.push_back(j);
      }

    ans = s[0];

    for(int x=0;x<s.size();x++){
      for(int i=x+1;i<s.size();i++){
        ans = max(ans,s[x]+s[i]);
      }
    }

    //if(ans%2) ans++;

    cout<<(ans+1)/2<<"\n";
    for(int x=0;x<n;x++) m[x].clear();
    //if(T) cout<<"\n";
  }
  return 0;
}
