from audioop import reverse
import string
import sys
input = sys.stdin.readline
a=[]
N = int(input())
for i in str(N):
    a.append(i)
a.sort(reverse=True)

for i in a:
    print(i,end='')