num1, num2 = map(int,input().split(' '))

def karatsuba(x, y):
    strx, stry = str(x), str(y)
    lenx, leny = len(strx), len(stry)

    if lenx==1 or leny==1:
        return x*y
    
    m = min(lenx, leny) // 2
    a, b = int(strx[-m:]), int(strx[:-m])
    c, d = int(stry[-m:]), int(stry[:-m])

    z0 = karatsuba(a, c)
    z1 = karatsuba(a+b, c+d)
    z2 = karatsuba(b, d)

    return (z2 * 10**(m*2) + (z1 - z2 - z0) * 10**m + z0)

print(karatsuba(num1, num2))