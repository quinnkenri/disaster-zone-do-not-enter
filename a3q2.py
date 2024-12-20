# CMPT-142 Assignment 3, Question 2
# Closest to Zero Function
# Created by: Quinn Lawson (SN: 11400636, NSID: lwa854)

def closest_to_zero(num1, num2, num3):
    """
    Returns the number closest to zero among three given three numbers
    In case of two numbers equally close to zero, returns the positive one
    Params:
        num1: int or float, one of the numbers being compared
        num2: int or float, one of the numbers being compared
        num3: int or float, one of the numbers being compared
    Returns: whichever of the original three parameters is closest to zero
    """
    min_abs_value = min(abs(num1), abs(num2), abs(num3))
    tiebreaker = [num for num in (num1, num2, num3) if abs(num) == min_abs_value]
    if len(tiebreaker) > 1:
        return max(tiebreaker)
    else:
        return tiebreaker[0]