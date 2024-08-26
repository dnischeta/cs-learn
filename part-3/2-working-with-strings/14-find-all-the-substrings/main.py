word = input("Please type in a word: ")
char = input("Please type in a character: ")

for idx in range(0, len(word) - 2, 1):
    if char == word[idx]:
        print(word[idx:idx+3])