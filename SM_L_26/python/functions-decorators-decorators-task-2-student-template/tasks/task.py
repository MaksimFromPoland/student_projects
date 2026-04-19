import time
import inspect


def log(fn):
    def wrapper(*args, **kwargs):
        start = time.time()
        result = fn(*args, **kwargs)
        end = time.time()

        sig = inspect.signature(fn)
        bound_args = sig.bind(*args, **kwargs)
        bound_args.apply_defaults()

        param_names = list(sig.parameters.keys())

        args_list = []
        kwargs_list = []

        for name, value in bound_args.arguments.items():
            if name in param_names:
                idx = param_names.index(name)
                if idx < len(args):
                    args_list.append(f"{name}={value}")
                else:
                    kwargs_list.append(f"{name}={value}")

        args_str = ', '.join(args_list)
        kwargs_str = ', '.join(kwargs_list)

        log_entry = f"{fn.__name__}; args: {args_str}; kwargs: {kwargs_str}; execution time: {end - start:.2f} sec.\n"

        with open('log.txt', 'a') as log_file:
            log_file.write(log_entry)

        return result

    return wrapper