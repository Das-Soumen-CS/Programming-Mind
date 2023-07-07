#include<stdio.h>
int CheckPalindrome(char str[20]);

int main(int argc ,char *argv[])
{   
    printf("No of Command Line arguments =%d\n",argc);
    int temp=0;
    if(argc==1 || argc>2)
     printf("\n Caution::Please provide the String || No of command line arguments exit the limit !\n ");
    else
    {
     temp=CheckPalindrome(argv[1]); /*Function Call*/

        if(temp==1)
            printf("\n Not a palindrome \n");
        else
            printf("\n Yes it is a Palindrome \n");
    }
    return 0;
}

int CheckPalindrome(char str[20])  /*Function Defination*/
{  
    printf("The Input String is = %s \n",str);
    /*Find String Length*/
    int str_len=0,i=0;
    int flag;
    for ( int i = 0; str[i] != '\0'; ++i)
          str_len=i+1;
    printf("\nLength of String is= %d\n", str_len);
    for (i = 0; i < str_len; i++) 
      {
        if (str[i] != str[str_len -i-1 ]) 
             flag=1;   
            
      }
 return flag;       
}