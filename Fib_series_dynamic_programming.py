import pandas as pd
import numpy as np
import sys
from colorama import init
from termcolor import colored
from colorama import Fore, Back, Style

def dynamic_Fib_series(n,Fib_list,intial_val):
    print("\nIntial value inside List before fib operation =\n",Fib_list,"\n")
    Fib_list[0]=0 # O(1)
    Fib_list[1]=1 #O(1)
    loop_count=0  # O(1)
    for i in range(2,n): # iterate =n-2 times hence # O(n)
        Fib_list[i]=Fib_list[i-1]+ Fib_list[i-2] 
        loop_count+=1
        if(i%2==0):
            print("\033[93m {}\033[00m" .format(Fib_list))
        else:
            print("\033[96m {}\033[00m" .format(Fib_list))          
    return Fib_list,loop_count
    pass            

def main():         # Overall Time Complexity T(n)= O(n)
    Fib_list=[]          
    n=int(sys.argv[1]) #O(1)
    initial_val=int(sys.argv[2]) # O(1)
    for i in range(n):  # O(n)
        Fib_list.append(initial_val)
    Final=dynamic_Fib_series(n,Fib_list,initial_val)
    print("\n Final_list and No of Loop iteration=\n",Final,"\n")
    pass

main()
