import sys

def Binary_search_recursive(list,key,lb,ub):
     # Repeat until the pointers lb and ub meet each other
    if ub >= lb:
        mid = lb + (ub - lb)//2 # compute mid 
        if list[mid] == key:# If key is found at mid position, then return mid
            return mid
        elif list[mid] > key: # Search the left half
            return Binary_search_recursive(list, key, lb, mid-1) # lb unchanged but ub=mid-1 
        else:# Search the right half
            return Binary_search_recursive(list, key, mid + 1, ub) # lb=mid+1 but ub is unchanged
    else:
        return -55
    pass

def main():
    List=[1,2,5,7,8,99,102,334,545,657]# Must be in Sorted order necessarry condition of Binary Search
    print("The list is =\n",List,"\n")
    lb=0  # min index of List
    ub=len(List)-1 # Max index of List
    key=int(sys.argv[1])
    print("We are searching for =",key,"\n")
    result=Binary_search_recursive(List,key,lb,ub)
    if(result!=-55):
        print("The key exists inside the list when index =", result ,", value=",key) 
    else:
        print("The key doesnot exists inside the list when index = ",result)
    pass
main()