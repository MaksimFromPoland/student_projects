from typing import List


def split_by_index(s: str, indexes: List[int]) -> List[str]:
    valid_indexes = sorted(i for i in indexes if 0 < i < len(s))

    result = []
    prev = 0

    for idx in valid_indexes:
        result.append(s[prev:idx])
        prev = idx

    result.append(s[prev:])

    return result