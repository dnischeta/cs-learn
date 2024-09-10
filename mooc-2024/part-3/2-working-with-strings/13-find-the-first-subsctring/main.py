word = input("Please type in a word: ")
char = input("Please type in a character: ")

idx = word[0:-2].find(char)

if idx > -1:
    print(word[idx:idx+3])