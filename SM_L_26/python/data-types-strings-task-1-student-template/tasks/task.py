def get_fractions(a_b: str, c_b: str) -> str:
    x = a_b.split("/")
    y = c_b.split("/")
    a = int(x[0])
    b = int(y[0])
    c = x[1]
    suma = a + b
    return f"{a_b} + {c_b} = {suma}/{c}"

