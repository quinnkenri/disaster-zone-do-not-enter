# CMPT-142 Assignment 3, Question 1
# Black Box Testing
# Created by: Quinn Lawson (SN: 11400636, NSID: lwa854)

from testing_blackbox_improvedAverage_provided import improvedAverage

all_passed = True

# test case 1: empty list
test = []
expected = None
result = improvedAverage(test)
if result != expected:
    print("Testing improvedAverage() with", test, " Expected:", expected, " Got:", result)
    all_passed = False


# test case 2: one fewer than 20 values (otherwise would resolve True)
test = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19]
expected = None
result = improvedAverage(test)
if result != expected:
    print("Testing improvedAverage() with", test, " Expected:", expected, " Got:", result)
    all_passed = False


# test case 3: average of last 10 values is LESS than the average of all other values
test = [2] * 10 + [1] * 10
expected = False
result = improvedAverage(test)
if result != expected:
    print("Testing improvedAverage() with", test, " Expected:", expected, " Got:", result)
    all_passed = False


# test case 4: average of last 10 values is MORE than the average of all other values
test = [1] * 10 + [2] * 10
expected = True
result = improvedAverage(test)
if result != expected:
    print("Testing improvedAverage() with", test, " Expected:", expected, " Got:", result)
    all_passed = False


# test case 5: average of last 10 values is the SAME as the average of all other values
test = [1] * 20
expected = False
result = improvedAverage(test)
if result != expected:
    print("Testing improvedAverage() with", test, " Expected:", expected, " Got:", result)
    all_passed = False


if all_passed:
    print("All tests passed")