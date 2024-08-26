line = input("Please type in a sentence: ")
inside_word = False

for letter in line:
    if letter == ' ':
        inside_word = False
    else:
        if not(inside_word):
            print(letter)
        inside_word = True