import numpy as np
import numpy.typing as npt
from typing import Tuple

def laplace(A: npt.NDArray) -> float:
    n, m = A.shape
    if n != m:
        raise ValueError("A must be square")

    if n == 1:
        return A.item()

    result = 0
    for i in range(n):
        result += (-1)**i * A[0, i] * laplace(np.delete(np.delete(A, 0, 0), i, 1))
    return result

def backward_substitution(A: npt.NDArray, b: npt.NDArray) -> npt.NDArray:
    n, m = A.shape
    if n != m:
        raise ValueError("A must be square")

    x = np.zeros(shape=(n, 1))
    for i in range(n - 1, -1, -1):
        if abs(A[i, i]) <= 1e-15:
            raise ValueError("A must be non-singular")

        x[i, 0] = (b[i, 0] - A[i, i + 1:] @ x[i + 1:, 0]) / A[i, i]

    return x

def lu(A: npt.NDArray) -> Tuple[npt.NDArray, npt.NDArray]:
    n, m = A.shape
    if n != m:
        raise ValueError("A must be square")

    L = np.eye(n)
    U = A.copy()
    for i in range(n - 1):
        for j in range(i + 1, n):
            if abs(U[i, i]) <= 1e-15:
                raise ValueError("Principal minor cannot be null")

            L[j, i] = U[j, i] / U[i, i]
            U[j, i:] += -L[j, i] * U[i, i:]

    return L, U

def row_reduction(A: npt.NDArray) -> Tuple[npt.NDArray, npt.NDArray, npt.NDArray]:
    n, m = A.shape
    if n != m:
        raise ValueError("A must be square")

    P = np.eye(n)
    L = np.eye(n)
    U = A.copy()

    for i in range(n - 1):
        k = max(range(i, n), key=lambda x: abs(U[x, i]))
        if abs(U[k, k]) <= 1e-15:
            raise ValueError("Invalid matrix")

        if i != k:
            P[[i, k]] = P[[k, i]]
            U[[i, k]] = U[[k, i]]

        for j in range(i + 1, n):
            L[j, i] = U[j, i] / U[i, i]
            U[j, i:] += -L[j, i] * U[i, i:]

    return P, L, U

def ref(A: npt.NDArray) -> npt.NDArray:
    n, m = A.shape

    U = A.copy()
    lead = 0
    for i in range(n):
        if lead >= m:
            return U

        j = i
        while abs(U[j, lead]) <= 1e-15:
            j += 1
            if j == n:
                j = i
                lead += 1
                if lead == m:
                    return U

        U[[i, j]] = U[[j, i]]
        for k in range(n):
            if k != i:
                U[k, :] += -U[k, lead] / U[i, lead] * U[i, :]

        lead += 1

    return U

def rank(A: npt.NDArray) -> int:
    U = ref(A)
    rank = 0
    for i in range(U.shape[0]):
        rank += int(any(abs(U[i]) > 1e-15))

    return rank
