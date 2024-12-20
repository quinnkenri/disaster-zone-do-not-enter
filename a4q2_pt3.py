# CMPT-142 Assignment 4, Question 2, Part 3
# NumPy System of Linear Equations Solver
# Created by: Quinn Lawson (SN: 11400636, NSID: lwa854)

import numpy as np

def doc_to_list(filename):
    """
    Reads a file for linear equations and returns a list representing all the left-hand-sides
     (coefficient matrices) and a list representing the right-hand-side (constant vector).
    input: filename, a .txt file containing equations
    returns:
        coefficient_matrix: a list of str representing the left-hand-sides of the equations in filename
        constant_vector: a list of int representing the right-hand-side of the equations in filename
    """
    coefficient_matrix = []
    constant_vector = []

    file = open(filename, 'r')
    for line in file:
        left, right = [s.strip() for s in line.split('=')]
        coefficient_matrix.append(left)
        constant_vector.append(right)
    file.close()

    constant_vector = [int(i) for i in constant_vector] # convert to a list of ints

    return coefficient_matrix, constant_vector


def var_name_retrieval(coefficient_matrix):
    """
    Accepts a list of equations and returns the variable names found in that list.
    input: coefficient_matrix, a list of str containing linear equations
    returns:
        variables: a list of str containing variable names
    """
    variables = []

    for equation in coefficient_matrix:
        terms = equation.split()
        for term in terms:
            variable = ''.join([t for t in term if t.isalpha()])
            if variable and variable not in variables: # if variable not documented yet
                variables.append(variable)

    return variables


def equation_retrieval(coefficient_matrix):
    """
    Accepts a list of equations and splits it into a list-of-lists where each sublist contains
    the coefficients of a single equation in the original list.
    input: coefficient_matrix, a list of str containing linear equations
    returns:
        equation_coeffs: a list-of-lists of int containing coefficients
    """
    equation_coeffs = []
    for equation in coefficient_matrix:
        coefficients = []
        coeffs = equation.split(' + ') # assume all terms are separated by plus sign and spaces
        for coeff in coeffs:
            coeff = coeff.strip()
            if coeff:
                index = 0 # index for while loop
                while index < len(coeff):
                    if coeff[index].isalpha(): # if current character is letter
                        coefficient = coeff[:index].strip() # coefficient is part before letter
                        if coefficient == '-': # if coefficient is just negative sign it means -1
                            coefficient = '-1'
                        if not coefficient: # if no coefficient it means 1
                            coefficient = '1'
                        coefficients.append(int(coefficient)) # convert to int
                        break
                    index += 1 # loop until letter found
        equation_coeffs.append(coefficients) # add resulting list to overall list
    return equation_coeffs


filename = input("Enter file name for the system of equations: ")

coefficient_matrix, constant_vector = doc_to_list(filename)
variable_names = var_name_retrieval(coefficient_matrix)
coefficients = equation_retrieval(coefficient_matrix)

A = np.array(coefficients)
b = np.array(constant_vector)
x = np.linalg.solve(A, b) # Ax=b is typical notation for matrix equation

print("Solution for equations from", filename)
print("------------")
for i in range(len(variable_names)):
    print(variable_names[i], " = ", x[i]) # x[i] prints answer