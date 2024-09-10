list = [1,2,3,4,5]

print(list)

while True:
    idx = int(input("Index [0, 4]: "))

    if idx < 0 or idx >= len(list):
        break

    list[idx] = int(input("New value: "))
    print(list)