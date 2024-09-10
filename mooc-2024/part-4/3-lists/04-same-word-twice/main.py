list = []

while True:
    w = input("Word: ")
    if w in list:
        break
    list.append(w)

print(f"You typed in {len(list)} different words")