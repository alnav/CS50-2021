#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start = -1;
    int end = -1;

    while (start < 9)
    {
        start = get_int("Start size: ");
    }

    // TODO: Prompt for end size
    while (end < start)
    {
        end = get_int("End size: ");
    }

    // TODO: Calculate number of years until we reach threshold
    int year = 0;
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        year++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", year);
}