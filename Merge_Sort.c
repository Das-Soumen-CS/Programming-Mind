#include<stdio.h>
#include<stdlib.h>
int Merge_Sort_Recursive(int Un_Sorted[],int low, int high);
int Merge(int Un_Sorted[],int low ,int mid,int high);

int main(int argc, char * argv[])
{
    int Un_Sorted[argc-1];
    int i;
    /*Insert Elements inside the Empty array*/
    for(i=1;i<=argc-1;i++)
    {
        Un_Sorted[i]=atoi(argv[i]);
    }
/*Display The unsorted array */
    for(i=1;i<=argc-1;i++)
    {
      printf("\nIndex[%d]=%d",i,Un_Sorted[i]);
    }
    printf("\n");
    Merge_Sort_Recursive(Un_Sorted,1,argc-1);
return 0;
}

int Merge_Sort_Recursive(int Un_Sorted[],int low, int high)
{
    if(low<high)
    {
    int mid=low+(high-low)/2;
    /*Recursive Call for Left and Right Subarray*/
    Merge_Sort_Recursive(Un_Sorted,low,mid);
    Merge_Sort_Recursive(Un_Sorted,mid+1,high);
    /*Merge */
    Merge(Un_Sorted,low,mid,high);
    }
}

int Merge(int Un_Sorted[],int low ,int mid,int high)
{
    int left_sub_array_size=(mid-low)+1;
    int right_sub_array_size=high-mid;
    int i,j,k;

    /*Create Two Temporary Array one for Left subarray and Right subarray*/
    int left_sub_array[left_sub_array_size];
    int right_sub_array[right_sub_array_size];

    // copying the data from un_sorted array to temporary array
    for (i = 0; i < left_sub_array_size; i++)
        left_sub_array[i] = Un_Sorted[low + i];
 
    for (j = 0; j < right_sub_array_size; j++)
        right_sub_array[j] = Un_Sorted[mid + 1 + j];

    // merging of the array
    i = 0;	// intital index of first subarray
    j = 0;	// inital index of second subarray
    k = low; // initial index of parent array
    while (i < left_sub_array_size && j < right_sub_array_size)
    {
        if (left_sub_array[i] <= right_sub_array[j])
        {
            Un_Sorted[k] = left_sub_array[i];
            i++;
        }
        else
        {
            Un_Sorted[k] = right_sub_array[j];
            j++;
        }
        k++;
    }
    
    //copying the elements from left_sb_array, if any
    while (i < left_sub_array_size)
    {
        Un_Sorted[k] = left_sub_array[i];
        i++;
        k++;
    }
 
    // copying the elements from Right[], if any
    while (j < right_sub_array_size)
    {
        Un_Sorted[k] = right_sub_array[j];
        j++;
        k++;
    }

for(i=low;i<=high;i++)
{
    printf("%d ",Un_Sorted[i]);
}
printf("\n");
}