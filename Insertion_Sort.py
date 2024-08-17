def Insertion_Sort(List):
    n=len(List)
    print("List before sort=",List,",","No of elements in List=",n)
    swap_count=0

    if n <= 1:
        return  # If the array has 0 or 1 element, it is already sorted, so return
 
    for i in range(1, n):  # Iterate over the List starting from the second element
        key = List[i]  # Store the current element as the key to be inserted in the right position
        print("key=",key)
        j = i-1
        print("j=",j)
        while j >= 0 and key < List[j]:  # Move elements greater than key one position ahead
            List[j+1] = List[j]  # Shift elements to the right
            j -= 1
            swap_count
        print(List)
        List[j+1] = key  # Insert the key in the correct position
        
    return List,swap_count
    pass
    
def main():
    #List=[2,5.7,9,99,10,24,2,6]
    List=[]
    length=int(input("How many you want to sort="))
    for k in range(0,length):
               List.append(int(input("Value is=")))
    Sorted_List,swap_count=Insertion_Sort(List)
    print("Sorted list is=",Sorted_List)
    print("No of swap_count=",swap_count)
    pass
    
main()