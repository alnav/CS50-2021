#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string encipher(int key, string s);

int main(int argc, char *argv[])
{
    int key = 0;
    // get key
    if (argc == 2)
    {
        // check if key is valid number
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage ./caesar key\n");
                return 1;
            }
        }
        key = atoi(argv[1]);

    }
    else
    {
        printf("Usage ./caesar key\n");
        return 1;
    }


    // get plaintext
    string plainText = get_string("Plaintext: ");

    // encipher
    string cipherText = encipher(key, plainText);

    // print ciphertext
    printf("Ciphertext: %s\n", cipherText);

}

string encipher(int key, string s)
{
    // set key between 0 and 25
    key = key % 26;

    // loop through string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // check if letter is valid
        if ((s[i] >= 'a' && s[i] <= 'z') | (s[i] >= 'A' && s[i] <= 'Z'))
        {
            // check if it would go over, if that's the case, wrap around
            if (((s[i] + key) > 'Z' && (s[i] + key) < 'a') | ((s[i] + key) > 'z'))
            {
                s[i] += (key - 26);
            }
            else
            {
                s[i] += key;
            }

        }

    }
    // return string
    return s;
}