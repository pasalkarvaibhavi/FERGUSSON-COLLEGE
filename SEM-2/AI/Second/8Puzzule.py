goal = [1, 2, 3, 4, 5, 6, 7, 8, 0]

def h(state):
    return sum(abs(i//3 - (val-1)//3) + abs(i%3 - (val-1)%3) for i, val in enumerate(state) if val)

def get_neighbors(state):
    i = state.index(0)
    moves = []
    for d in [-3, 3, -1, 1]:
        ni = i + d
        if 0 <= ni < 9 and not (i % 3 == 0 and d == -1) and not (i % 3 == 2 and d == 1):
            new_state = state[:]
            new_state[i], new_state[ni] = new_state[ni], new_state[i]
            moves.append(new_state)
    return moves

def hill_climbing(start):
    state, step = start, 0
    while True:
        print(f"Step {step} (h={h(state)}): {state}")
        if h(state) == 0:
            print("Goal reached!")
            break
        neighbors = get_neighbors(state)
        next_state = min(neighbors, key=h)
        if h(next_state) >= h(state):
            print("Stuck in local minimum.")
            break
        state = next_state
        step += 1

start = [1, 2, 3, 4, 0, 6, 7, 5, 8]
hill_climbing(start)
