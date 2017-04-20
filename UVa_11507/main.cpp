#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int l=0,pos=0;
    char sign='+';
    string data,ans="xyz";
    scanf("%d",&l);
    while(l!=0){
    	// cout<<"starting new\n";
    for(int x=0;x<l-1;x++){
        cin>>data;
        // cout<<data<<" ";
        if(data != "No"){
        if(pos == 0){
                if(data[1] == 'y'){
                    pos = 1;
                }
                else pos=2;

                if(data[0] == '-'){
                    sign =='-'? sign='+':sign='-' ;
                }
        }
        else if(pos == 1){
            if(data[1] == 'y'){
                pos = 0;
                // cout<<"making it pointing x\n";
                data[0] == sign ? sign='-':sign='+';
            }


        }
        else if(pos == 2){
            if(data[1] == 'z'){
                pos = 0;
                // cout<<"making it pointing x\n";
                data[0] == sign ? sign='-':sign='+';
            }

        }
        // cout<<data<<"\n";
        // cout<<"After change \n";
        // cout<<"After "<<data<<" "<<sign<<ans[pos]<<"\n";
        }
    }

    cout<<sign<<ans[pos]<<"\n";
    pos=0,sign='+';
    scanf("%d",&l);
    }
    return 0;
}
