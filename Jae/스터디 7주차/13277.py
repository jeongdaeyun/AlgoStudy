a,b=map(int,input().split(' '))
print(a*b)
"""import sys
def karatsuba(a,b):
    a=str(a)
    b=str(b)
    lena=len(a)
    lenb=len(b)
    if lena==1 or lenb==1:
        return int(a)*int(b)
    else:
        minlen=min(lena,lenb)//2
        x=int(a[:-minlen])
        y=int(a[-minlen:])
        w=int(b[:-minlen])
        z=int(b[-minlen:])
        xw=karatsuba(x,w)
        yz=karatsuba(y,z)
        xwyz=karatsuba(x+y,w+z)-(x*w)-(y*z)
        return 10**(2*minlen)*xw+10**(minlen)*xwyz+yz
a,b=map(int,sys.stdin.readline().split(' '))
sys.stdout.write(str(karatsuba(a,b)))"""