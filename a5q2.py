# CMPT-142 Assignment 5, Question 2
# Pikachu Treasure Chooser
# Created by: Quinn Lawson (SN: 11400636, NSID: lwa854)

from treasure_starter import read_data

def treasure_chooser(treasures, remaining_space):
    """
    Uses recursion on a list of values and weights to determine the maximum value that
    could be accumulated while staying under a given weight
    Parameters:
        treasures: call to an external function that provides a list of treasures and their values/weights
        remaining_space: the amount of space left in the treasure bag
        Returns:
            the maximum value of treasure that could be recovered under the given weight
    """

    if not treasures or remaining_space <= 0:
        return 0

    current_treasure = treasures[0]
    value = current_treasure['value']
    weight = current_treasure['weight']

    exclude_treasure = treasure_chooser(treasures[1:], remaining_space) # exclude current treasure

    if weight <= remaining_space:
        include_treasure = value + treasure_chooser(treasures[1:], remaining_space - weight) # include current treasure
    else:
        include_treasure = 0 # if treasure does not fit in bag, cannot include

    return max(exclude_treasure, include_treasure) # return largest possible total


treasures = read_data("room1.txt")
remaining_space = 100
treasure_value = treasure_chooser(treasures, remaining_space)
print(f"Pikachu could recover ${treasure_value}") # formatted answer
