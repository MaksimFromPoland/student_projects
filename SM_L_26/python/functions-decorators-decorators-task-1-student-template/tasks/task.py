from curses import wrapper
from typing import Dict
import time
from functools import wraps

execution_time: Dict[str, float] = {}


def time_decorator(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        start = time.perf_counter()
        ror = fn(*args, **kwargs)
        end = time.perf_counter()
        result = end - start
        execution_time[fn.__name__] = result
        return ror
    return wrapper
