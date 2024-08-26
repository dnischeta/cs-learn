hor = '******************************'

word = input('Word: ')
padL = (30 - 2 - len(word)) // 2
padR = 30 - 2 - len(word) - padL
print(hor)
print('*' + padL * ' ' + word + padR * ' ' + '*')
print(hor)