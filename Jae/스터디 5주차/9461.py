t=int(input())
def p(n):
    rst=[1, 1, 1]
    if(n==1):
        return 1
    elif(n==2):
        return 1
    elif(n==3):
        return 1
    else:
        for i in range(3,n):
            rst.append(rst[i-2]+rst[i-3])
    return rst[-1]
for j in range(t):
    n=int(input())
    print(p(n))