def union(*args) -> set:
    rset = set()
    temp = []
    for i in args:
        if i is list or set:
            for j in i:
                rset.update(j)
        elif i is tuple:
            temp = i
            for j in temp:
                rset.add(j)

    return rset


def intersect(*args) -> set:
    rset = set(args[0])
    for i in args[1:]:
        rset = rset.intersection(i)

    return rset

