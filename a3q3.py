# CMPT-142 Assignment 3, Question 3
# Pokemon Battle Chart
# Created by: Quinn Lawson (SN: 11400636, NSID: lwa854)

def pokemon_record(pokemon_species, pokemon_type, pokemon_level):
    """
    Creates a dictionary to store each new pokemon and appends it to the overall Pokedex list
    Params:
        pokemon_species: user-inputted species of Pokemon
        pokemon_type: user-inputted type of Pokemon
        pokemon_level: user-inputted Pokemon power level
    Returns: nothing, just assembles a list of dictionaries
    """
    pokedex.append({'Species': pokemon_species, 'Type': pokemon_type, 'Level': pokemon_level})


pokedex = []
enter_more = True # when set to False, ends while loop

print("Welcome to the PokeDex Logger!")
print("Enter info for newly-caught Pokemon:")

while enter_more:
    pokemon_species = input("Pokemon's species? ")
    pokemon_type = input("Pokemon type? ")
    pokemon_level = input("Pokemon level? ")

    pokemon_record(pokemon_species, pokemon_type, pokemon_level) # function to store pokémon

    print("-------")
    choice = input("Are there more Pokemon to add (y/n)? ").lower()
    if choice == "n":
        enter_more = False # end while loop

print("Logging complete. Printing final Pokedex: ")
for entry in pokedex:
    print(entry)