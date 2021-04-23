#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Prompt user for amount
    float amount = -1;
    do
    {
        amount = get_float("How much money?");
    }
    while (amount < 0);

    // declare variables
    int cents = round(amount * 100);
    int quarters = 0;
    int dimes = 0;
    int nichels = 0;
    int pennies = 0;

    // Loop reducing cents while increasing coins
    while (cents > 0)
    {
        if ((cents - 25) >= 0)
        {
            quarters += 1;
            cents -= 25;
        }
        else if ((cents - 10) >= 0)
        {
            dimes += 1;
            cents -= 10;
        }
        else if ((cents - 5) >= 0)
        {
            nichels += 1;
            cents -= 5;
        }
        else
        {
            pennies = cents;
            cents = 0;
        }
    }

    // Sum coins
    int total_coins = quarters + dimes + nichels + pennies;

    // Results
    printf("Cash %i", total_coins);


}