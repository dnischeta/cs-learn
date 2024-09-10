limit = int(input("Limit: "))
n = 1
total = 0
text = ''

while total < limit:
    total = total + n

    if len(text) > 0:
        text = text + f' + {n}'
    else:
        text = str(n)

    n = n + 1

print(f'The consecutive sum: {text} = {total}')
