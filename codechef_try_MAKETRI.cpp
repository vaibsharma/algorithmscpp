#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp{
	bool operator()(const string& a, const string& b){
		
		if(a.size() == b.size()){
			if(a.compare(b) == 0){
				return true;
			}
			else {
				if(a.compare(b)<0){
					return true;
				}
				else{
					return false;
				}
			}
		}
		else{
			return a.size() < b.size();
		}
	}
} ;


int main(){
	long int N =0,x=0,k=0,count=0;
	string L="",R="",push;
	vector <string> main;
	vector <string>::iterator it;
	cmp check;
	bool comp(string,string,string,string);
	// cout<<"enter the value of N : ";
	cin>>N>>L>>R;
	// cin>>N;
	
	// cout<<"\n enter the value in the list :-"<<endl;
	for(x=0;x<N;x++){
		cin>>push;
		
		main.push_back(push);
	}
	sort(main.begin(),main.end(),check);
	for(it=main.begin();it!=main.end();it++){
		cout<<*it<<endl;
	}
	for(x=0;x<N;x++){
		for(k=x;k<N;k++){
			if(comp(main.at(x),main.at(k),L,R)){
					
					// cout<<x<<" "<<k<<" "<<N-k-1<<endl;
					// count+=(N-k-1);
					// k=N;
				count++;
			}
		}
	}
	printf("\n%ld",count);
	// if(comp("1","2","1","4")){
	// 	printf("triangle is possible");
	// }
	// else{
	// 	printf("Not possible");
	// }
	return 0;
}
bool comp(string a,string b,string L,string R){
	bool addition(string,string,string);
	
	if(addition(a,R,b)||addition(b,R,a)){
		// cout<<"\n 73 return true";
		return true;
	}
	else if(addition(a,b,L)||addition(a,b,R)){
		// cout<<"\n 77 return true";
		return true;
	}
	else{
		// cout<<"\n 81 return false";
		return false;
	}
	
}

bool addition(string a,string b,string c){
	int first[20] = {0},second[20] = {0}, a_size = a.length()-1, b_size = b.length()-1,c_size=c.length()-1,AN=0,BN=0,CN=0;
	char a_ = ' ',b_=' ',c_= ' ';
	for(int x = 19;x>0;x--){
		if(a_size < 0){
			a_ = '0';
		}
		else{
			a_ = a.at(a_size);
		}
		if(b_size < 0){
			b_ = '0';
		}
		else{
			b_ = b.at(b_size);
		}
		if(c_size<0){
			c_ = '0';
		}
		else{
			c_ = c.at(c_size);
		}
		AN = a_ - '0';
		BN = b_ - '0';
		CN = c_ - '0';
		first[x] = first[x]+((AN +BN)%10);
		first[x-1] = first[x-1] + ((AN+BN)/10);
		second[x] = CN ;
		a_size--;
		b_size--;
		c_size--;
		
	}
	// cout<<"adding "<<a<<" and"<<b<<" ";
	// for(int x=0;x<20;x++){
	// 	cout<<first[x];
	// }
	// cout<<endl<<"second array of "<<c<<" is"<<endl;
	// 	for(int x=0;x<20;x++){
	// 	cout<<second[x];
	// }
	
	for(int x=0;x<20;x++){
		if(first[x]>=second[x]){
			
		}
		else{
				// cout<<"adding "<<a<<" and "<<b<<" results lower than "<<c<<"\n";
			return false;
			
		}
		
		
	}
	// cout<<"adding "<<a<<" and "<<b<<" results greater than "<<c<<"\n";
	
	return true;
	
}