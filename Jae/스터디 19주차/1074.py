import sys
N,r,c=map(int,sys.stdin.readline().split(' '))
cnt=0
while N!=0:
    N-=1
    if r<2**N and c<2**N:
        """1사분면"""
        cnt+=(2**N)*(2**N)*0
    elif r<2**N and c>=2**N:
        """2사분면"""
        cnt+=(2**N)*(2**N)*1
        """1사분면은 다 거쳤으므로 1사분면의 크기만큼 더함"""
        c-=2**N
        """y좌표 값을 한 개의 사분면만큼 빼는 이유는 쪼개면서 세로의 칸이 줄어들기 때문"""
    elif r>=2**N and c<2**N:
        """3사분면"""
        cnt+=(2**N)*(2**N)*2
        r-=2**N
    else:
        """4사분면"""
        cnt+=(2**N)*(2**N)*3
        r-=2**N
        c-=2**N
print(cnt)