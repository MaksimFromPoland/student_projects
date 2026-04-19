from typing import Dict

def generate_squares(num: int)-> Dict[int, int]:
    d = {}
    for i in range(1, num + 1):
        d[i] = i ** 2

    return d

