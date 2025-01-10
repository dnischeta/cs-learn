# Middle-square

# Period of that generator is too small
# Just a demo:

seed_number = int(input("Input 6-digit number:\n[######] "))
number = seed_number
already_seen = set()
counter = 0

while number not in already_seen:
    counter += 1
    already_seen.add(number)
    number = int(str(number * number).zfill(8)[3:9])
    print(f"#{counter}: {number}")

print(f"We started from {seed_number} and got a repetition after {counter} steps with number: {number}")
