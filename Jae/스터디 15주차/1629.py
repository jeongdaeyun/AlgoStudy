import sys
a,b,c=map(int,sys.stdin.readline().split(' '))
def sol(a,b,c):
    if b==1:
        return a%c
    else:
        x=sol(a,b//2,c)
        if b%2==0:
            return x*x%c
        else:
            return x*x*a%c
print(sol(a,b,c))