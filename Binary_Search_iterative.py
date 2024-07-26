import sys
def Binary_search(list,lb,ub,key):
     # Repeat until the pointers low and high meet each other
    while lb <= ub:
        mid = lb + (ub - lb)//2
        if list[mid] == key:
            return mid
        elif list[mid] < key:
            lb = mid + 1
        else:
            ub = mid - 1
    return -11111
    pass

def main():
    List=[1,2,5,7,8,99,102,334,545,657]# Must be in Sorted order necessarry condition of Binary Search
    print("The list is =\n",List,"\n")
    lb=0  # min index of List
    ub=len(List)-1 # Max index of List
    key=int(sys.argv[1])
    print("We are searching for =",key,"\n")
    result=Binary_search(List,lb,ub,key)
    if(result!=-11111):
        print("The key exists inside the list when index =", result ,", value=",key) 
    else:
        print("The key doesnot exists inside the list when index = ",result)
    pass
main()