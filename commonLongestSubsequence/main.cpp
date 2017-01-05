#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

string A,B;
int LCS(int,int,int a[][10],char b[][10]);
void check(int,int,int a[][10],char b[][10]);
int main()
{
    int memo[10][10];
    char dir[10][10];

    printf("Please enter the first string :");
    cin>>A;
    printf("\nNow Enter the second string :");
    cin>>B;

    for(int i=0;i<A.length()+1;i++)
    {
        for(int j=0;j<B.length()+1;j++){
            memo[i][j] = 0;
            dir[i][j] = ' ';
      }
    }

    check(A.length(),B.length(),memo,dir);

    for(int i=0;i<A.length()+1;i++)
    {
        for(int j=0;j<B.length()+1;j++){
            printf("%d ",memo[i][j]);
        }
        printf("\n");
    }
		 printf("\n");
    for(int i=0;i<A.length()+1;i++)
    {
        for(int j=0;j<B.length()+1;j++){
            printf("%c ",dir[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void check(int a, int b,int memo[][10],char dir[][10]){
    printf("The total number of subsequence of these to string is : %d",LCS(a,b,memo,dir));
}
int LCS(int a,int b,int memo[][10],char dir[][10]){
    int i,j;
    if(a > 0 && b > 0){

    if(memo[a][b] != 0){
        //printf("The memo[%d][%d] is :%d")
        return memo[a][b];
    }
    else if(A.at(a-1) == B.at(b-1)){
        memo[a][b] = LCS(a-1,b-1,memo,dir) + 1;
        dir[a][b] = '\\' ;
    }
    else{
        i = LCS(a-1,b,memo,dir);
        j = LCS(a,b-1,memo,dir);
        memo[a][b] = max(i,j);
        if(memo[a][b] == i){
            dir[a][b] = '|';
        }
        else{
            dir[a][b] = '~';
        }

    }
    return memo[a][b];
    }
    else return 0;
}
