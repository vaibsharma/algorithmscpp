#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> sieve(int n){
	bool arr[n];
	vector<int> primes;
	memset(arr,true,sizeof(arr));
	for(int x=2;x<=sqrt(n);x++){
		if(arr[x]){
			for(int i=2*x;i<=n;i+=x){
				arr[x] = false;
			}
		}
	}
	for(int x=2;x<=n;x++){
		if(arr[x]){
			primes.push_back(x);
			cout<<x<<" ";
		}
	}
	return primes;
}
int main() {
	// your code goes here
	int n,a,b,f;
	cin>>n;
	vector<int> primes;
	primes = sieve(1050);
	while(n--){
		cin>>a>>b>>f;
		int l = (b-a)+1;
		int arr[l];
		memset(arr,0,sizeof(arr));
		for(int x=0;x<primes.size();x++){
			int p = (a/primes[x])*primes[x];
			if(p<a) p+=primes[x];
			for(int i=p-a;i<l;i+=primes[x]){
				arr[i]++;
			}
		}
		// for(int i=0;i<l;i++){
		// 	if(arr[i]==f && a+i<=b) cout<<a+i<<" ";
		// }
		// cout<<"\n";
	}
	return 0;
}
