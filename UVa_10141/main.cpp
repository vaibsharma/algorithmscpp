#include <iostream>
#include<cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N=0,p=0,r,complianceD=0,count=0;
    float d=0,lowest;
    string dump,proposal,compliance;
    scanf("%d %d",&N,&p);
    while(N!=0){
        ++count;
        for(int x=0;x<N;x++){
            getline(cin,dump);
            if(dump.empty()){
            	x--;
            }
            // cout<<dump<<"\n";
        }
        for(int x=0;x<p;x++){
            getline(cin,proposal);
            // cout<<"proposal "<<proposal<<"\n";
            scanf("%f %d",&d,&r);
            // cout<<"price "<<d<<" compliance "<<r<<"\n";
            if(x==0) {
                    compliance = proposal;
                    lowest = d;
                    complianceD = r;
            }
            for(int y=0;y<r;y++){
                getline(cin,dump);
                if(dump.empty()){
                	y--;
                }
                // cout<<"dump value is "<<dump<<"\n";
            }
            if(complianceD < r){
                compliance = proposal;
                lowest = d;
                complianceD = r;
            }
            else if(complianceD == r && lowest > d){
                compliance = proposal;
                lowest = d;
            }
        }
        cout<<"RFP #"<<count<<"\n"<<compliance<<"\n\n";
        scanf("%d %d",&N,&p);
    }
    return 0;
}
