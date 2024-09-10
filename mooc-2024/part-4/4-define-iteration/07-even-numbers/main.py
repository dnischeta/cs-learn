def is_even(num):
    return num % 2 == 0

def even_numbers(l):
    return list(filter(is_even, l))

my_list = [1, 2, 3, 4, 5]
new_list = even_numbers(my_list)
print("original", my_list)
print("new", new_list)