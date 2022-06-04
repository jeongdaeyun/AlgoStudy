import sys
import collections

input = sys.stdin.readline

N = int(input())
length = collections.defaultdict(int)
arr = list(map(int, input().split()))

for k in range(N):
    length[k] = 1
    for i in range(k):
        if arr[i] < arr[k]:
            length[k] = max(length[k], length[i]+1)
    
maxvalue = 0
for i in range(N):
    if maxvalue < length[i]:
        maxvalue = length[i]

print(maxvalue)