#Create a Dictionary - student_grades = {'Ram': 85, 'Sham': 92, 'Ojas": 88, 'Anay': 79}
#Write a Python function to find the student with the highest grade.
#Add a new student Eve' with a grade of 95.
#Print all the student names and their grades in alphabetical order.

student_grades={ 'Ram':89,'Nitin':78,'Anay':93,'Zjas':99}

print(student_grades)

highest_grade_student =max(student_grades,key=student_grades.get)
print(f"The student with highest grade is {highest_grade_student} with a grade of student {student_grades[highest_grade_student]}")

student_grades["Neha"]=55
print(student_grades)

print(sorted(student_grades.items()))


