#Write a lambda function that:
#Takes two arguments and returns Power of 1st arg by 2nd.
#Use this lambda function in the map() function to add corresponding elements of two lists:
#list1 [1, 2, 3, 4] list2 [5, 6, 7, 8]

list1=[1,2,3,4]
list2=[5,6,7,8]

power=lambda x,y:x**y
ans=list(map(power,list1,list2))
print(ans)

