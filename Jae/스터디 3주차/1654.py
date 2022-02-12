import sys
k,n=list(map(int,sys.stdin.readline().split(' ')))
rst=[]
for i in range(k):
    line=int(sys.stdin.readline())
    rst.append(line)
start=1
end=max(rst)
while start<=end:
    mid=(start+end)//2
    l=sum([x//mid for x in rst])
    """랜선을 mid의 길이로 몇개를 만들 수 있는 지 구함"""
    if l>=n:
        """랜선의 개수 l이 n보다 크거나 같은 경우"""
        start=mid+1
        """start값을 하나씩 늘려가며 범위를 좁힘"""
    else:
        end=mid-1
        """end값을 하나씩 줄여가면서 범위를 좁힘"""
print(end)
"""end는 결과값"""