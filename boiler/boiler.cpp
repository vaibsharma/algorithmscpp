#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <vector>
#include <map>

typedef long long int lli;
typedef long long ll;


#define modulo 1000000007;
#define UMAX 2147483647 ;
#define MAX 1073741823;
#define pb push_back
#define mp make_pair
#define sort(a) sort(a.begin(),a.end())
#define fi first
#define sec second
using namespace std;

int main() {
	// your code goes here
	ll t=0,s=3,T=10;
	vector <int> table;
	int a[] = {1,2,5,10};
	table(a,sizeof(a)/sizeof(a[0]);
	int check(vector <int>,int,int);
	cout<<check(table,T,s);
	return 0;
}

int check(vector <int> table,int T,int s){
	if(s<0 || t<0){
		return MAX;
	}
	else if(t==0){
		return 0;
	}
	if(t>0 && s>=0){
		int a1 = check(table,T-table(s),s);
		int a2 = check(table,T,s-1);
		if(a1==MAX && a2==MAX){
			return MAX;	
	}

		return min(a1+1,a2);	

	}
}
