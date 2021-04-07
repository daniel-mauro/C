#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // credit card number
    long num = 4003400240014004;

    // get a number from user
    do
    {
        num = get_long("Number: ");
    }
    while (num < 0);

    // make copy of number for later use
    long copy = num;

    // pass1 is for single digits, pass2 is for digits that get doubled
    int pass = 0;
    int temp = 0;

    while (num)
    {
        // start by adding final digit
        pass += (num % 10);
        num /= 10;

        // need to check if the result is double digit
        temp = (num % 10) * 2;
        if (temp > 9)
        {
            pass += temp % 10;
            pass++;
        }
        else
        {
            pass += temp;
        }
        num /= 10;
    }

    //printf("%i\n", pass);

    if (pass % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // AMEX must start with 34 or 37 and be 15 digits
    if ((copy > 339999999999999 && copy < 350000000000000) || (copy > 369999999999999 && copy < 380000000000000))
    {
        printf("AMEX\n");
        return 0;
    }

    // Mastercard must start with 51-55 and be 16 digits
    if (copy > 5099999999999999 && copy < 5600000000000000)
    {
        printf("MASTERCARD\n");
        return 0;
    }

    // Visa must start with 4 and be 13 or 16 digits
    if ((copy > 3999999999999 && copy < 5000000000000) || (copy > 3999999999999999 && copy < 5000000000000000))
    {
        printf("VISA\n");
        return 0;
    }

    // Base case - no cards match

    printf("INVALID\n");

}
