from typing import List

def check(row_start:int, row_end:int, column_start:int, column_end:int) -> List[List[int]]:
    l = []
    it = 0
    for i in range(row_start, row_end + 1):
        l.append([])
        for j in range(column_start, column_end + 1):
            l[it].append(i * j)
        it += 1
    return l

