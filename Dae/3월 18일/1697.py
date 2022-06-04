import sys
input = sys.stdin.readline

a, b = map(int, input().split(' '))

def value(b, a):
    if b <= a:
        return a-b
    elif b == 1:
        return 1
    elif b%2 == 1:
        return 1 + min(value(b-1,a),value(b+1,a))
    else:
        return min(b-a, 1 + value(b//2,a))


print(value(b,a))