#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // prompts user for input.
    do
    {
        height = get_int("Heigth(0-23): ");
    }
    while (height > 23 || height < 0);

    // start drawing loops
    for (int col = 0; col < height; col++)
    {
        // spaces
        for (int spaces = 0; spaces < height - col - 1; spaces++)
        {
            printf(" ");
        }
        // blocks
        for (int blocks = 0; blocks < col + 2; blocks++)
        {
            printf("#");
        }
        // start new line
        printf("\n");
    }
}
