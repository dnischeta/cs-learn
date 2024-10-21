person1 = {"name": "Mary", "result1": 2, "result2": 3, "result3": 3}
person2 = {"name": "Gary", "result1": 5, "result2": 1, "result3": 8}
person3 = {"name": "Larry", "result1": 3, "result2": 1, "result3": 1}

print(smallest_average([person1, person2, person3])

def smallest_average(persons):
    avgs = []

    for idx, person in enumerate(persons):
        avgs[idx] = (person['result1'] + person['result2'] + person['result3']) / 3

    return persons[avgs.index(min(avgs))]