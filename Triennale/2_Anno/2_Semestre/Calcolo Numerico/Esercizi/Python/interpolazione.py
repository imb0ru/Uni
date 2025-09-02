from typing import Callable

import numpy as np
import numpy.typing as npt

import matplotlib.pyplot as plt

def vandermonde(x: npt.NDArray) -> npt.NDArray:
    if x.ndim != 2 or x.shape[1] != 1:
        raise ValueError("x must be a vector")

    n = x.shape[0]
    V = np.zeros((n, n))
    for j in range(n):
        for i in range(n):
            V[j, i] = x[j, 0]**i

    return V

def interpolate(x: npt.NDArray, y: npt.NDArray) -> npt.NDArray:
    if x.ndim != 2 or x.shape[1] != 1:
        raise ValueError("x must be a vector")
    if y.ndim != 2 or y.shape[1] != 1:
        raise ValueError("y must be a vector")

    if x.shape[0] != y.shape[0]:
        raise ValueError("x and y must have the same length")

    V = vandermonde(x)
    a = np.linalg.solve(V, y)

    return a

def lagrange(x: npt.NDArray, y: npt.NDArray, xx: npt.NDArray) -> npt.NDArray:
    if x.ndim != 2 or x.shape[1] != 1:
        raise ValueError("x must be a vector")
    if y.ndim != 2 or y.shape[1] != 1:
        raise ValueError("y must be a vector")
    if xx.ndim != 2 or xx.shape[1] != 1:
        raise ValueError("xx must be a vector")

    if x.shape[0] != y.shape[0]:
        raise ValueError("x and y must have the same length")

    n = x.shape[0]

    yy = np.zeros(xx.shape)
    for i in range(xx.shape[0]):
        value = 0
        for j in range(n):
            term = 1
            for k in range(n):
                if j == k:
                    continue

                term *= (xx[i, 0] - x[k, 0]) / (x[j, 0] - x[k, 0])
            value += y[j, 0] * term
        yy[i, 0] = value

    return yy

def lagrange_graph(f: Callable[[float], float], low: float, high: float, n_points: int):
    if low >= high:
        raise ValueError("low must be lower than high")

    if n_points <= 0:
        raise ValueError("n_points must be positive")

    px = np.linspace(low, high, n_points).reshape(-1, 1)
    py = lagrange(px, np.vectorize(f)(px), px)

    x = np.linspace(low, high, 1000).reshape(-1, 1)
    y = np.vectorize(f)(x)

    _, ax = plt.subplots()

    ax.plot(x, y)
    ax.plot(px, py)

    plt.show()

if show_graphs := False:
    lagrange_graph(lambda x: np.exp(x) * np.sin(2 * x), 0, np.pi, 100)
    lagrange_graph(lambda x: 1 / (1 + x * x), -5, 5, 100)
