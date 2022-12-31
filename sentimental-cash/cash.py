# TODO


def main():
    # Get the number of coins
    cents = get_cents()

    # Calculate the number of quarters to give the customer
    quarters = get_quarters(cents)
    cents = cents - quarters * 25

    dimes = get_dimes(cents)
    cents = cents - dimes * 10

    nickels = get_nickels(cents)
    cents = cents - nickels * 5

    pennies = get_pennies(cents)
    cents = cents - pennies * 1

    coins = int(quarters + dimes + nickels + pennies)
    print(f"{coins}")


def get_cents():
    # Initiating the variable to make the loop work
    cents = -1

    # Catching non numerical user input and
    # reprompting the user in case of error
    while cents < 0:
        try:
            cents = float(input("Change Owed: "))
        except:
            print("Sorry, please type a float.")
            get_cents()

    return cents * 100


def get_quarters(cents):
    # Floored (//) so we only take in
    # consideration whole number of coins
    coins = cents // 25
    return coins


def get_dimes(cents):
    coins = cents // 10
    return coins


def get_nickels(cents):
    coins = cents // 5
    return coins


def get_pennies(cents):
    coins = cents // 1
    return coins


if __name__ == "__main__":
    main()

