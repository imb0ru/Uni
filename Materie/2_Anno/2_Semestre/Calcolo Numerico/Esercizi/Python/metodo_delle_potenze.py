from typing import Tuple
import numpy as np
import numpy.typing as npt

def power_iteration(A: npt.NDArray[np.float64], max_iterations: int = 100) -> Tuple[float, npt.NDArray]:
    n, m = A.shape
    if n != m:
        raise ValueError("Matrix must be square")

    if max_iterations <= 0:
        raise ValueError("Invalid number of iterations")

    z = np.random.rand(n, 1)
    for _ in range(max_iterations):
        t = A @ z
        z = t / np.linalg.norm(t)

    return ((A @ z).T @ z).item(), z
