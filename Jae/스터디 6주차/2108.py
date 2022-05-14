from collections import Counter
import sys
a=int(sys.stdin.readline())
b=[]
for _ in range(a):
    c=int(sys.stdin.readline())
    b.append(c)
print(round(sum(b)/a))
"""산술평균"""
new_b=sorted(b)
"""작은 수부터 정렬"""
for i in range(0,len(b)):
    if(i==(len(b)//2)):
        print(new_b[i])
        """중앙값"""
def numbers(nums):
    num1=Counter(nums).most_common()
    """nums의 요소를 세어 데이터의 개수가 많은 순으로 정렬된 배열을 반환"""
    """[(특정 요소,개수)...]"""
    if len(nums) > 1:
        if num1[0][1] == num1[1][1]:
            """여러 개의 최빈값이 있는 경우"""
            """ex) [(-2,2),(-1,2)...]"""
            new_num=num1[1][0]
            """최빈값 중 2번째로 작은 값"""
        else:
            new_num=num1[0][0]
    else:
        new_num=num1[0][0]
    return new_num
if(a==1):
    """입력된 수가 1개"""
    print(b[0])
    """최빈값"""
else:
    new_b=numbers(new_b)
    """numbers에 new_b를 넣는 이유는 작은 수부터 정렬이 되어 있어서 new_b를 사용해야만 2번째로 작은 수를 뽑을 수 있다"""
    print(new_b)
    """최빈값"""
print(max(b)-min(b))
"""범위"""