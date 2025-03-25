#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if input is a valid number
int is_valid_key(const char *key);

int main(int argc, char *argv[])
{
    // Ensure exactly one command-line argument is provided
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert key from string to integer and normalize it
    int key = atoi(argv[1]) % 26; // Ensures key wraps around within 26 letters

    // Get plaintext input from user
    char plaintext[256];
    printf("plaintext: ");
    if (!fgets(plaintext, sizeof(plaintext), stdin))
    {
        printf("Error reading input\n");
        return 1;
    }

    // Remove newline character if present
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("ciphertext: ");

    // Encrypt each character
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char ch = plaintext[i];

        if (isupper(ch))
        {
            putchar((ch - 'A' + key) % 26 + 'A');
        }
        else if (islower(ch))
        {
            putchar((ch - 'a' + key) % 26 + 'a');
        }
        else
        {
            putchar(ch);
        }
    }

    printf("\n");
    return 0;
}

// Function to check if key contains only digits
int is_valid_key(const char *key)
{
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isdigit(key[i]))
        {
            return 0;
        }
    }
    return 1;
}
