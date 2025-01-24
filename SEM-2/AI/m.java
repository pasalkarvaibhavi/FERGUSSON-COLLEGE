import java.util.*;

class m {
    static class State {
        int leftMissionaries, leftCannibals, rightMissionaries, rightCannibals;
        boolean boat; // true = left side, false = right side
        State parent; // To track the path

        public State(int leftM, int leftC, int rightM, int rightC, boolean boat, State parent) {
            this.leftMissionaries = leftM;
            this.leftCannibals = leftC;
            this.rightMissionaries = rightM;
            this.rightCannibals = rightC;
            this.boat = boat;
            this.parent = parent;
        }

        // Check if the state is valid
        public boolean isValid() {
            if (leftMissionaries < 0 || leftCannibals < 0 || rightMissionaries < 0 || rightCannibals < 0) {
                return false; // Negative values are invalid
            }
            if (leftMissionaries > 0 && leftMissionaries < leftCannibals) {
                return false; // Missionaries eaten on the left
            }
            if (rightMissionaries > 0 && rightMissionaries < rightCannibals) {
                return false; // Missionaries eaten on the right
            }
            return true;
        }

        // Check if the state is the goal
        public boolean isGoal() {
            return leftMissionaries == 0 && leftCannibals == 0 && rightMissionaries == 3 && rightCannibals == 3;
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
                    boat == state.boat;
        }

        @Override
        public int hashCode() {
            return Objects.hash(leftMissionaries, leftCannibals, rightMissionaries, rightCannibals, boat);
        }
    }

    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        Queue<State> queue = new LinkedList<>();
        Set<State> visited = new HashSet<>();
        State initialState = new State(3, 3, 0, 0, true, null);

        queue.add(initialState);
        visited.add(initialState);

        while (!queue.isEmpty()) {
            State current = queue.poll();

            if (current.isGoal()) {
                printSolution(current);
                return;
            }

            System.out.println("Current State: ");
            System.out.println("Left Side: Missionaries = " + current.leftMissionaries + ", Cannibals = " + current.leftCannibals);
            System.out.println("Right Side: Missionaries = " + current.rightMissionaries + ", Cannibals = " + current.rightCannibals);
            System.out.println("Boat is on the " + (current.boat ? "left" : "right") + " side.\n");

            while (true) {
                System.out.println("Enter the number of Missionaries and Cannibals to move (Boat Capacity: 1-2): ");
                System.out.print("Number of Missionaries: ");
                int missionaries = scanner.nextInt();
                System.out.print("Number of Cannibals: ");
                int cannibals = scanner.nextInt();

                if (missionaries + cannibals >= 1 && missionaries + cannibals <= 2) {
                    State nextState = null;

                    if (current.boat) { // Boat on the left side
                        nextState = new State(
                                current.leftMissionaries - missionaries, current.leftCannibals - cannibals,
                                current.rightMissionaries + missionaries, current.rightCannibals + cannibals,
                                false, current
                        );
                    } else { // Boat on the right side
                        nextState = new State(
                                current.leftMissionaries + missionaries, current.leftCannibals + cannibals,
                                current.rightMissionaries - missionaries, current.rightCannibals - cannibals,
                                true, current
                        );
                    }

                    if (nextState.isValid()) {
                        queue.add(nextState);
                        visited.add(nextState);
                        break; // Proceed to the next state
                    } else {
                        System.out.println("Invalid move! This would result in missionaries being eaten. Try again.\n");
                    }
                } else {
                    System.out.println("Invalid input! Boat capacity is 1-2 people. Try again.\n");
                }
            }
        }

        System.out.println("No solution found.");
    }

    // Print the solution path
    private static void printSolution(State state) {
        List<State> path = new ArrayList<>();
        while (state != null) {
            path.add(state);
            state = state.parent;
        }
        Collections.reverse(path);

        for (State s : path) {
            System.out.println("Left: M=" + s.leftMissionaries + ", C=" + s.leftCannibals +
                    " | Right: M=" + s.rightMissionaries + ", C=" + s.rightCannibals +
                    " | Boat is on " + (s.boat ? "Left" : "Right") + " side");
        }
        System.out.println("\nGoal reached! All missionaries and cannibals are on the right side.");
    }

    public static void main(String[] args) {
        System.out.println("Missionaries and Cannibals Problem");
        solve();
    }
}
