limit = int(input("Please type in a positive integer: "))

for n in range(-limit, limit + 1):
    if n == 0:
        continue
    print(n)