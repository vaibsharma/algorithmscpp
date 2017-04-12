#include <iostream>
#include <cstdio>
#include<string>
using namespace std;
int ar[] = {2,3,47,8};
int main()
{
    void mergeSort(int arr[],int x,int y,int m);
    cout << "Hello world!" << endl;
    int x =0;
    for(int x=0;x<4;x++){
    cout<<ar[x];
    }
    cout<<"performing merge sort";
    mergeSort(ar,0,3);
        return 0;
}
void mergeSort(int arr[],int x,int y){
    if(x<y){
        int m = (x+y)/2;
    }

}
