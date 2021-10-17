def linear_Search(list1, n, key):  
  
    
    for i in range(0, n):  
        if (list1[i] == key):  
            return i  
    return -1  
  
  
list1 = list(map(int,input("Enter your list: ").split(' ')))  
key = int(input("enter key to search: "))
  
n = len(list1)  
res = linear_Search(list1, n, key)  
if(res == -1):  
    print("Element not found")  
else:  
    print("Element found at index: ", res) 