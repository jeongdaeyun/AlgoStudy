import sys

s = str(sys.stdin.readline().rstrip())
s = list(s)
rst = []
"""후위표기식"""
stack = []
"""연산자"""
for i in s:
    if i.isalpha():
        """i가 알파벳인 경우 rst에 push"""
        rst.append(i)
    if i == '(':
        """(는 연산자 stack에 push"""
        stack.append(i)
    elif i == ')':
        while True:
            if stack and stack[-1] != '(':
                """연산자 스택이 비거나 (를 만날때까지, stack에는 (와 연산자들만 있음"""
                """ex)A*(B+C)면 stack에는 [*,(,+]"""
                rst += stack.pop()
                """stack을 pop해서 rst에 넣어줌"""
            else:
                stack.pop()
                """(를 지워주기 위함"""
                break
            """어려움"""
            """연산자가 들어오면 자기보다 우선순위가 높거나 같은 것들을 빼고 자신을 stack에 넣는다"""
    elif i == '+' or i == '-':
        """i가 +인지 -인지 확인"""
        while stack and stack[-1] != '(':
            """+와 -는 연산자 우선순위 상관이 없다"""
            rst += stack.pop()
            """stack을 pop한 후 rst에 더함"""
        stack.append(i)
        """stack에 i추가"""
    elif i == '*' or i == '/':
        """i가 *인지 /인지 확인"""
        while stack and (stack[-1] == '*' or stack[-1] == '/'):
            """같은 우선순위에 있는 *와 /"""
            rst += stack.pop()
            """rst뒤에 stack pop한것을 넣음"""
        stack.append(i)
        """stack에 i추가"""
while stack:
    rst += stack.pop()
print("".join(rst))