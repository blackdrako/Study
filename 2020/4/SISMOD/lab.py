from math import pi, fabs
import numpy as np
import matplotlib.pyplot as plt
import time
from scipy.integrate import ode
ts = [ ]
ys = [ ]
def fout(t, y):# обработчик шага
    pass
# функция правых частей системы ОДУ
def f(t, y, k):  #  имеется дополнительный аргумент k
         v1, v2, v3, x1, x2, x3, i1, i2, q1, q2 = y

         k1 = 10000
         k2 = 5000
         k3 = 15000
         m1 = 5
         m2 = 7
         m3 = 1

         g = 9.8

         newV1 = (-k1 * x1 - k2 * (x1 - x2) - k3 * (x1 - x3)) / m1
         newV2 = (-k2 * (x2 - x1)) / m2
         newV3 = (-k3 * (x3 - x1)) / m3

         L1 = 5. / 1000.
         L2 = 5. / 100.
         C1 = 5. / 1000000.
         R2 = 200

         E = 10
         R1 = 4 * 1000 * x2
         if ((x2 < 0) | (x2 > 0.1)):
             R1 = 0

         newI1 = (E - R1 * i1 - 1. / C1 * (q1 - q2)) / L1
         newI2 = (-1. / C1 * (q2 - q1) - R2 * i2) / L2

         Ur2 = i2*R2

         ts.append(t)
         ys.append([x2, Ur2/100-0.1])
         return [newV1, newV2, newV3, v1, v2, v3, newI1, newI2, i1, i2]
tmax= 1  # максимально допустимый момент времени
#
y0,t0=[0, 0, 0, 0, 0.03, 0, 0, 0, 0, 0], 0 # начальные условия
ODE=ode(f)
ODE.set_integrator('dopri5', max_step=0.001, nsteps = 1000000)
ODE.set_solout(fout)
fig, ax = plt.subplots()
fig.set_facecolor('yellow')
ODE.set_initial_value(y0, t0) # задание начальных значений
ODE.set_f_params(0)  # передача дополнительного аргумента k     # в функцию f(t,y,k) правых частей системы ОДУ
ODE.integrate(tmax)      # решение ОДУ
T=np.array(ts)
Y=np.array(ys)
plt.plot(T[100::],Y[100::,0],linewidth=3,label='X2')
plt.plot(T[100::],Y[100::,1],linewidth=3,label='U')


stop = time.time()
plt.grid(True)
# plt.xlim(0,8)
# plt.ylim(-0.1,2)
plt.legend(loc='best')
plt.show()
