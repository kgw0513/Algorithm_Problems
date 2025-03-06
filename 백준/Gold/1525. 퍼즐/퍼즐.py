from collections import deque

# 문자열 자리 바꾸기
def swap(graph_swap, x, y):
    graph_swap = list(graph_swap)
    if y == 'L':
        graph_swap[x], graph_swap[x-1] = graph_swap[x-1], graph_swap[x]
    elif y == 'R':
        graph_swap[x], graph_swap[x+1] = graph_swap[x+1], graph_swap[x]
    elif y == 'U':
        graph_swap[x], graph_swap[x-3] = graph_swap[x-3], graph_swap[x]
    elif y == 'D':
        graph_swap[x], graph_swap[x+3] = graph_swap[x+3], graph_swap[x]
    return "".join(graph_swap)

# 문자열 자리 바꾸기 중앙 제어
def move(graph_move, count):
    x = graph_move.index('0')
    for direction, condition, offset in [('L', x % 3 != 0, -1),
                                         ('R', x % 3 != 2, 1),
                                         ('U', x > 2, -3),
                                         ('D', x < 6, 3)]:
        if condition:
            graph_want_move = swap(graph_move, x, direction)
            if graph_want_move not in visited:
                if graph_want_move == '123456780':  # 목표 상태 도달 즉시 종료
                    print(count + 1)
                    exit()
                queue.append((graph_want_move, count + 1))
                visited.add(graph_want_move)

# 입력 및 초기 상태 설정
graph = ''
visited = set()
queue = deque()

for _ in range(3):
    graph += ''.join(input().split())

visited.add(graph)
queue.append((graph, 0))

# 목표 상태가 초기 상태인 경우 즉시 종료
if graph == '123456780':
    print(0)
    exit()

# BFS 탐색
while queue:
    graph, count = queue.popleft()
    move(graph, count)

# 목표 상태에 도달할 수 없는 경우
print(-1)