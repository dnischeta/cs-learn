students = {}
grades = {}

with open('students.csv') as f:
    for line in f:
        parts = line.strip().split(';')
        if parts[0] == 'id':
            continue
        students[parts[0]] = f'{parts[1]} {parts[2]}'

with open('grades.csv') as f:
    for line in f:
        parts = line.strip().split(';')
        if parts[0] == 'id':
            continue
        grades[parts[0]] = sum([*map(int, parts[1:])])

for key in students:
    print(f'{students[key]}: {grades[key]}')