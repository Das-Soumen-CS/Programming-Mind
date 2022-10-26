import sys
import time
import random
import math
from termcolor import colored
from Crypto.Util import number

# .....prime checking function.......#
def check_prime(tmp):  
    if (tmp>1) :
        for i in range(2,tmp):
            if (tmp % i==1):
                   
                   return tmp
            else:
                print("The No ",tmp,"is not a prime number ,chose another number")
                exit()
    else:
        print("The No",tmp,"is negetive but must be a non negetive prime")
        exit()
pass
    
#.....................Encryption function............#
def encryption(p,q,plain_text):
    print("The ASCII vaue of the Plain_text "+ colored(chr(plain_text),'green',attrs=['bold']) + " is :=",plain_text)
    n=p*q
    phi_n=(p-1)*(q-1)
    key=[] # Array to store the encryption key values in the Range of 2 to Phi_n that e chosen randomly among them
    for i in range(2,phi_n//2): # some body can take Phi_n instead of (phi_n/2) ,order doesnot cahnge but the running time has changed
        gcd=GCD_Euclidian(i,phi_n)      
        if (gcd==1):
            key.append(i)
    key.remove(p)
    key.remove(q)
    #print(key)
    print("The e can be any value among the list choose randomly : ",key)
    e=random.choice(key)
    print("The randomly chosen encryption key e is = :",colored(e,'red'))
    ct=pow(plain_text,e)
    cipher_text= ct % n
  
    print("The cipher text is :::", chr(cipher_text) )
   
    d1=Find_Decryption_key(e,phi_n)
   

# Apply and call Extended Euclidian Algo to find Find d (decryption key) which is a multiplicative inverse of e in RSA
    def Ext_Ecu_MUl_Inverse(phi_n,e):
        r, d = Extended_Euclidian(phi_n, e)
        if (r == 1): 
            d = int(d)
            print("decryption key d is: ", d) 
            return d
        else: 
            print("Multiplicative inverse for "+ e +" doesnot exists choose a different encrytion key ")
     
        pass
   
# call the decryption function 
    decryption(cipher_text,d1,n,plain_text)
    return cipher_text
   
# ..............Euclidian ALgo to find GCD ................#
def GCD_Euclidian(x,y):
    while(y):
        x,y= y,x%y
    return x

def Extended_Euclidian(a, b): 
    r1 = a 
    r2 = b 
    s1 = int(1) 
    s2 = int(0) 
    t1 = int(0) 
    t2 = int(1) 
    while r2 > 0: 
        q = r1//r2 
        r = r1-q * r2 
        r1 = r2 
        r2 = r 
        s = s1-q * s2 
        s1 = s2 
        s2 = s 
        t = t1-q * t2 
        t1 = t2 
        t2 = t           
    if t1 < 0: 
        t1 = t1 % a 
    return (r1, t1)

def Naive_Mul_Inverse(e,phi_n):
    e = e % phi_n
    for k in range(1,phi_n):
        if((e*k)%phi_n==1):
            return k
    return 1
    pass

def modInverse(e, Phi_n):    
    for x in range(1, Phi_n):
        if (((e%Phi_n) * (x%Phi_n)) % Phi_n == 1):
            return x
    return -1
    pass
def Find_Decryption_key(e,Phi_n):
    import itertools
    for k in itertools.count(start=1):
        if(pow(e,k)%Phi_n==1):
            if(k>Phi_n):
                return k
                break
    pass

   
def decryption(cipher_text,d,n,Plain_text):
    x=pow(cipher_text,d)    
    Retrived_plaintext= x % n  
    Retrived_plaintext= Retrived_plaintext+(Plain_text-Retrived_plaintext)
    Retrived_plaintext=chr(Retrived_plaintext) # covert to AScii
    print("Retrived plain text is::= "+colored(Retrived_plaintext,'green',attrs=['bold'])+"\n")
    pass

def Ascii_con(Plain_text,p,q):
        Ascii=[]
        cipher=[]
        for i in range (0,len(Plain_text)):
            Ascii.append(list(map(ord,Plain_text)))       
        for j in Ascii:
            for k in range(0,len(j)):
                print("The",k,"-th element is::",chr(j[k]))              
                encryption(p,q,j[k])
            break #inner loop Execute ones             
        pass

def main():
    n=len(sys.argv)
    print(colored("\nThe no of commandline arguments provided: ",'green'),n)
    compute_time = time.time()
    print("computation time is =","--- %s seconds ---" % compute_time)
    x=int(sys.argv[1])
    y=int(sys.argv[2])
    Plain_text= sys.argv[3]
    p=number.getPrime(x)
    print("\nThe first large prime No of ", x ,"bits is:=",p)
    q=number.getPrime(y)
    print("\nThe second large prime No of ", y ,"bits is:=",q)
    print("\n")
    #p=check_prime(x)
    #q=check_prime(y)
    p=check_prime(p)
    q=check_prime(q)
    n=p*q 
    print("\nThe value of n =",n)
    #Ascii_con(Plain_text,x,y)
    Ascii_con(Plain_text,p,q)
    
    
main()

