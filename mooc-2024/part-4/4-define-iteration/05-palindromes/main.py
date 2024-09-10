def is_palindrome(s: str):
    return "".join(reversed(s)) == s

while True:
    s = input("Please type in a palindrome: ")
    if is_palindrome(s):
        print(s, "is a palindrome!")
    else:
        print("that wasn't a palindrome")
        break