#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main()
{
    map <string,int> data ;
    vector <string> LOP;
    vector <string>::iterator it;
    string names = "",gift_receivers = "";
    int T=0,NOM=0,allias=0,gift=0,NOP=0,GTE=0,save=0;
    scanf("%d",&NOM);
    printf("%d \n",NOM);
    allias = NOM;
    while(allias--){
        cin>>names;
        LOP.push_back(names);
        data[names] = 0;
    }
    cout<<"List of people \n";
    for(it=LOP.begin();it!=LOP.end();it++){
    	cout<<*it<<"\n";
    }
    allias = NOM;
    cout<<"\n"<<"number of people :"<<allias<<endl;
    while(allias--){
    	cout<<"--> "<<3-allias<<endl;
        cin>>names;
        cout<<names<<" ";
        scanf("%d %d",&gift,&NOP);
        cout<<gift<<" "<<NOP<<" ";
        GTE = gift/NOP;
        save = gift - GTE*NOP;

        data[names] -= gift-save ;
        /*for(it = LOP.begin();x!=LOP.end();x++){
            if(names != *it){
                data[names] += GTE ;
            }
            else{
                data[names] -= gift ;
            }
        }
        */
        for(int x = 0; x<NOP;x++){
            cin>>gift_receivers;
            cout<<gift_receivers<<" ";
            data[gift_receivers] += GTE;
            cout<<"\n The total money in "<<gift_receivers<<"'s pocket is "<<data[gift_receivers]<<"\n";
        }
        cout<<"\n";
    }


    cout<<"\n"<<"Everything is fine :)";
    for(it=LOP.begin();it!=LOP.end();it++){
    // 	cout<<*it<<"\n";
    	cout<<*it<<" "<<data[*it]<<"\n";
     }


    return 0;
}
