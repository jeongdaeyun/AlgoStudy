n=int(input())+1
l_k=list(map(int,str(n)))
rst=[]
for i in range(100):
    """적당히 100번 돌려도 괜찮다"""
    for i in range(len(l_k)//2):
        """2개씩 짝지어 확인하므로 길이의 절반만 본다"""
        if(l_k[i]<l_k[len(l_k)-1-i]):
            """앞에꺼보다 뒤에꺼가 큰 경우"""
            l_k[len(l_k)-2-i]+=1
            """뒤에꺼보다 1개 전의 수에 1을 더해줌"""
        l_k[len(l_k)-1-i]=l_k[i]
        """print(l_k)"""
        """9299939"""
        """그리고 앞에 것이 작으므로 뒤에 수를 앞에 수로 바꿔줌"""
        for j in reversed(range(len(l_k)-1)):
            if(l_k[j]>=10):
                """숫자가 10과 같거나 크게 된다면 안된다"""
                l_k[j],l_k[j-1] = l_k[j]%10,l_k[j-1]+l_k[j]//10
                """10과 같거나 큰 l_k[j]와 l_k[j-1]을 고쳐주는데 l_k[j]는 10보다 크거나 같기 때문에 10을 나눈 나머지로 바꿔주고 l_k[j-1]은 l_k[j-1]+l_k[j]//10으로 바꿔준다"""
for _ in l_k:
    print(_,end='')