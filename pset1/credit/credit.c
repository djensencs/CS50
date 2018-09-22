//
// a program that determiens whether a number provided is a valid card # according to Luhn's algorithm
//

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long card_num, last, slast;
    int addprod, addsum, sum;
    addprod = addsum = sum = 0;

    // take input of positive card number
    do
    {
        card_num = get_long_long("CARD NUMBER: \n");
    }
    while (card_num < 0);

    // double every other digit and add the sum of product starting w/ 2nd to last digit
    for (slast = card_num / 10; slast > 0; slast /= 100)
    {
        if (2 * (slast % 10) > 9)
        {
            // add the products digits
            addprod += (2 * (slast % 10)) / 10;
            addprod += (2 * (slast % 10)) % 10;
        }
        else
        {
            // multiply by 2 and add sum
            addprod += 2 * (slast % 10);
        }
    }
    // sum every other digit starting with the last
    for (last = card_num; last > 0; last /= 100)
    {
        addsum += last % 10;
    }

    sum = addprod + addsum;

    //  if # is valid check for card type
    if (sum % 10 == 0)
    {
        if ((card_num >= 340000000000000 && card_num < 350000000000000) || (card_num >= 370000000000000 && card_num < 380000000000000))
        {
            printf("AMEX\n");
        }
        else if (card_num >= 5100000000000000 && card_num < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if ((card_num >= 4000000000000 && card_num < 5000000000000) || (card_num >= 4000000000000000 && card_num < 5000000000000000))
        {
            printf("VISA\n");
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
    return 0;
}