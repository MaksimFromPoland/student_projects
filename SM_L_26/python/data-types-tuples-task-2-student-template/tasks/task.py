from typing import Any, Tuple, List

def get_pairs(lst: List[Any]) -> List[Tuple[Any, Any]]:
    if len(lst) < 2:
        return []

    r = list((lst[i], lst[i + 1]) for i in range(len(lst) - 1))

    return r

print(get_pairs([1, 2, 3, 4, 5]))