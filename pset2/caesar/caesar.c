//
// a program that encrypts messages using Caesar's cipher.
//

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check for proper command line input
    if (argc != 2)
    {
        printf("Error: command-line argument should be: ./caesar <positive int>\n");
        return 1;
    }

    // converts string to int and makes sure it's positive
    int k = atoi(argv[1]);
    if (k < 0)
    {
        printf("Error: command-line argument should be: ./caesar <positive int>\n");
        return 1;
    }

    // gets input of text to be encrypted
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");

    // iterate thru length of string
    for (int i = 0; i < strlen(plain); i++)
    {
        if isupper(plain[i])
        {
            // uppercase starts at 65 on ascii chart, mod 26 to keep in upper
            printf("%c", (((plain[i] - 65 + k) % 26) + 65));
        }

        else if islower(plain[i])
        {
            //lowercase starts at 97 on ascii chart, mod 26 to keep in lower
            printf("%c", (((plain[i] - 97 + k) % 26) + 97));
        }
        // to print spaces and special characters
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}