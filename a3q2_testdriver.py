# CMPT-142 Assignment 3, Question 2
# White Box Testing: Closest to Zero Function
# Created by: Quinn Lawson (SN: 11400636, NSID: lwa854)

from a3q2 import closest_to_zero

all_passed = True

# test case 1: all unique positive integers in mixed order
num1, num2, num3 = 3, 1, 2
expected = 1
result = closest_to_zero(num1, num2, num3)
if result != expected:
    print("Testing closest_to_zero() with", num1, num2, num3, " Expected:", expected, " Got:", result)
    all_passed = False


# test case 2: all unique negative integers in order
num1, num2, num3 = -3, -2, -1
expected = -1
result = closest_to_zero(num1, num2, num3)
if result != expected:
    print("Testing closest_to_zero() with", num1, num2, num3, " Expected:", expected, " Got:", result)
    all_passed = False


# test case 3: tie scenario: two of the same positive integer
num1, num2, num3 = 3, 4, 3
expected = 3
result = closest_to_zero(num1, num2, num3)
if result != expected:
    print("Testing closest_to_zero() with", num1, num2, num3, " Expected:", expected, " Got:", result)
    all_passed = False


# test case 4: tie scenario: two of the same negative integer
num1, num2, num3 = -4, -5, -4
expected = -4
result = closest_to_zero(num1, num2, num3)
if result != expected:
    print("Testing closest_to_zero() with", num1, num2, num3, " Expected:", expected, " Got:", result)
    all_passed = False


# test case 5: tie scenario: two zeroes
num1, num2, num3 = 0, 0, 1
expected = 0
result = closest_to_zero(num1, num2, num3)
if result != expected:
    print("Testing closest_to_zero() with", num1, num2, num3, " Expected:", expected, " Got:", result)
    all_passed = False


# test case 6: tie scenario: positive and negative
num1, num2, num3 = -2, 3, 2
expected = 2
result = closest_to_zero(num1, num2, num3)
if result != expected:
    print("Testing closest_to_zero() with", num1, num2, num3, " Expected:", expected, " Got:", result)
    all_passed = False


# test case 7: tie scenario: floating point positive and negative
num1, num2, num3 = -2.2, 3.3, 2.2
expected = 2.2
result = closest_to_zero(num1, num2, num3)
if result != expected:
    print("Testing closest_to_zero() with", num1, num2, num3, " Expected:", expected, " Got:", result)
    all_passed = False


# test case 8: all zeroes
num1, num2, num3 = 0, 0, 0
expected = 0
result = closest_to_zero(num1, num2, num3)
if result != expected:
    print("Testing closest_to_zero() with", num1, num2, num3, " Expected:", expected, " Got:", result)
    all_passed = False


if all_passed:
    print("All tests passed")