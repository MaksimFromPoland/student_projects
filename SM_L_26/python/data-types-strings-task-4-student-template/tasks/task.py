from operator import truediv


def check_str(s: str):
    l = [chr(i) for i in range(ord("a"), ord("z") + 1)]
    result = ""

    for i in s.lower():
        if i in l or i.isdigit():
            result += i

    x = result[::-1]
    if result == x:
        return True

    return False
