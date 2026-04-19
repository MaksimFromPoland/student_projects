from typing import Dict


def get_dict(s: str) -> Dict[str, int]:
    d = {}
    s = s.lower()
    for i in s:
        temp = s.count(i)
        d[i] = temp

    return d


