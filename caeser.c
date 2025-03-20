#include <stdio.h>

// Function to check if input is a valid number
bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // Ensure exactly one command-line argument is provided
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert key from string to integer
    int key = atoi(argv[1]);

    // Get plaintext input from user
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    // Encrypt each character
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char ch = plaintext[i];

        // Encrypt uppercase letters
        if (isupper(ch))
        {
            printf("%c", (ch - 'A' + key) % 26 + 'A');
        }
        // Encrypt lowercase letters
        else if (islower(ch))
        {
            printf("%c", (ch - 'a' + key) % 26 + 'a');
        }
        // Leave non-alphabetic characters unchanged
        else
        {
            printf("%c", ch);
        }
    }

    printf("\n");
    return 0;
}

// Function to check if key contains only digits
bool is_valid_key(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}
