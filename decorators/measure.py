from time import perf_counter

def measure(f: callable):
    def withMeasure(*args, **kvargs):
        start = perf_counter()
        r = f(*args, **kvargs)
        end = perf_counter()
        print(f"DEBUG: {f.__name__} took {'{0:0.2f}'.format((end-start) * 1000)}ms")
        return r
    return withMeasure
        
@measure
def sum():
    r = 0
    for i in range(100000):
        r += i
    return r

print(sum())