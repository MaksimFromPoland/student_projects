
def decorator_apply(lambda_func):
    def decorator(or_fn):
        def wrapper(*args, **kwargs):
            result = or_fn(*args, **kwargs)
            return lambda_func(result)
        return wrapper
    return decorator



@decorator_apply(lambda user_id: user_id + 1)
def return_user_id(num: int) -> int:
    return num
