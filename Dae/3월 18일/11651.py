import sys
input = sys.stdin.readline
N = int(input())
arr = []

for i in range(N):
    [a, b] = map(int,input().split())
    arr.append([b, a])

array = sorted(arr)

for i in range(N):
    print(array[i][1],array[i][0])