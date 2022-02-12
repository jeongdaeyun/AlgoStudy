import sys
num=int(sys.stdin.readline())
num_list=list(map(int,sys.stdin.readline().split(' ')))
sorted_num_list=sorted(set(num_list),reverse=False)
"""작은 수가 먼저 나오도록 정렬"""
dic={i:v for v,i in enumerate(sorted_num_list)}
"""enumerate로 sorted_num_list의 인덱스와 원소를 동시에 접근하면서 루프를 돌림"""
"""ex)2 4 -10 4 -9"""
"""ex)-10:0 -9:1 2:2 4:3"""
for i in num_list:
    print(dic[i], end=" ")