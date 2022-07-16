"""lis 유형의 문제"""
"""ex)1,2,3,4,5 -> lis=5이므로 답이 0 (전체길이 - lis)"""
"""ex)5,4,3,2,1 -> lis=1이므로 답이 4 """
"""예제) 3,7,5,2,6,1,4 -> 3 5 6 즉, lis=3이므로 7 - 3 = 4"""
import sys
a=int(sys.stdin.readline())
dp=[1 for _ in range(a)]
rst=[]
for _ in range(a):
    su=int(sys.stdin.readline())
    rst.append(su)
for i in range(len(rst)):
    for j in range(0,i):
        if(rst[i]>rst[j]):
            dp[i]=max(dp[i],dp[j]+1)
print(a-max(dp))