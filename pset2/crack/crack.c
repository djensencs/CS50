#define _XOPEN_SOURCE
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    // check for proper command line input
    if (argc != 2)
    {
        printf("Error: command-line argument should be: ./crack <hash>\n");
        return 1;
    }
    // alpha counter for lowercase/uppercase + null char
    const int alpha = 53;
    string hash = argv[1];
    // letters from a-z ordered from highest to lowest frequncy in english language starting with null char for loops
    string letters = "\0etaoinsrhldcumfpgwybvkxjqzETAOINSRHLDCUMFPGWYBVKXJQZ";
    char salt[3];
    char key[6] = "\0\0\0\0\0\0";
    memcpy(salt, hash, 2);
    salt[2] = '\0';

    // Loops:
    // x\0
    // xx\0
    // xxx\0
    // xxxx\0
    // xxxxx\0

    for (int e = 0; e < alpha; e++)
    {
        for (int d = 0; d < alpha; d++)
        {
            for (int c = 0; c < alpha; c++)
            {
                for (int b = 0; b < alpha; b++)
                {
                    for (int a = 1; a < alpha; a++)
                    {
                        key[0] = letters[a];
                        key[1] = letters[b];
                        key[2] = letters[c];
                        key[3] = letters[d];
                        key[4] = letters[e];

                        if (strcmp(crypt(key, salt), hash) == 0)
                        {
                            printf("%s\n", key);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("Password couldn't be cracked!");
    return 2;
}