from functools import reduce

def debug(f: callable):
    def withDebug(*args):
        r = f(*args)
        print(f"DEBUG: {f.__name__}{args} -> {r}") 
        return r
    
    return withDebug
    
@debug
def add(a, b):
    return a + b

@debug
def sum(*args):
    return reduce(lambda s, n: s + n, args, 0)

add(1,2)
sum(1,2,3,4,5)