import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: dna.py csv txt")

    # TODO: Read database file into a variable
    STRs = []
    database = {}
    with open(sys.argv[1],"r") as csvfile:
        for row in csv.DictReader(csvfile):
            database[row['name']] = []
            for value in row:
                nbSTRS = len(row) - 1
                if value == 'name':
                    continue
                if value not in STRs:
                    STRs.append(value)
                database[row['name']].append(int(row[value]))
    
    # TODO: Read DNA sequence file into a variable
    sequence = ""
    with open(sys.argv[2],"r") as txtfile:
        for row in csv.reader(txtfile):
            sequence = row[0]

    # TODO: Find longest match of each STR in DNA sequence
    matches = []
    for i in range(len(STRs)):
        matches.append(longest_match(sequence,STRs[i]))

    # TODO: Check database for matching profiles
    for name,dna in database.items():
        match = True
        for i in range(len(dna)):
            if dna[i] != matches[i]:
                match = False
        if match:
            print(name)
            return
    
    print("No match")
    return


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
