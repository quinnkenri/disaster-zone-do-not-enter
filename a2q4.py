availability = { "Caesar" : ["Sunday","Monday"],
                "Cleopatra" : ["Monday", "Tuesday"],
                 "Napoleon" : ["Tuesday", "Wednesday"],
                 "Jesus" : ["Monday", "Tuesday", "Wednesday"]
}


def schedule(availability):
    result = { "Monday" : [], "Tuesday" : [], "Wednesday" : [], "Thursday" : [],
               "Friday" : [], "Saturday" : [], "Sunday" : []
    }

    for friend, days in availability.items():
        for day in days:
            result[day].append(friend)

    return result

print(result)

big = []
bestday = ""

