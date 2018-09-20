#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float amt;
    int cents = 0;
    int coins = 0;

    // takes input.
    do
    {
        amt = get_float("change owed? ");
    }
    while (amt <= 0);

    // rounds float and changes to integer in cents.
    amt = round(amt * 100);
    cents = amt;

    // quarters
    while (cents >= 25)
    {
        coins++;
        cents -= 25;
    }
    // dimes
    while (cents >= 10)
    {
        coins++;
        cents -= 10;
    }
    // nickels
    while (cents >= 5)
    {
        coins++;
        cents -= 5;
    }
    // pennies
    while (cents >= 1)
    {
        coins++;
        cents -= 1;
    }
    printf("%i\n", coins);
}
