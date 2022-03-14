import sys
a=sys.stdin.readline().rstrip()
list_n=[]
for i in range(int(a)):
    list_n.append(list(map(int,input().split(' '))))
sorted_n=sorted(list_n,key=lambda x:(x[1],x[0]))
for j in sorted_n:
    print(j[0], j[1])