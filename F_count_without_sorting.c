#include<stdio.h>

void TwoDim_to_oneDim(int aux[][3],int m ,int n);

void freq_count(int Flatten_1D[]);

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
int  len=m*n;
//printf("Hello=%d",len);
int k=0,Tmp[len],temp;
for(int i=0;i<m;i++) 
    {
        for(int j=0;j<n;j++)       
        {
            temp=aux[i][j];
            Tmp[k]=temp;
            k++;
            //printf ("Hi=%d",k);
        }       
    }
printf("\n Dispaly the FLATTEN array\n ");
for (int s=0;s<len;s++)
{
    printf ("\t %d",Tmp[s]);

}
printf("\n");
freq_count(Tmp);

}


void freq_count(int Flatten_1D[12] )
{
int visited=-222;
 int f_count[12];
 int loc,j;
 for(int i=0;i<12;i++)
   {
       int count =1;
     for(int j = i+1; j < 12; j++)
        {  
            if(Flatten_1D[i] == Flatten_1D[j])
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
        printf("\nThe frequency of %d is = %d\n", Flatten_1D[i],f_count[i]);
    }

}