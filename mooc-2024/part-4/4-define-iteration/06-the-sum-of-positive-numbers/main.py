def sum_of_positives(l):
    s = 0
    for el in l:
        if el > 0:
            s = s + el
    return s

my_list = [1, -2, 3, -4, 5]
result = sum_of_positives(my_list)
print("The result is", result)