import java.util.*;

class State {
    int leftMissionaries, leftCannibals, rightMissionaries, rightCannibals, boatPosition;
    State parent; 
    State(int leftMissionaries, int leftCannibals, int rightMissionaries, int rightCannibals, int boatPosition, State parent) {
        this.leftMissionaries = leftMissionaries;
        this.leftCannibals = leftCannibals;
        this.rightMissionaries = rightMissionaries;
        this.rightCannibals = rightCannibals;
        this.boatPosition = boatPosition; 
        this.parent = parent;
    }

    boolean isValid() {
        return (leftMissionaries >= 0 && leftCannibals >= 0 &&
                rightMissionaries >= 0 && rightCannibals >= 0 &&
                (leftMissionaries == 0 || leftMissionaries >= leftCannibals) &&
                (rightMissionaries == 0 || rightMissionaries >= rightCannibals));
    }

    boolean isGoal() {
        return (leftMissionaries == 0 && leftCannibals == 0 &&
                rightMissionaries == 3 && rightCannibals == 3);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        State state = (State) obj;
        return leftMissionaries == state.leftMissionaries &&
                leftCannibals == state.leftCannibals &&
                rightMissionaries == state.rightMissionaries &&
                rightCannibals == state.rightCannibals &&
                boatPosition == state.boatPosition;
    }

    @Override
    public int hashCode() {
        return Objects.hash(leftMissionaries, leftCannibals, rightMissionaries, rightCannibals, boatPosition);
    }
}

public class m1 {
    private static final int[][] MOVES = {
            {1, 0}, // 1 Missionary
            {0, 1}, // 1 Cannibal
            {1, 1}, // 1 Missionary and 1 Cannibal
            {2, 0}, // 2 Missionaries
            {0, 2}  // 2 Cannibals
    };

    public static void main(String[] args) {
        State initialState = new State(3, 3, 0, 0, 0, null); // All on the left side
        bfs(initialState);
    }

    private static void bfs(State initialState) {
        Queue<State> queue = new LinkedList<>();
        Set<State> visited = new HashSet<>();

        queue.add(initialState);
        visited.add(initialState);

        while (!queue.isEmpty()) {
            State currentState = queue.poll();

            if (currentState.isGoal()) {
                printSolution(currentState);
                return;
            }

            for (int[] move : MOVES) {
                State nextState = getNextState(currentState, move);
                if (nextState != null && nextState.isValid() && !visited.contains(nextState)) {
                    queue.add(nextState);
                    visited.add(nextState);
                }
            }
        }

        System.out.println("No solution found.");
    }

    private static State getNextState(State currentState, int[] move) {
        int missionaries = move[0], cannibals = move[1];

        if (currentState.boatPosition == 0) { // Boat is on the left side
            return new State(
                    currentState.leftMissionaries - missionaries,
                    currentState.leftCannibals - cannibals,
                    currentState.rightMissionaries + missionaries,
                    currentState.rightCannibals + cannibals,
                    1, // Move boat to the right
                    currentState
            );
        } else { // Boat is on the right side
            return new State(
                    currentState.leftMissionaries + missionaries,
                    currentState.leftCannibals + cannibals,
                    currentState.rightMissionaries - missionaries,
                    currentState.rightCannibals - cannibals,
                    0, // Move boat to the left
                    currentState
            );
        }
    }

    private static void printSolution(State goalState) {
        List<State> path = new ArrayList<>();
        State current = goalState;

        while (current != null) {
            path.add(current);
            current = current.parent;
        }

        Collections.reverse(path);

        for (State state : path) {
            System.out.println("LM: " + state.leftMissionaries + ", LC: " + state.leftCannibals +
                    ", RM: " + state.rightMissionaries + ", RC: " + state.rightCannibals +
                    ", Boat: " + (state.boatPosition == 0 ? "Left" : "Right"));
        }

        System.out.println("Solution Found!");
    }
}
