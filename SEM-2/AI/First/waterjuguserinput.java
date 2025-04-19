import java.util.*;

public class waterjuguserinput {

    private static void displayCurrentState(int jug1, int jug2) {
        System.out.println("Jug 1: " + jug1 + " liters, Jug 2: " + jug2 + " liters\n");
    }


    public static void solveWaterJugProblem(int capacity1, int capacity2, int target, int initialJug1, int initialJug2) {
        int jug1 = initialJug1;
        int jug2 = initialJug2;

        Scanner scanner = new Scanner(System.in);

        System.out.println("\nStarting with the following state:");
        displayCurrentState(jug1, jug2);

        if (jug1 == target || jug2 == target) {
            System.out.println("Target achieved right away!");
            return;
        }


        while (true) {
            System.out.println("\nCurrent state:");
            displayCurrentState(jug1, jug2);


            System.out.println("1. Fill Jug 1 complete.");
            System.out.println("2. Fill Jug 2 complete.");
            System.out.println("3. Empty Jug 1");
            System.out.println("4. Empty Jug 2");
            System.out.println("5. Move water from Jug 1 into Jug 2");
            System.out.println("6. Move water from Jug 2 into Jug 1");
            System.out.println("7. Exit the program");
            System.out.println("Choose Action:");

            int n= scanner.nextInt();


            switch(n) {
                case 1:
                    jug1 = capacity1;
                    break;
                case 2:
                    jug2 = capacity2;
                    break;
                case 3:
                    jug1 = 0;
                    break;
                case 4:
                    jug2 = 0;
                    break;
                case 5:
                    int pourToJug2 = Math.min(jug1, capacity2 - jug2);
                    jug1 -= pourToJug2;
                    jug2 += pourToJug2;
                    break;
                case 6:
                    int pourToJug1 = Math.min(jug2, capacity1 - jug1);
                    jug2 -= pourToJug1;
                    jug1 += pourToJug1;
                    break;
                case 7:
                    System.out.println("Exit");
                    return;
                default:
                    System.out.println("Invalid input. Please choose a correct option.");
                    continue;
            }

            if (jug1 == target || jug2 == target) {
                System.out.println("\nYou reached the Target !!!");
                displayCurrentState(jug1, jug2);
                return;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("\n***Water Jug Problem***\n");

        System.out.print("Enter capacity of JUG 1: ");
        int capacity1 = scanner.nextInt();

        System.out.print("Enter capacity of JUG 2: ");
        int capacity2 = scanner.nextInt();

        System.out.print("Enter target amount: ");
        int target = scanner.nextInt();

        System.out.print("\nEnter the initial amount of water in 1st jug: ");
        int initialJug1 = scanner.nextInt();

        System.out.print("Enter the initial amount of water in 2nd jug: ");
        int initialJug2 = scanner.nextInt();

        solveWaterJugProblem(capacity1, capacity2, target, initialJug1, initialJug2);

        scanner.close();
    }
}

/*
* ***Water Jug Problem***

Enter capacity of JUG 1: 5
Enter capacity of JUG 2: 3
Enter target amount: 4

Enter the initial amount of water in 1st jug: 0
Enter the initial amount of water in 2nd jug: 0

Starting with the following state:
Jug 1: 0 liters, Jug 2: 0 liters


Current state:
Jug 1: 0 liters, Jug 2: 0 liters

1. Fill Jug 1 complete.
2. Fill Jug 2 complete.
3. Empty Jug 1
4. Empty Jug 2
5. Move water from Jug 1 into Jug 2
6. Move water from Jug 2 into Jug 1
7. Exit the program
Choose Action:
1

Current state:
Jug 1: 5 liters, Jug 2: 0 liters

1. Fill Jug 1 complete.
2. Fill Jug 2 complete.
3. Empty Jug 1
4. Empty Jug 2
5. Move water from Jug 1 into Jug 2
6. Move water from Jug 2 into Jug 1
7. Exit the program
Choose Action:
5

Current state:
Jug 1: 2 liters, Jug 2: 3 liters

1. Fill Jug 1 complete.
2. Fill Jug 2 complete.
3. Empty Jug 1
4. Empty Jug 2
5. Move water from Jug 1 into Jug 2
6. Move water from Jug 2 into Jug 1
7. Exit the program
Choose Action:
4

Current state:
Jug 1: 2 liters, Jug 2: 0 liters

1. Fill Jug 1 complete.
2. Fill Jug 2 complete.
3. Empty Jug 1
4. Empty Jug 2
5. Move water from Jug 1 into Jug 2
6. Move water from Jug 2 into Jug 1
7. Exit the program
Choose Action:
5

Current state:
Jug 1: 0 liters, Jug 2: 2 liters

1. Fill Jug 1 complete.
2. Fill Jug 2 complete.
3. Empty Jug 1
4. Empty Jug 2
5. Move water from Jug 1 into Jug 2
6. Move water from Jug 2 into Jug 1
7. Exit the program
Choose Action:
1

Current state:
Jug 1: 5 liters, Jug 2: 2 liters

1. Fill Jug 1 complete.
2. Fill Jug 2 complete.
3. Empty Jug 1
4. Empty Jug 2
5. Move water from Jug 1 into Jug 2
6. Move water from Jug 2 into Jug 1
7. Exit the program
Choose Action:
5

You reached the Target !!!
Jug 1: 4 liters, Jug 2: 3 liters


Process finished with exit code 0*/