from typing import Callable

def find_zero(f: Callable[[float], float], low: float, high: float, tolerance: float = 1e-16, max_iterations: int = 1000) -> float:
    """
    `find_zero` finds a zero of a function `f` in the interval [`low`, `high`]
    with a maximum absolute error `tolerance`.

    :param f: the function
    :param low: the lower bound of the interval
    :param high: the higher bound of the interval
    :param tolerance: the maximum absolute error
    :param max_iterations: the maximum number of iterations
    :returns: the zero of the function in that interval (approximated)
    :raises ValueError: if the interval is invalid or if the images of the
                        bounds of the interval don't have opposite signs
    """
    if low > high:
        raise ValueError("The lower bound must be smaller than the higher bound")

    f_low = f(low)
    f_high = f(high)

    if f_low * f_high > 0:
        raise ValueError("The images of the bounds of the interval don't have opposite signs")

    iterations = 0
    mid = 0
    while iterations < max_iterations and high - low > tolerance:
        mid = (low + high) / 2
        f_mid = f(mid)
        if f_mid == 0:
            break

        if f_low * f_mid < 0:
            high, f_high = mid, f_mid
        else:
            low, f_low = mid, f_mid

        iterations += 1

    if iterations == max_iterations and high - low > tolerance:
        print("[WARN] Required tolerance not reached")

    return mid
