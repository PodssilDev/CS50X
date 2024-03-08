from cs50 import get_int

# Credit (Sentimental)
# Problem Set 6 - Week 6 - Python
# Author: John Serrano


# FUNCTIONS


# Input: Credit card number, as a integer
# Output: Sum of the other numbers multiplied by 2, as an integer
# Description: Function that obtains the sum of the other numbers multiplied by 2,
# returns an integer to be used for luhn's algorithm check.
def luhn_check1(card_number):
    last_digit = 0
    sum_check1 = 0
    flag_check1 = False
    while (card_number >= 1):
        if (flag_check1 == False):
            card_number = card_number // 10
            last_digit = card_number % 10
            last_digit = last_digit * 2
            sum_check1 = sum_check1 + (last_digit % 10) + (last_digit // 10)
            flag_check1 = True
        else:
            card_number = card_number // 100
            last_digit = card_number % 10
            last_digit = last_digit * 2
            sum_check1 = sum_check1 + (last_digit % 10) + (last_digit // 10)

    return sum_check1


# Input: Credit card number, as a integer and the return value of luhn_check1
# as an integer.
# Output: A boolean that determines if the card number is valid (true) or not (false)
# Description: Function that determines, using luhn's algorithm if the card value
# is valid or not. Returns a boolean expression.
def luhn_check2(card_number, luhn_check_1):
    last_digit = 0
    sum_check2 = 0
    while (card_number >= 1):
        last_digit = card_number % 10
        sum_check2 += last_digit
        card_number = card_number // 100
    sum_check2 += luhn_check_1
    last_digit = sum_check2 % 10
    if (last_digit == 0):
        return True
    else:
        return False


# Input: Credit card number, as a integer
# Output: No output (But it does print on terminal)
# Description: Function that checks, using the information provided, if the card
# corresponds to American Express (AMEX), Mastercard (MASTERCARD) or Visa (VISA).
# If it doesn't correspond to any of the three, it prints INVALID.
def check_card_type(card_number):
    card_length = 0
    first_digit = 0

    while (card_number >= 10):
        card_length += 1
        first_digit = card_number % 100
        card_number = card_number // 10
    card_length += 1
    # Check for American Express
    if (card_length == 15):
        if (first_digit == 34 or first_digit == 37):
            print("AMEX")
        else:
            print("INVALID")
    # Check for Visa
    elif (card_length == 13):
        if ((first_digit // 10) == 4):
            print("VISA")
        else:
            print("INVALID")

    # Check for Visa or Mastercard
    elif (card_length == 16):
        if ((first_digit // 10) == 4):
            print("VISA")
        elif (first_digit == 51 or first_digit == 52 or first_digit == 53 or first_digit == 54 or first_digit == 55):
            print("MASTERCARD\n")
        else:
            print("INVALID")
    # If none of the previous checks are true, then the card number is Invalid.
    else:
        print("INVALID")


# MAIN CODE


# Obtain input as a int
card_number = get_int("Number: ")
# Obtain the sum of the other numbers multiplied by 2
luhn_check_1 = luhn_check1(card_number)
# Check if the card number passes luhn's algorithm
valid_card = luhn_check2(card_number, luhn_check_1)
if (valid_card):
    # If the card passes luhn's algorithm, check if AMEX, VISA or MASTERCARD
    check_card_type(card_number)
else:
    # If the card didn't pass luhn's algorithm, then is an invalid card number
    print("INVALID")
