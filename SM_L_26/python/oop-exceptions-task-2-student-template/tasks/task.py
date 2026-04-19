from typing import Union

def divide(str_with_ints: str) -> Union[float, str]:
    parts = str_with_ints.split()
    if len(parts) < 2:
        return "Error code: not enough values to unpack"
    
    try:
        x = int(parts[0])
    except ValueError:
        return f"Error code: invalid literal for int() with base 10: '{parts[0]}'"
    
    try:
        y = int(parts[1])
    except ValueError:
        return f"Error code: invalid literal for int() with base 10: '{parts[1]}'"
    
    if y == 0:
        return "Error code: division by zero"
    
    result = x / y
    return round(result, 1)
