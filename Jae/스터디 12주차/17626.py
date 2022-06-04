"""1인 경우: 25와 같이 n의 제곱근이 정수인 경우"""
"""2인 경우: 어떤 정수 i에 대해서 n-i^2의 제곱근이 정수인 경우"""
"""3인 경우: 어떤 정수 i와 j에 대해서 n-i^2-j^2의 제곱근이 정수인 경우"""
import sys
n=int(sys.stdin.readline())
def sol(n):
    if int(n**0.5)==(n**0.5):
        return 1
    for i in range(1,int(n**0.5)+1):
        """예를 들어 26인 경우 1에서 부터 6까지 확인해야 하기 때문"""
        if int((n-i**2)**0.5)==((n-i**2)**0.5):
            return 2
    for i in range(1,int(n**0.5)+1):
        for j in range(1,int((n-i**2)**0.5)+1):
            if int((n-i**2-j**2)**0.5)==((n-i**2-j**2)**0.5):
                return 3
    return 4
print(sol(n))