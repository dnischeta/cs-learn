num = int(input("Please type in a number: "))

for left in range(1, num+1):
    for right in range(1, num+1):
        print(f"{left} x {right} = {left*right}")