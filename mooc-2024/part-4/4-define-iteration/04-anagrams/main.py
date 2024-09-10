def are_anagrams(s1, s2):
    return sorted(s1) == sorted(s2) # O(n+nlogn)

print(are_anagrams("tame", "meta")) # True
print(are_anagrams("tame", "mate")) # True
print(are_anagrams("tame", "team")) # True
print(are_anagrams("tabby", "batty")) # False
print(are_anagrams("python", "java")) # False