import sys
import time


# record start time
start = time.time()

fib_list=[]

def fibonacci_iterative(n,a,b):
    fib_list.append(a) # Append first Base value to the list
    fib_list.append(b) # Append Second Base value to the list
    c=0
    num_assign=0
    for i in range(0,n):
        start = time.time()
        c=a+b  # addition of previous two memory location
        fib_list.append(c) # Append the sum value of  previous two memory location    
        a=b  # Assignment
        b=c  # Assignment
        end = time.time()
        # show time of execution per iteration
        print(f"Iteration: {i}\tTime taken for one addition and two assignment: {(end-start)*10**3:.03f}ms")
    print("\n")
    print(*fib_list,sep=',')
    print("\n")
    pass

def main():
    n=int(sys.argv[1])
    a=0
    b=1
    fibonacci_iterative(n,a,b)
    # record end time
    end = time.time() 
    print("The Total Excecution Time is =:",(end-start) * 10**3, "ms")
    pass

main()