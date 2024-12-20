# CMPT-142 Assignment 2, Question 2
# Matplotlib Polynomial Graph
# Created by: Quinn Lawson (SN: 11400636, NSID: lwa854)

import matplotlib.pyplot as plt

print("Plotter for polynomials of the form Ax^B + C")
print("---------------------")

A_value = float(input("Please input a value for A: "))
B_value = float(input("Please input a value for B: "))
C_value = float(input("Please input a value for C: "))
N = int(input("How many points should we plot? "))

x_values = []
for i in range(0,N):
    x_values.append(i)

y_values = [A_value*x_values**B_value+C_value for x_values in x_values]

plt.plot(x_values, y_values, label=f'{A_value}x^{B_value} + {C_value}')
plt.xlabel('x')
plt.ylabel('y')
plt.title(f'Polynomial Plot: {A_value}x^{B_value} + {C_value}')
plt.legend()

plt.show() # display plot



