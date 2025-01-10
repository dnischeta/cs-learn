# Linear congruential generator random generator - 1951

# Xn+1 = (a * Xn + c) mod m
# - m >= 2
# - 0 <= a < m
# - 0 <= c < m
# - 0 <= X0 < m, X0 - initial value
#
# That generator is sensitive to to the choice of the parameters m and a.

# Certain params are borrowed from ANSI C example
# def create_lcg_ansi(seed):
#     while True:
#         seed = (1103515245 * seed + 12345) & 0xFFFFFFFF # Use only 32-bit
#         yield (seed // 65536) % 32768

def create_lcg_ansi(seed):
    next = seed
    def random():
        nonlocal next
        next = (1103515245 * next + 12345) & 0xFFFFFFFF # Use only 32-bit
        return ((next // 65536) % 32768) / 32768
    return random
