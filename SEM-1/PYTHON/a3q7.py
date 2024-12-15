#Write a function that takes two lists and uses map() to return a list of the sums of corresponding elements.
def two_list(list1,list2):
    sum=map(lambda x,y:x+y ,list1,list2)
    return list(sum)

list1=[1,2,3]
list2=[2,4,1]
print(two_list(list1,list2))

