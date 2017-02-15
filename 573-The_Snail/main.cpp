#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int Nslide=0,days=0,height=0;
    float jump=0,decrement=0,Cloc=0,Dslide=1;
    scanf("%d %f %d %f",&height,&jump,&Nslide,&decrement);
    decrement = decrement/100;
    while(jump < height){
        days++;
        if(days == 1){

        }
        else{
            Dslide = Dslide*decrement;
            jump-=Dslide;
            decrement = decrement*decrement;

        }
        if(jump < 0 ){
            printf("failure in day %d \n",days);
        }


        Cloc = Cloc + jump -1;


    }
    if(height>jump){
        printf("failure in day %d \n",days);
    }

    return 0;
}
