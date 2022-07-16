#include<stdio.h>
void TwoDim_to_oneDim(int aux[][3]);
void Bubble_Sort(int oneDim[]);
void freq_count(int Sort_1D[]);

int main()
{
    int A[4][3],i,j,temp ,count=0;
  
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
        printf("Enter value for A[%d][%d]:", i, j);
        scanf("%d",&A[i][j]);
        }
    }
    printf("\n Display the 2D array\n");
    for(int i=0;i<4;i++) 
    {
        for(j=0;j<3;j++)       
        {
            printf("\t %d",A[i][j]);
        
        }
       printf("\n");
    }
    TwoDim_to_oneDim(A);
}

void TwoDim_to_oneDim(int aux[4][3])
{
int k=0,Tmp[12],temp;
for(int i=0;i<4;i++) 
    {
        for(int j=0;j<3;j++)       
        {
            temp=aux[i][j];
            Tmp[k]=temp;
            k++;
        }       
    }
printf("\n Dispaly the 1D array\n ");
for (int s=0;s<12;s++)
{
    printf ("\t %d",Tmp[s]);

}
printf("\n");
// call Sorting
Bubble_Sort(Tmp);
}

void Bubble_Sort(int oneDim[12])
{
 int temp;
 for (int i=0;i<12;i++)
 {
     for(int j=i+1;j<12;j++)
    {
     if(oneDim[i]>oneDim[j])
        {
            temp=oneDim[i];
            oneDim[i]=oneDim[j];
            oneDim[j]=temp;
        }
    }

 }
    printf("\n Dispaly the sorted 1D array\n ");
    for (int s=0;s<12;s++)
       {
         printf ("\t %d",oneDim[s]);

        }
    printf("\n");
 freq_count(oneDim);
}


void freq_count(int Sort_1D[12])
{

 int visited=-222;
 int f_count[12];
 int loc,j;
 for(int i=0;i<12;i++)
   {
       int count =1;
     for(int j = i+1; j < 12; j++)
        {  
            if(Sort_1D[i] == Sort_1D[j])
            {  
                count++;  
                //To avoid counting same element again  
                f_count[j] = visited; 
                
            }        
        }
        if(f_count[i] != visited)  
                f_count[i] = count;       
   }
    for(int i=0;i<12;i++)
    {
        if(f_count[i] != visited)  
        printf("\nThe frequency of %d is = %d\n", Sort_1D[i],f_count[i]);
    } 
}