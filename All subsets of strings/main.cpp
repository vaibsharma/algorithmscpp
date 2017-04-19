#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	string avr=" ";
	printf("please enter the string to subset for ?\n");
	cin>>avr;
	int slength = avr.length();
	int total_sSets = pow(2,slength);
	printf("%d",total_sSets);
	for(int i =0;i<total_sSets;i++){
		 for(int x=0;x<slength;x++){
		 	if(i & (1<<x)){
		 		printf("%c",avr[x]);
		 	}
		 }
		 printf("\n");
	}
	return 0;
}
