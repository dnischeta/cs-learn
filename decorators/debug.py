from functools import reduce

def debug(f: callable):
    def withDebug(*args, **kvargs):
        r = f(*args, **kvargs)
        l = [*args]
        if len(kvargs) > 0:
            l.append(kvargs)
        print(f"DEBUG: {f.__name__}{l} -> {r}") 
        return r
    
    return withDebug
    
@debug
def add(a, b):
    return a + b

@debug
def sum(*args, **kvargs):
    print(kvargs)
    return reduce(lambda s, n: s + n, args, 0)

add(1,2)
sum(1,2,3,4,5)
sum(1,2,3,4,5,some=1)