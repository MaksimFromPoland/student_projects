from typing import Union, List

ListType = List[Union[int, str]]


def get_fizzbuzz_list(n: int) -> ListType:
    result = []
    for i in range(1, n + 1):
        if i % 5 == 0 and i % 3 == 0:
            result.append("FizzBuzz")
        elif i % 3 == 0:
            result.append("Fizz")
        elif i % 5 == 0:
            result.append("Buzz")
        else: result.append(i)

    return result


print(get_fizzbuzz_list(15))