#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt user for input
    int n = -1;

    while((n<=0) | (n >=9))
    {
        n = get_int("Height: ");
    }

    // loop
    int spaces = n-1;
    int hash = 1;
    for(int i = 0; i < n; i++)
    {
        for (int j = spaces; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < hash; k++)
        {
            printf("#");
        }
        printf("\n");
        spaces -= 1;
        hash += 1;
    }

}