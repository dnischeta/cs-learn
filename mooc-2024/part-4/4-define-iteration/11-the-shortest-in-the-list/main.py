def shortest(l):
    len_list = list(map(len, l))
    min_len = min(len_list)
    return l[len_list.index(min_len)]

my_list = ["first", "second", "fourth", "eleventh"]

my_list = ["first", "second", "fourth", "eleventh"]

result = shortest(my_list)
print(result)
my_list = ["adele", "mark", "dorothy", "tim", "hedy", "richard"]

result = shortest(my_list)
print(result)
