//
// a program that determines whether a provided credit card number is valid according to Luhn's algorithimm.
//
#include <stdio.h>
#include <cs50.h>

int main(void)

{
    long long card, check;
    int odd, even, type, count, i;
    odd = even = count = 0;
    i = 1;

    do
    {
        printf("CARD NUMBER: \n");
        card = get_long_long();
    }
    while (card < 0);

// counts the number of digits.
    check = card;
    while (check > 0)
    {
        check /= 10;
        count++;
    }
    while (card > 0)
    {
// takes card number down to last digit.
        int digit = card % 10;
// when card is down to a double digit number will save value to determine card type later.
        if (card < 100 && card > 9)
        {
            type = card;
        }
// integer i tracks odd or even state.
        if (i % 2 == 1)
        {
            odd += digit;
        }
        else
        {
// multiplies the digit by 2 and then adds the sum of the products digits together.
            digit *= 2;
            even += digit / 10 + digit % 10;
        }
// removes a digit off the card.
        card /= 10;
        i++;
    }
    int sum = even + odd;
    if (sum % 10 == 0)
    {
        if (((type / 10) == 4) && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        else if (((type == 34) || (type == 37)) && (count = 15))
        {
            printf("AMEX\n");
        }
        else if ((type > 50) && (type < 56) && (count = 16))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}