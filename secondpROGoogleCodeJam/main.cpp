#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int T=0,count=0,length=0,k=0;
    vector<int> getAnswer(string,int),result;
    string pattern;
    scanf("%d",&T);
    while(T--){
        count++;
        cin>>pattern>>k;
        length = pattern.length();
        result = getAnswer(pattern,k);
        if(result[0] == 1){
            printf("Case #%d: %d\n",count,result[1]);
        }
        else{
        cout<<"Case #"<<count<<": IMPOSSIBLE\n";}

    }
    return 0;
}
vector<int> getAnswer(string pattern,int k){
    int length = pattern.length(),count=0;
    int front = 0,back=length-1,allias=0;;
    bool flag =false,turn=false;
    vector<int> status;
    while(front+k<back){
        if(pattern[front] == '-' && !turn){
            count++;
            for(int x=0;x<k;x++){
                if(pattern[front+x] == '+'){
                    pattern[front+x] = '-';
                    if(!flag){
                    flag = true;
                    allias = front +x;
                    }
                }
                else pattern[front+x] = '+';
            }
            if(flag){
                front = allias;
            }
            else front += k;

        }
        if(pattern[back] == '-' && turn){
            count++;
            for(int x=0;x<k;x++){
                if(pattern[back-x] == '+'){
                    pattern[back-x] = '-';
                    if(!flag){
                    flag = true;
                    allias = back-x;
                    }
                }
                else pattern[back-x] = '+';
            }
            if(flag){
                back = allias;
            }
            else back -= k;
        }
        flag = false;
        turn = !turn;
        if(back - front <= 1){
            status.push_back(1);
            status.push_back(count);
            return status;
        }
        if(back-front-1 < k && back-front >1){
        status.push_back(0);
        status.push_back(count);
        return status;
        }
        back--;
        front++;
    }
}
