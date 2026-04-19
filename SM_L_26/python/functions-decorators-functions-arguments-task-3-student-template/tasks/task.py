from typing import Dict

def combine_dicts(*args:Dict[str, int]) -> Dict[str, int]:
    ddd = {}
    keyss = list(i.keys() for i in args)
    for t in args:
        for key, value in t.items():
            if key in ddd:
                ddd[key] += value
            else: ddd[key] = value

    return ddd

