def length(list):
    l = 0

    try:
        while True:
            list[l]
            l = l + 1
    except IndexError:
        return l

print(length([1,2,3,4]))