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

def memo_wrapper(maxSize=None):
    def _memo(f: callable):
        cache = {}
        
        def clear_cache():
            cache.clear()
        
        @wraps(f)
        def withMemo(*args, **kvargs):
            key = repr(args)
            if key in cache:
                return cache[key]
            r = f(*args, **kvargs)
            
            # Random replacement policy
            if len(cache) == maxSize:
                deleted_qty = 0
                for k in cache.keys():
                    del cache[k]
                    deleted_qty += 1
                    if deleted_qty >= maxSize / 2:
                        break
            if maxSize is None or len(cache) < maxSize:
                cache[key] = r
            return r
        
        withMemo.__dict__['clear_cache'] = clear_cache
        
        return withMemo
    
    return _memo

def memo(f=None, *, maxSize=None):
	wrapper = memo_wrapper(maxSize=maxSize)
	if f is None:
		return wrapper
	else:
		return wrapper(f)

@memo
@debug
def add1(a, b):
    return a + b
    
@memo(maxSize=2)
@debug
def add(a, b):
    return a + b


add1(1,2)
add1(1,2)
add1(1,2)
add1(1,2)
add1(1,3)
add1(1,5)
add1(1,5)
add(1,2)
add(1,3)
add(1,5)
add(1,6)
add(1,7)
add(1,8)
add(1,8)
add(1,8)
add(1,8)
add(1,8)
# add({}, [])
