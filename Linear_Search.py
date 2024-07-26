import sys

def linear_search(list,key):
    for i in range(len(list)):
        if(list[i]==key):
            print("The key exists inside the list when index =", i ,", value=",key)
            break
        else:
            print("The key doesnot exists inside the list when index = ",i)
    pass
def main():
    List=[1,4,78,9,10,74,90,2,5,64,65]
    print("The list is =\n",List,"\n")
    key=int(sys.argv[1])
    print("We are searching for =",key,"\n")
    linear_search(List,key)
    pass
main()