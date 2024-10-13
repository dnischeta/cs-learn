fruits = {}

with open('fruits.csv', encoding='utf-8') as f:
    for line in f:
        line = line.replace('\n', '')
        entries = line.split(';')
        fruits[entries[0]] = float(entries[1])

print(fruits)