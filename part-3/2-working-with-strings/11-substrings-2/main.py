word = input("Please type in a string: ")

for i in range(1, len(word) + 1, 1):
    print(word[len(word) - i:len(word)])
    