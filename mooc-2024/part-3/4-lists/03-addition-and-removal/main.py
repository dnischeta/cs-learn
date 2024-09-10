list = []

while True:
    print("The list now is", list)
    cmd = input("a(d)d, (r)emove or e(x)it: ")
    match cmd:
        case "d":
            list.append(len(list) + 1)
        case "r":
            if len(list) > 0:
                list.pop()
        case "x":
            print("Bye!")
            break
        case _:
            print("Unknown command", cmd)