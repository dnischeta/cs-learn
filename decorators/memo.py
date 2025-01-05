from functools import wraps

def debug(f: callable):
    @wraps(f)
    def withDebug(*args, **kvargs):
        r = f(*args, **kvargs)
        l = [*args]
        if len(kvargs) > 0:
            l.append(kvargs)
        print(f"DEBUG: {f.__name__}{l} -> {r}") 
        return r
    
    return withDebug

# TODO: support unhashable types
# TODO: support kwargs
# TODO: make polymorphic
def memo(maxSize=None):
    def _memo(f: callable):
        cache = {}
        @wraps(f)
        def withMemo(*args, **kvargs):
            print(type(args), type(kvargs))
            if args in cache:
                return cache[args]
            r = f(*args, **kvargs)
            if maxSize is None or len(cache) < maxSize:
                cache[args] = r
            return r
        
        return withMemo
    
    return _memo
    
@memo(maxSize=10)
@debug
def add(a, b):
    return a + b


add(1,2)
add(1,3)
add(1,5)
add(1,5)
# add({}, [])
