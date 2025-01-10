# Linear congruential generator random generator - 1951

# Xn+1 = (a * Xn + c) mod m
# - m >= 2
# - 0 <= a < m
# - 0 <= c < m
# - 0 <= X0 < m, X0 - initial value
#
# That generator is sensitive to to the choice of the parameters m and a.

next = 1

def seed_random(seed):
    global next
    next = seed
    
def random():
    global next
    next = (1103515245 * next + 12345) & 0xFFFFFFFF # Use only 32-bit
    return ((next // 65536) % 32768) / 32768
