from typing import Tuple

def get_tuple(num: int) -> Tuple[int]:
    r = str(num)
    re = tuple(int(i) for i in  r )


    return re


