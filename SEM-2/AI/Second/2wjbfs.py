from collections import deque

def bfs_water_jug_easy():
    # Take input from user
    max_a = int(input("Enter capacity of Jug 1 (A): "))
    max_b = int(input("Enter capacity of Jug 2 (B): "))
    goal = int(input("Enter target amount to be measured in Jug 1: "))

    queue = deque()
    visited = set()
    parent = {}
    action_taken = {}

    start = (0, 0)
    queue.append(start)
    visited.add(start)
    parent[start] = None
    action_taken[start] = "Start"

    while queue:
        a, b = queue.popleft()

        if a == goal or b == goal:
            path = []
            state = (a, b)
            while state is not None:
                path.append((state, action_taken[state]))
                state = parent[state]
            path.reverse()

            print("\n✅ Steps to reach the goal:")
            print(f"Jug 1 capacity: {max_a}L | Jug 2 capacity: {max_b}L | Goal: {goal}L\n")
            for (s, act) in path:
                print(f"{s} - {act}")
            return
        
        space_in_b = max_b-b
        if a>space_in_b:
            new_a1=a-space_in_b
            new_b1=max_b
        else:
            new_b1=b+a
            new_a1=0
    
        space_in_a=max_a-a
        if b>space_in_a:
            new_b2=b-space_in_a
            new_a2=max_a
        else:
            new_a2=a+b
            new_b2=0

        possible_moves = [
            ((max_a, b), "Jug 1 is filled"),
            ((a, max_b), "Jug 2 is filled"),
            ((0, b), "Jug 1 is emptied"),
            ((a, 0), "Jug 2 is emptied"),
            ((new_a1,new_b1), "Poured Jug 1 → Jug 2"),
            ((new_a2,new_b2), "Poured Jug 2 → Jug   1")
        ]

        for (p, action) in possible_moves:
            if p not in visited:
                visited.add(p)
                parent[p] = (a, b)
                action_taken[p] = action
                queue.append(p)

    print("❌ No solution found.")

# Run it
bfs_water_jug_easy()
