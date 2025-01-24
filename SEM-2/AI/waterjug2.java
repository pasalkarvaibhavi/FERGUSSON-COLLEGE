import java.util.*;

public class waterjug {

    static class State {
        int jug1, jug2;
        String path;

        State(int jug1, int jug2, String path) {
            this.jug1 = jug1;
            this.jug2 = jug2;
            this.path = path;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass())
                return false;
            State state = (State) obj;
            return jug1 == state.jug1 && jug2 == state.jug2;
        }

        @Override
        public int hashCode() {
            return Objects.hash(jug1, jug2);
        }
    }

    public static boolean canMeasureWater(int X, int Y, int Z) {
        if (Z > X + Y || Z % gcd(X, Y) != 0) return false;

        Queue<State> queue = new LinkedList<>();
        Map<State, State> parentMap = new HashMap<>(); // To track the BFS tree
        Set<State> visited = new HashSet<>();
        State initialState = new State(0, 0, "Start");
        queue.add(initialState);
        parentMap.put(initialState, null);

        System.out.println("BFS Tree:");

        while (!queue.isEmpty()) {
            State current = queue.poll();

            if (!visited.contains(current)) {
                visited.add(current);

                // Print the current state and its parent
                if (parentMap.get(current) != null) {
                    State parent = parentMap.get(current);
                    System.out.println("Parent: (" + parent.jug1 + ", " + parent.jug2 + ") -> Child: (" + current.jug1 + ", " + current.jug2 + ") via " + current.path);
                } else {
                    System.out.println("Root: (" + current.jug1 + ", " + current.jug2 + ")");
                }

                if (current.jug1 == Z || current.jug2 == Z || current.jug1 + current.jug2 == Z) {
                    System.out.println("\nSteps to achieve " + Z + " liters:");
                    printPath(current, parentMap);
                    return true;
                }

                // Generate all possible next states
                State[] nextStates = new State[] {
                        new State(X, current.jug2, "Fill Jug 1"),
                        new State(current.jug1, Y, "Fill Jug 2"),
                        new State(0, current.jug2, "Empty Jug 1"),
                        new State(current.jug1, 0, "Empty Jug 2"),
                        new State(current.jug1 - Math.min(current.jug1, Y - current.jug2),
                                current.jug2 + Math.min(current.jug1, Y - current.jug2),
                                "Pour Jug 1 to Jug 2"),
                        new State(current.jug1 + Math.min(current.jug2, X - current.jug1),
                                current.jug2 - Math.min(current.jug2, X - current.jug1),
                                "Pour Jug 2 to Jug 1")
                };

                for (State nextState : nextStates) {
                    if (!visited.contains(nextState) && !parentMap.containsKey(nextState)) {
                        queue.add(nextState);
                        parentMap.put(nextState, current);
                    }
                }
            }
        }

        return false;
    }

    private static void printPath(State target, Map<State, State> parentMap) {
        List<String> steps = new ArrayList<>();
        State current = target;

        while (current != null) {
            steps.add(0, "(" + current.jug1 + ", " + current.jug2 + ")" + (current.path.equals("Start") ? "" : " via " + current.path));
            current = parentMap.get(current);
        }

        for (String step : steps) {
            System.out.println(step);
        }
    }

    private static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter Jug 1 capacity:");
        int X = scanner.nextInt();
        System.out.println("Enter Jug 2 capacity:");
        int Y = scanner.nextInt();
        System.out.println("Enter target amount (Z):");
        int Z = scanner.nextInt();

        if (!canMeasureWater(X, Y, Z)) {
            System.out.println("\nIt is not possible to measure " + Z + " liters.");
        }

        scanner.close();
    }
}
