import sys
n=int(sys.stdin.readline())
for i in range(n):
    M,N,x,y=map(int,sys.stdin.readline().split(' '))
    max_xy=M*N
    f=1
    while x<=max_xy:
        if x%N==y%N:
            print(x)
            f=0
            break
        x+=M
    if f:
        print(-1)