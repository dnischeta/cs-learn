def list_sum(l1: list, l2: list):
    res = [None] * len(l1)
    for idx in range(len(l1)):
        res[idx] = l1[idx] + l2[idx]
    return res

a = [1, 2, 3]
b = [7, 8, 9]
print(list_sum(a, b)) # [8, 10, 12]