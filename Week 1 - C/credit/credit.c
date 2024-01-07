#include <cs50.h>
#include <stdio.h>

// Credit (more comfortable)
// Problem Set 1 - Week 1 - C
// Author: John Serrano

// Functions headers
int luhn_check1(long int card_number);
bool luhn_check2(long int card_number, int luhn_check_1);
void check_card_type(long int card_number);

int main(void)
{
    // Obtain input as a long int
    long int card_number = get_long("Number: ");
    // Obtain the sum of the other numbers multiplied by 2
    int luhn_check_1 = luhn_check1(card_number);
    // Check if the card number passes luhn's algorithm
    bool valid_card = luhn_check2(card_number, luhn_check_1);
    if (valid_card)
    {
        // If the card passes luhn's algorithm, check if AMEX, VISA or MASTERCARD
        check_card_type(card_number);
    }
    else
    {
        // If the card didn't pass luhn's algorithm, then is an invalid card number
        printf("INVALID\n");
    }
}

// Input: Credit card number, as a long integer
// Output: Sum of the other numbers multiplied by 2, as an integer
// Description: Function that obtains the sum of the other numbers multiplied by 2,
// returns an integer to be used for luhn's algorithm check.
int luhn_check1(long int card_number)
{
    int last_digit = 0;
    int sum_check1 = 0;
    bool flag_check1 = false;
    while (card_number >= 1)
    {
        if (flag_check1 == false)
        {
            card_number = card_number / 10;
            last_digit = card_number % 10;
            last_digit = last_digit * 2;
            sum_check1 = sum_check1 + (last_digit % 10) + (last_digit / 10);
            flag_check1 = true;
        }
        else
        {
            card_number = card_number / 100;
            last_digit = card_number % 10;
            last_digit = last_digit * 2;
            sum_check1 = sum_check1 + (last_digit % 10) + (last_digit / 10);
        }
    }
    return sum_check1;
}

// Input: Credit card number, as a long integer and the return value of luhn_check1
// as an integer.
// Output: A boolean that determines if the card number is valid (true) or not (false)
// Description: Function that determines, using luhn's algorithm if the card value
// is valid or not. Returns a boolean expression.
bool luhn_check2(long int card_number, int luhn_check_1)
{
    int last_digit = 0;
    int sum_check2 = 0;
    while (card_number >= 1)
    {
        last_digit = card_number % 10;
        sum_check2 += last_digit;
        card_number = card_number / 100;
    }
    sum_check2 += luhn_check_1;
    last_digit = sum_check2 % 10;
    if (last_digit == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Input: Credit card number, as a long integer
// Output: No output (But it does print on terminal)
// Description: Function that checks, using the information provided, if the card
// corresponds to American Express (AMEX), Mastercard (MASTERCARD) or Visa (VISA).
// If it doesn't correspond to any of the three, it prints INVALID.
void check_card_type(long int card_number)
{
    int card_length = 0;
    int first_digit = 0;

    while (card_number >= 10)
    {
        card_length += 1;
        first_digit = card_number % 100;
        card_number = card_number / 10;
    }
    card_length += 1;
    // Check for American Express
    if (card_length == 15)
    {
        if (first_digit == 34 || first_digit == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // Check for Visa
    else if (card_length == 13)
    {
        if ((first_digit / 10) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // Check for Visa or Mastercard
    else if (card_length == 16)
    {
        if ((first_digit / 10) == 4)
        {
            printf("VISA\n");
        }
        else if (first_digit == 51 || first_digit == 52 || first_digit == 53 || first_digit == 54 || first_digit == 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // If none of the previous checks are true, then the card number is Invalid.
    else
    {
        printf("INVALID\n");
    }
}
