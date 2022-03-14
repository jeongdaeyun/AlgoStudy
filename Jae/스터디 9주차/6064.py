import sys
n=int(sys.stdin.readline())
for i in range(n):
    M,N,x,y=map(int,sys.stdin.readline().split(' '))
    max_xy=M*N
    while x<max_xy:
        if (x-1)%N+1==y:
            break
        x+=M
    if x<max_xy:
        print(x)
    else:
        print(-1)