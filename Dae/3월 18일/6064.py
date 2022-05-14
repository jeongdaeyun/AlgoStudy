import sys
input = sys.stdin.readline
T = int(input())
for i in range(T):
    M, N, x, y = map(int,input().split(' '))
    p = M*N
    count = -1
    if x <= M and y <= N:
        for j in range(x,p+1,M):
            if (j-1)%N + 1 == y:
                count = j
                break
            
    print(count)