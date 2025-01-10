from lcg_closure import create_lcg_ansi as create_lcg_closure
from lcg_global_vars import seed_random as seed_random_global_vars, random as random_global_vars
from lcg_class import Random

print("\nClosure based generator:")
random = create_lcg_closure(123) # seed - 123
for n in range(3):
    print(random())
    
print("\nGlobal variables based generator:")
seed_random_global_vars(123)
for n in range(3):
    print(random_global_vars())

print("\nClass based generator:")
random = Random(123)
for n in range(3):
    print(random.get_number())
