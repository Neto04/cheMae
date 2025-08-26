debug=0

# return si chocan en 10^i return i+1




def ultimoChoque(a, b):
    ans=0
    a2=a
    b2=b
    count=0
    while (a2>0 and b2>0):
        if(debug):
            print('proceso '+str(a2%10)+' vs '+str(b2%10))
        count=count+1
        if (a2%10 + b2%10 >=10):
            ans=count
        a2//=10
        b2//=10
        
    return ans

def aumentar(a, b, k):
    a2=a
    b2=b
    counter=k
    while(counter>0):
        a2//=10
        b2//=10
        counter-=1
        
    supCounter=k
    while (a2>0 and b2>0 and a2%10 + b2%10 == 9):
        a2//=10
        b2//=10
        supCounter+=1
        
    return supCounter 

        
    







a=int(input())
b=int(input())


x=ultimoChoque(a, b)
if (debug):
    print('el ultimo choque de '+str(a)+', y '+str(b)+' es '+ str(x))
if (x== 0):
    print(0)
    
else:
    k=aumentar(a, b, x)
    if(debug):
        print('el ultimo lugar que de fijo me como es '+str(k))
    pot=10**k
    
    aAns=pot-a%pot
    
    bAns=pot-b%pot
    
    ans=min(aAns, bAns)
    print(ans)
    


