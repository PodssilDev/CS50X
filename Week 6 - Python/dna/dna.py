import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Missing command line arguments!")
        sys.exit(1)

    file_csv = sys.argv[1]
    file_text = sys.argv[2]

    # Read database file into a variable
    rows = []
    with open(file_csv) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)

    # Read DNA sequence file into a variable
    sequence_file = open(file_text)
    sequence = sequence_file.read()

    # Find longest match of each STR in DNA sequence
    dict = rows[0]
    dict_keys = list(dict.keys())
    i = 1

    counts = []
    while i < len(dict_keys):
        longest_count = longest_match(sequence, dict_keys[i])
        counts.append(longest_count)
        i += 1

    # Check database for matching profiles
    j = 0
    name = ""
    while j < len(rows):
        flag = True
        k = 1
        u = 0
        current = rows[j]
        while k < len(dict_keys):
            if int(current[dict_keys[k]]) != counts[u]:
                flag = False
                break
            k += 1
            u += 1
        if (flag):
            name = current[dict_keys[0]]
            return name
        j += 1

    return "No match"


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


name = main()
print(name)
