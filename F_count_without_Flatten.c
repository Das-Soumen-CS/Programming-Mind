#include<stdio.h>

void TwoDim_to_oneDim(int aux[][3],int m ,int n);



int main()
{
    int m,n;
    printf("Enter the no of Rows  :=");
    scanf("%d",&m);
    printf("Enter the no of coulmn:=");
    scanf("%d",&n);
    int A[m][n],i,j,temp ,count=0;
  
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
        printf("Enter value for A[%d][%d]:", i, j);
        scanf("%d",&A[i][j]);
        }
    }
    printf("\n Display the 2D array\n");
    for(int i=0;i<m;i++) 
    {
        for(j=0;j<n;j++)       
        {
            printf("\t %d",A[i][j]);
        
        }
       printf("\n");
    }
    TwoDim_to_oneDim(A,m,n);
}

void TwoDim_to_oneDim(int aux[][3], int m ,int n)
{
int  flag=-222;

int k=0,temp;

int f_count[4][3];

for(int i=0;i<m;i++) 
    {
        int count=1;
        for(int j=0;j<n;j++)       
        {
            
            //aux[i][j]=flag;
                       
                for(int k=j+1;k<m*n;k++) 
                {
                            if(aux[i][j]==aux[j][k])
                            {
                            count++;
                            f_count[j][k]=flag;
                            }
                         
                        if(f_count[j][k] != flag)  
                         f_count[j][k] = count;      
                        
                }
        //printf("\nThe frequency of %d is = %d\n", temp,count);
            
        } 
    } 
     for(int i=0;i<m;i++)
          {
             for(int j=0;j<=n;j++)
               {
         
                 if(f_count[i][j] != flag)  
                 printf("\nThe frequency of %d is = %d\n", aux[i][j],f_count[i][j]);
               }
          }
           
 }


 



