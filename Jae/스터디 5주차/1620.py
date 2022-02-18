import sys
n,m=map(int,sys.stdin.readline().split(' '))
dict={}
for i in range(1,n+1):
    pokemon=sys.stdin.readline().rstrip()
    dict[pokemon]=i
    dict[i]=pokemon
    """이름:번호, 번호:이름 딕셔너리 생성"""
for j in range(m):
    rst=sys.stdin.readline().rstrip()
    if rst.isalpha() is True:
        print(dict[rst])
    else:
        print(dict[int(rst)])