from typing import Any, List

def linear_seq(sequence: List[Any]) -> List[Any]:
    l = []
    for i in sequence:
        if isinstance(i, (list, tuple)):
            l.extend(linear_seq(i))
        else: l.append(i)

    return l

print(linear_seq([1,2,3,[4,5, (6,7)]]))