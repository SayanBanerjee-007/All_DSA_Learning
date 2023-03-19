#include<stdio.h>
#include<string.h>

void powerSet(char *string,int i,char *recentSTR)
{
    if(i == strlen(string)-1)
    {
        printf("%s\t",recentSTR);
        return;
    }
    powerSet(string,i+1,strcat(recentSTR,string[i]));
    powerSet(string,i+1,recentSTR);

}
int main()
{
    char string[100];
    printf("Enter your string: \n");
    gets(string);
    powerSet(string,0,NULL);
    return 0;
}
/*
#include <stdio.h>
#include <string.h>

void powerSet(char *string, int i, char *recentSTR)
{
    if (i == strlen(string)-1)
    {
        printf("%s\t", recentSTR);
        return;
    }
    char *cpy = recentSTR;
    char *temp = &string[i] ;
    strcat(recentSTR, temp);
    powerSet(string, i + 1, recentSTR);
    powerSet(string, i + 1, cpy);
}
int main()
{
    char string[100];
    printf("Enter your string: \n");
    gets(string);
    char recentSTR[100]={" "};
    powerSet(string,-1 ,recentSTR);
    // strcat(recentSTR,string);
    // puts(recentSTR);
    return 0;
}
*/