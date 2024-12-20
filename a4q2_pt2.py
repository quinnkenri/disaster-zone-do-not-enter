# CMPT-142 Assignment 4, Question 2, Part 2
# Simple NumPy System of Linear Equations Solver
# Created by: Quinn Lawson (SN: 11400636, NSID: lwa854)

import numpy as np

A = np.array([[2,1,3],
              [5,3,1],
              [1,7,12]])

b = np.array([9,15,0])

x = np.linalg.solve(A,b) # Ax=b is typical notation for matrix equation

print("Solution", x)