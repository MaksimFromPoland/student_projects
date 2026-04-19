from typing import List, Tuple, Union


def seq_sum(sequence: Union[List, Tuple]) -> int:
    l = 0

    for item in sequence:
        if isinstance(item, (list, tuple)):
            l += (seq_sum(item))
        else: l += item




    return l
