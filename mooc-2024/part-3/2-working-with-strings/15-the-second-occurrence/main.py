word = input("Please type in a word: ")
substr = input("Please type in a substring: ")

firstMeet = word.find(substr)
secondMeet = word[firstMeet+len(substr):].find(substr)

if secondMeet > -1:
    print(f'The second occurrence of the substring is at index {firstMeet+secondMeet+len(substr)}.')
else:
    print('The substring does not occur twice in the string.')
