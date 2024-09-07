length = int(input("How many items: "))

if length < 0:
    raise Exception("Invalid length")

list = []

for i in range(length):
    list.append(int(input(f"Item {i+1}: ")))

print(list)
