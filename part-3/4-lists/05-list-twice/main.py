list = []

while True:
    list.append(int(input("New item: ")))
    if list[-1] == 0:
        print('Bye!')
        break
    print('The list now: ', list)
    print('The list in order: ', sorted(list))