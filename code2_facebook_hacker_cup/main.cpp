#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int T=0,N=0,Wi=0,d,count=0,cases=0,no_of_pops=0,front=0,back=0;
	float top=0;
	vector<int>::iterator last;

	scanf("%d",&T);
	while(T--){
		cases++;
		scanf("%d",&N);
		back = N;
		vector<int> arr;
		for(int x=0;x<N;x++){
			scanf("%d",&d);
			arr.push_back(d);
		}
		sort(arr.begin(),arr.end());
		reverse(arr.begin(),arr.end());


		for(vector<int>::iterator x = arr.begin();x!=arr.end();x++){
			top = *x;
			no_of_pops = ceil(50/top)-1;
			front++;
			// if(no_of_pops >0){
			// 	arr.pop_back();
			// }
			// printf("top is : %f no. of pops required : %d  front : %d back: %d\n",top,no_of_pops,front,back);


			while(front < back && no_of_pops > 0){

				no_of_pops-- ;
				// printf("poping %d\n",arr.back());
				arr.pop_back();
				back--;

			}

			if(no_of_pops <= 0){
				// printf("pop done\n");
				count++;
			}
		}
		printf("Case #%d: %d\n",cases,count);

		count = 0;
		front=0;


	}
	return 0;
}
