def format_number(n):
    return f"{n:.2f}"

def formatted(l):
    return list(map(format_number, l))

my_list = [1.234, 0.3333, 0.11111, 3.446]
new_list = formatted(my_list)
print(new_list)