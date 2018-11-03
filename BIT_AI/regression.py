import numpy as np
import matplotlib.pyplot as plt
from typing import Tuple, List


def my_loss(w_0: float, w_1: float, X: np.ndarray, Y: np.ndarray) -> float:
    error = 0
    total_error = 0
    for x, y in zip(X, Y):
        error = w_0 + w_1 * x - y
        total_error += error ** 2

    total_error /= len(X)
    return total_error

def my_loss_vectorized(w_0: float, w_1: float, X: np.ndarray, Y: np.ndarray) -> float:
    Y_pred = w_0 + w_1 * X
    errors = (Y_pred - Y) ** 2
    loss = errors.mean()
    return loss

def dLdw_0(w_0: float, w_1: float, X: np.ndarray, Y: np.ndarray) -> float:
    Y_pred = w_0 + w_1 * X
    errors = Y_pred - Y
    return errors.mean() * 2

def dLdw_1(w_0: float, w_1: float, X: np.ndarray, Y: np.ndarray) -> float:
    Y_pred = w_0 + w_1 * X
    errors = Y_pred - Y
    errors_mul = errors * X
    return errors_mul.mean() * 2


def gradient_step(w_0: float, w_1: float, X: np.ndarray, Y: np.ndarray, learning_rate: float) -> Tuple[float, float, float]:
    loss = my_loss(w_0, w_1, X, Y)
    delta_w_0 = 0.0
    delta_w_1 = 0.0
    N = len(X)
    for x, y in zip(X, Y):
        error = w_0 + w_1 * x - y
        delta_w_1 += error * x
        delta_w_0 += error

    delta_w_1 *= (2 / N)
    delta_w_0 *= (2 / N)

    w_1 = w_1 - learning_rate * delta_w_1
    w_0 = w_0 - learning_rate * delta_w_0

    return w_0, w_1, loss

def gradient_step_vectorized(
    w_0: float,
    w_1: float,
    X: np.ndarray,
    Y: np.ndarray,
    learning_rate: float
) -> Tuple[float, float, float]:
    loss = my_loss_vectorized(w_0, w_1, X, Y)
    delta_w_0 = dLdw_0(w_0, w_1, X, Y) * learning_rate
    delta_w_1 = dLdw_1(w_0, w_1, X, Y) * learning_rate
    w_0 = w_0 - delta_w_0
    w_1 = w_1 - delta_w_1
    return w_0, w_1, loss

def train_model(
    init_w_0: float,
    init_w_1: float,
    X: np.ndarray,
    Y: np.ndarray,
    learning_rate: float,
    num_iterations: int
) -> Tuple[float, float, List[float]]:
    w_0 = init_w_0
    w_1 = init_w_1
    loss_history = []
    for i in range(num_iterations):
        w_0, w_1, loss = gradient_step_vectorized(w_0, w_1, X, Y, learning_rate)
        loss_history.append(loss)
    return w_0, w_1, loss_history


def plot_linear_model(w_0: float, w_1: float, X: np.ndarray, Y: np.ndarray):
    Y_pred = w_0 + w_1 * X
    plt.scatter(X, Y)
    plt.plot(X, Y_pred, 'r')
    plt.show()
    print('w_0:', w_0)
    print('w_1:', w_1)
    print('Loss:', my_loss(w_0, w_1, X, Y))





if __name__ == "__main__":
    X_hard = np.linspace(1, 10)
    noise = np.random.normal(size=X_hard.shape)
    Y_hard = 10 * np.sin(X_hard) + 5 * X_hard - 10 + 3 * noise

    X = np.array([1, 2, 3, 4, 5, 6, 7])
    Y = np.array([4.1, 6.7, 10.8, 14.3, 15.5, 20.0, 21.37])

    X = X_hard
    Y = Y_hard

    init_w_0 = np.random.rand()
    init_w_1 = np.random.rand()
    learning_rate = 0.01
    num_iterations = 10

    trained_w_0, trained_w_1, loss_history = train_model(init_w_0, init_w_1, X, Y, learning_rate, num_iterations)

    #plt.plot(list(range(num_iterations)), loss_history)
    plot_linear_model(trained_w_0, trained_w_1, X, Y)

