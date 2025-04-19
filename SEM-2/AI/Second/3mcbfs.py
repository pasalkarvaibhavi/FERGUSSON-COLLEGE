from collections import deque

def is_valid(m_left, c_left, m_right, c_right):
    if m_left < 0 or c_left < 0 or m_right < 0 or c_right < 0:
        return False
    if m_left > 0 and m_left < c_left:
        return False
    if m_right > 0 and m_right < c_right:
        return False
    return True

def bfs_missionaries_and_cannibals():
    start = (3, 3, 'left')  # (missionaries_left, cannibals_left, boat_position)
    goal = (0, 0, 'right')

    queue = deque([start])
    visited = set([start])
    parent = {start: None}
    action_taken = {start: "Start"}

    # All valid moves: (missionaries, cannibals)
    

    while queue:
        m_left, c_left, boat = queue.popleft()
        m_right = 3 - m_left
        c_right = 3 - c_left

        if (m_left, c_left, boat) == goal:
            path = []
            state = (m_left, c_left, boat)
            while state:
                path.append((state, action_taken[state]))
                state = parent[state]
            path.reverse()

            print("✅ Steps to solve Missionaries and Cannibals:\n")
            for (s, a) in path:
                print(f"{s} -> {a}")
            return

        moves = [(2, 0), (0, 2), (1, 1), (1, 0), (0, 1)]
        
        for m, c in moves:
            if boat == 'left':
                new_state = (m_left - m, c_left - c, 'right')
                new_m_left, new_c_left = new_state[0], new_state[1]
                new_m_right, new_c_right = 3 - new_m_left, 3 - new_c_left
            else:
                new_state = (m_left + m, c_left + c, 'left')
                new_m_left, new_c_left = new_state[0], new_state[1]
                new_m_right, new_c_right = 3 - new_m_left, 3 - new_c_left

            if is_valid(new_m_left, new_c_left, new_m_right, new_c_right) and new_state not in visited:
                visited.add(new_state)
                parent[new_state] = (m_left, c_left, boat)
                action_taken[new_state] = f"Move {m}M, {c}C to the {new_state[2].upper()} bank"
                queue.append(new_state)

    print("❌ No solution found.")

# Run the automatic BFS solver
bfs_missionaries_and_cannibals()
 