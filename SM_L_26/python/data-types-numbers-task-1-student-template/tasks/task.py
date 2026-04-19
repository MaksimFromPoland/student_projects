from typing import Union

NumType = Union[int, float]

def some_expression_with_rounding(a: NumType, b: NumType) -> NumType:
  result = None
  a = 1.4
  b = 2.55
  result = (12 * a + 25 * b) / (1 + a ** (2 ** b))
  return round(result, 2)
