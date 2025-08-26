debug=0


def ultimoChoque(a, b):
    n = len(a)
    m = len(b)
    
    # scan from rightmost digit
    i1=n-1
    i2=m-1
    count=0
    ans=0
    while (i1>=0 and i2>=0):
        count=count+1
        if int(a[i1]) + int(b[i2]) >= 10:
            ans=count
        i1-=1
        i2-=1
    
    
    
    i1=n-1-count
    i2=m-1-count
    while (i1>=0 and i2>=0 and int(a[i1])+int(b[i2])>=9):
        i1-=1
        i2-=1
        count+=1

    

    mod = 10**count
    if debug:
        print('quiere los '+str(count)+'digitos')
    a_tail = int(a[-count:])
    if debug:
        print('eso en a es '+str(a_tail))
    
    b_tail = int(b[-count:])
    if debug:
        print('eso en b es '+str(b_tail))
    return min(mod - a_tail, mod - b_tail)



a=input()
b=input()

print(ultimoChoque(a, b))