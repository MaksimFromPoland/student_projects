def get_longest_word( s: str) -> str:
    x = s.split()
    maxk = 0
    for i in range(len(x)):
        if maxk < len(x[i]):
            maxk = len(x[i])
            b = x[i]

    return b

