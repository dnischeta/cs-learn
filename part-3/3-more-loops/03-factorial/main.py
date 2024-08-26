while True:
    fac = 1
    num = int(input("Please type in a number: "))
    if num <= 0:
        print("Thanks and bye!")
        break
    numCopy = num
    while num > 1:
        fac = fac * num
        num = num - 1
    print(f"The factorial of the number {numCopy} is {fac}")