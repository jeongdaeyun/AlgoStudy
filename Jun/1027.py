#1027
n = int(input())
buildings = list(map(int,input().split()))
maxcount = 0

for i in range(n):
    count = 0
    min_val = 1234567890
    for j in range(i-1,-1,-1):
        left = (buildings[i]-buildings[j])/(i-j)
        if(min_val > left):
            count += 1
            min_val = left
    max_val = -1234567890
    for j in range(i+1,n):
        right = (buildings[j]-buildings[i]) / (j-i)
        if(max_val < right):
            count += 1
            max_val = right
    if(count > maxcount):
        # print("max:" + str(i))
        maxcount = count
print(maxcount)