import math
import numpy as np 
import matplotlib.pyplot as plt
# func = x**2 + 5*np.sin(x)
def grad_f(x):
    return 2*x+ 5*np.cos(x)

def f(x):
    return x**2 + 5*np.sin(x)

def myGD1(eta, x0):
    x = [x0]
    for it in range(100):
        x_new = x[-1] - eta*grad_f(x[-1])
        if abs(grad_f(x_new)) < 1e-3:
            break
        x.append(x_new)
    return (x, it)

(x1, it1) = myGD1(.1, -5)
(x2, it2) = myGD1(.1, 5)
print('Solution x1 = %f, cost = %f, obtained after %d iterations'%(x1[-1], f(x1[-1]), it1))
print('Solution x2 = %f, cost = %f, obtained after %d iterations'%(x2[-1], f(x2[-1]), it2))