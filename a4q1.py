# CMPT-142 Assignment 4, Question 1
# Prime Number Dictionary
# Created by: Quinn Lawson (SN: 11400636, NSID: lwa854)

from cache_primes_starter import is_prime

def prime_dict(filename):
    """
    Reads a file for numbers, and caches the results of whether they are prime or not in a dictionary
    input: filename, a .txt file containing numbers
    returns: result_dict, a dictionary with numbers as keys and Boolean True/False as values
    """
    result_dict = {}
    file = open(filename, 'r')
    for line in file:
        line = line.rstrip()
        number = int(line)
        result_dict[number] = is_prime(number)
    file.close()
    return result_dict

result = prime_dict("numbers.txt")
print(result)