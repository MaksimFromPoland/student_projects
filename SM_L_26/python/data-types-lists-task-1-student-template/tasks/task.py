from typing import List, Tuple

def sort_unique_elements(str_list: Tuple[str, ...]) -> List[str]:
    p = sorted(list(set(str_list)))

    return p
