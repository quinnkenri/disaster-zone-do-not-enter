# CMPT-142 Assignment 5, Question 1
# Recursive Sentence Reverser
# Created by: Quinn Lawson (SN: 11400636, NSID: lwa854)

def reverse_phrase(sentence):
    """
    Splits an inputted phrase into individual words and calls a second function to reverse the phrase
    Parameters:
        sentence: a string containing the phrase to be reversed
    Returns:
        a call to a second function, reverse_phrase_recursive, which reverses the phrase
    """
    words = sentence.split(" ")
    return reverse_phrase_recursive(words)

def reverse_phrase_recursive(words):
    """
    Reverses the order of words in a sentence using recursion
    Parameters:
        words: a string containing the phrase to be reversed
    Returns:
        the reversed phrase
    """
    if len(words) <= 1:
        return " ".join(words)
    return reverse_phrase_recursive(words[1:]) + " " + words[0]

print(reverse_phrase("DO I CHOOSE YOU PIKACHU"))