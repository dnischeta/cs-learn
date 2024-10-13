import math

max = -math.inf

with open('numbers.txt', encoding='utf-8') as f:
    for line in f:
        if int(line) > max:
            max = int(line)

print('Maximum is', max)