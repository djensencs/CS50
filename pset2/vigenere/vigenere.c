//
// a program that encrypts messages using Vigenere's cipher.
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
        printf("Error: command-line argument should be: ./caesar <text>\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        //make sure key is all alpha
        while (!isalpha(argv[1][i]))
        {
            printf("Error: command-line argument must be in alphabetic characters only. \n");
            return 1;
        }

    }

    int klen = strlen(argv[1]);
    string k = argv[1];

    for (int i = 0; i < klen; i++)
    {
        // make key all lowercase for easier encpyptioin
        k[i] = tolower(k[i]);
    }

    // take input text to be encrypted
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    int kreset = 0;
    for (int i = 0; i < strlen(plain); i++, kreset++)
    {
        if isupper(plain[i])
        {
            // uppercase starts at 65 on ascii chart, mod 26 to keep in upper, k-97 b/c string in lower
            printf("%c", (((plain[i] - 65 + k[kreset] - 97) % 26) + 65));
        }

        else if islower(plain[i])
        {
            //lowercase starts at 97 on ascii chart, mod 26 to keep in lower, k-97 b/c string in lower
            printf("%c", (((plain[i] - 97 + k[kreset] - 97) % 26) + 97));
        }
        else
        {
            // keep key the same if printing special character
            printf("%c", plain[i]);
            kreset--;
        }
        // check key and reset if at the end
        if (kreset >= klen - 1)
        {
            kreset = -1;
        }
    }
    printf("\n");
    return 0;
}



