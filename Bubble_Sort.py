def Bubble_Sort(List):
    n=len(List)
    print("List before sort=",List,",","No of elements in List=",n)
    swap_count=0
    for i in range(0,n-1):
        for j in range(0,n-i-1):
            if(List[j]>List[j+1]):
                temp=List[j]
                List[j] = List[j+1] 
                List[j+1] =temp
                swap_count=swap_count+1
        #print("swap_count per ouetloop=",swap_count)
            print("i=",i,",","j=",j,",","List=",List)
    #print(swap_count)
    return List ,swap_count
    pass
    
def main():
    #List=[2,5.7,9,99,10,24,2,6]
    List=[]
    length=int(input("How many you want to sort="))
    for k in range(0,length):
               List.append(int(input("Value is=")))
    Sorted_List,swap_count=Bubble_Sort(List)
    print("Sorted list is=",Sorted_List)
    print("No of swap_count=",swap_count)
    pass
    
main()