graph=[
    [0,10,12,14],
    [12,0,10,12],
    [12,16,0,11],
    [14,12,16,0]
]

def tsp(start):
    n=len(graph)
    visited=[False]*n
    path=[start]
    total_cost=0
    current=start
    visited[start]=True

    for _ in range(n-1):
        next_city=-1
        min_cost=float('inf')
        for i in range(n):
            if not visited[i] and 0<graph[current][i]<min_cost:
                min_cost=graph[current][i]
                next_city=i
        visited[next_city]=True
        path.append(next_city)
        total_cost+=min_cost
        current=next_city
    total_cost+=graph[current][start]
    path.append(start)
    print("Path:", path)
    print("Total cost:", total_cost)
tsp(0)
