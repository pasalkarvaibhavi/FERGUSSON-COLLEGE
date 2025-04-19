def water_jug_game():
    x=int(input("Enter capcacity of jug 1:"))
    y=int(input("Enter capcacity of jug 2:"))
    goal=int(input("Enter Goal You have to reached:"))

    a,b=0,0

    while True:
        print(f"Jug 1:{a}L/{x}L and Jug 2:{b}L/{y}L")
        if a==goal or b==goal:
            print("Goal Reacher")
            break

        print("""
1.Fill jug 1
2.Fill jug 
3.Empty Jug 1 
4.Empty jug 2
5.Pour jug 1 to jug 2
6.Pour jug 2 to jug 1
7.Exit""")
        
        choice=int(input("Enter your choice:"))

        if choice==1:
            a=x
        elif choice==2:
            b=y
        elif choice==3:
            a=0
        elif choice==4:
            b=0
        elif choice==5:
            space=y-b
            if a>space:
                a=a-space
                b=y
            else:
                b=b+a
                a=0
        elif choice==6:
            space=x-a
            if b>space:
                b=b-space
                a=x
            else:
                a=a+b
                b=0
        elif choice==7:
            break
        else:
            print("Invalid Choice")
            break

water_jug_game()