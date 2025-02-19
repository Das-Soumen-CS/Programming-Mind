#include<stdio.h>
#include<stdlib.h>
#include <time.h>

/*Prototype Decalration for Linear Search*/
/*Ls= array, key =search element , argc =No of command line arguments ,flag =staus variable */
int Linear_Search(int LS[],int key,int argc,int flag);

/*Fucntion Defintion for Linear_Search*/
int Linear_Search(int LS[],int key,int argc,int flag)
{
  for(int i=1;i<=argc;i++)
      {
        if(LS[i]==key)
            {
                printf("Element found at position= %d, Value= %d",i,key);
                printf("\n");
                flag++;
            }
      }
    printf("\nThe Key exists inside array = %d times",flag);
    printf("\n");
}

int main(int argc,char* argv[])
{
/*Cpu Time Measure*/
 clock_t start, end;
 double cpu_time_used;
 start = clock();
 /*Creating Array of size argc-1*/
        int LS[argc-1],i,key,flag=0,result;
            for(i=1;i<=argc-1;i++)
                {
                    LS[i]=atoi(argv[i]);  /*atio = string to integer conversion*/
                }

            for(i=1;i<=argc-1;i++)
                {
                    printf("\nindex[%d]=%d",i,LS[i]);
                }
        /*Looking for the Search Element*/
        printf("\n Please enter search key=");
        scanf("%d",&key);

        /*Function Call Linear Saerch*/
        result=Linear_Search(LS,key,argc,flag);
end=clock();
/*Calcutae CPU Time*/
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("\nExecution time=%f\n", cpu_time_used);

return 4.555555555555555555555555555555555555;

}