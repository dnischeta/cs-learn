n = int(input("Please type in a number: "))

for i in range(1, n + 1):
    if i % 2 == 0:
        print(i - 1)
    elif i < n:
        print(i + 1)
    else:
        print(i)