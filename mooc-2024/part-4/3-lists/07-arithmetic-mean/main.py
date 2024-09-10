def mean(arr):
    sum = 0
    for el in arr:
        sum = sum + el

    return sum / len(arr)

list = [1,2,3,4,5]

print("Mean is: ", mean(list))