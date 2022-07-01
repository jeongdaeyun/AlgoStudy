import heapq
import sys
a=int(sys.stdin.readline())
def sol():
    b=int(sys.stdin.readline())
    minHeap, maxHeap = [],  []
    minPop, maxPop = [],  []
    for _ in range(b):
        cmd = sys.stdin.readline().split()
        if cmd[0] == 'I':
            heapq.heappush(minHeap, int(cmd[1]))
            heapq.heappush(maxHeap, -int(cmd[1]))
        elif cmd[0] == 'D':
            """최댓값"""
            if cmd[1] == '1':
                "비어있는 경우 continue"
                if not maxHeap:
                    continue
                """minheap에서 삭제된 것은 maxheap에서도 삭제되어야 하므로 건너뛰기 작업"""
                while (maxHeap and minPop) and (-maxHeap[0] == -minPop[0]):
                    heapq.heappop(maxHeap)
                    heapq.heappop(minPop)
                """건너 뛰면서 보니까 비어있다면 무시"""
                if not maxHeap:
                    continue
                x = heapq.heappop(maxHeap)
                heapq.heappush(maxPop, -x)
            elif cmd[1] == '-1':
                if not minHeap:
                    continue
                while (minHeap and maxPop) and (minHeap[0] == maxPop[0]):
                    heapq.heappop(minHeap)
                    heapq.heappop(maxPop)
                if not minHeap:
                    continue
                x = heapq.heappop(minHeap)
                heapq.heappush(minPop, -x)
    """minheap, maxheap에 남아있는 최댓값, 최솟값 출력"""
    maxvalue, minvalue = 0, 0
    while (maxHeap and minPop) and (maxHeap[0] == minPop[0]):
        heapq.heappop(maxHeap)
        heapq.heappop(minPop)
    if not maxHeap:
        """maxheap 비어있다면"""
        print("EMPTY")
        return
    maxvalue=-maxHeap[0]
    while (minHeap and maxPop) and (minHeap[0] == maxPop[0]):
        heapq.heappop(minHeap)
        heapq.heappop(maxPop)
    minvalue = minHeap[0]
    print(maxvalue, minvalue)
    return
for _ in range(a):
    sol()