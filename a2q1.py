# CMPT-142 Assignment 2, Question 1
# Pokemon Battle Chart
# Created by: Quinn Lawson (SN: 11400636, NSID: lwa854)

def pokemon_effectiveness(attacker, defender):
    """
    Function to determine Pokemon effectiveness based on inputted attacker and defender
    Params:
        attacker: string. the type of attacking Pokemon
        defender: string. the type of defending Pokemon
    Returns: string representing Pokemon attack effectiveness
    """

    if attacker == "normal" or defender == "normal":
        return "okay."

    if attacker == "fire":
        if defender == "fire" or defender == "water":
            return "not very effective."
        elif defender == "electric":
            return "okay."
        elif defender == "grass" or defender == "ice":
            return "super effective!!!"

    elif attacker == "water":
        if defender == "water" or defender == "grass":
            return "not very effective."
        elif defender == "electric" or defender == "ice":
            return "okay."
        elif defender == "fire":
            return "super effective!!!"

    elif attacker == "grass":
        if defender == "fire" or defender == "grass":
            return "not very effective."
        elif defender == "electric" or defender == "ice":
            return "okay."
        elif defender == "water":
            return "super effective!!!"

    elif attacker == "electric":
        if defender == "grass" or defender == "electric":
            return "not very effective."
        elif defender == "fire" or defender == "ice":
            return "okay."
        elif defender == "water":
            return "super effective!!!"

    elif attacker == "ice":
        if defender == "fire" or defender == "water" or defender == "ice":
            return "not very effective."
        elif defender == "electric":
            return "okay."
        elif defender == "grass":
            return "super effective!!!"

    else:
        return "invalid!" # for user entering invalid pokemon

attacker = str.lower(input("Enter the type of attacking Pokemon: "))
defender = str.lower(input("Enter the type of defending Pokemon: "))
effectiveness = pokemon_effectiveness(attacker, defender)

print(f"Using {attacker} against {defender} is {effectiveness}")