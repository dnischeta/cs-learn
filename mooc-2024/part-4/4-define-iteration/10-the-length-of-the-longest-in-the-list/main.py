def length_of_longest(l):
    return max(map(len, l))

my_list = ["first", "second", "fourth", "eleventh"]

result = length_of_longest(my_list)
print(result)
my_list = ["adele", "mark", "dorothy", "tim", "hedy", "richard"]

result = length_of_longest(my_list)
print(result)