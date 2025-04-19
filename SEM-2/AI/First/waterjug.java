import java.util.*;

public class WaterJug {

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
        Set<State> visited = new HashSet<>();
        queue.add(new State(0, 0, "Start: (0, 0)"));

        while (!queue.isEmpty()) {
            State current = queue.poll();

            if (current.jug1 == Z || current.jug2 == Z || current.jug1 + current.jug2 == Z) {
                System.out.println("Steps to achieve " + Z + " liters:");
                String[] steps = current.path.split(" -> ");
                for (String step : steps) {
                    System.out.println(step);
                }
                return true;
            }

            if (visited.contains(current)) continue;
            visited.add(current);

            queue.addAll(Arrays.asList(
                new State(X, current.jug2, current.path + " -> Fill Jug 1"),
                new State(current.jug1, Y, current.path + " -> Fill Jug 2"),
                new State(0, current.jug2, current.path + " -> Empty Jug 1"),
                new State(current.jug1, 0, current.path + " -> Empty Jug 2"),
                new State(current.jug1 - Math.min(current.jug1, Y - current.jug2),
                          current.jug2 + Math.min(current.jug1, Y - current.jug2),
                          current.path + " -> Pour Jug 1 to Jug 2"),
                new State(current.jug1 + Math.min(current.jug2, X - current.jug1),
                          current.jug2 - Math.min(current.jug2, X - current.jug1),
                          current.path + " -> Pour Jug 2 to Jug 1")
            ));
        }

        return false;
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
            System.out.println("It is not possible to measure " + Z + " liters.");
        }

        scanner.close();
    }
}


