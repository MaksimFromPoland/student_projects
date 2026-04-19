from functools import wraps


def validate(set_pixel):
    @wraps(set_pixel)
    def wrapper(*args):
        count = 0
        for i in args:
            if i >= 0 and i <= 256:
                count += 1

        if len(args) == 3 and count == 3:
            return set_pixel(*args)
        else:
            return "Function call is not valid!"


    return wrapper

@validate
def set_pixel(x: int, y: int, z: int) -> str:
  return "Pixel created!"

set_pixel(256, 300, 300)