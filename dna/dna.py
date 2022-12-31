import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py databases.csv FILENAME")

    database = []
    # TODO: Read database file into a variable

    # Created a variable called database(see above) with an empty list
    # Open the file using the "open" method
    # The opened file is stored as an object in the reader variable
    # Appended each row in the reader variable to the database list
    # variable previously created
    with open(sys.argv[1], 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)


# Read DNA sequence file into a variable
    # Stored de dna sequence inside a variable called dna_sequence
    with open(sys.argv[2], 'r') as file:
        dna_sequence = file.read()

    # Find longest match of each STR in DNA sequence
    agatc = longest_match(dna_sequence, "AGATC")
    ttttttct = longest_match(dna_sequence, "TTTTTTCT")
    aatg = longest_match(dna_sequence, "AATG")
    tctag = longest_match(dna_sequence, "TCTAG")
    gata = longest_match(dna_sequence, "GATA")
    tatc = longest_match(dna_sequence, "TATC")
    gaaa = longest_match(dna_sequence, "GAAA")
    tctg = longest_match(dna_sequence, "TCTG")

    # Create a variable to track if a match was found
    found = False
    # If the database has "small" in it's name, use the following parameters
    if "small" in sys.argv[1]:
        for person in database:
            if (int(person["AGATC"]) == agatc and int(person["AATG"]) == aatg
                    and int(person["TATC"]) == tatc):

                found = True
                print(person["name"])

    # Else, if the database don't have small in it's name, use this parameters
    else:
        for person in database:
            if (int(person["AGATC"]) == agatc and int(person["TTTTTTCT"]) == ttttttct
                and int(person["AATG"]) == aatg and int(person["TCTAG"]) == tctag
                and int(person["GATA"]) == gata and int(person["TATC"]) == tatc
                    and int(person["GAAA"]) == gaaa and int(person["TCTG"]) == tctg):

                found = True
                print(person["name"])

    # If nothing no matches have been found, print "No match"
    if found != True:
        print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
