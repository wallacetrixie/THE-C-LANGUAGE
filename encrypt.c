#include <stdio.h>
#include <string.h>

int main() {
    int key = 3; // The shift value for the Caesar cipher
    char message[100]; // The message to be encrypted/decrypted
    printf("Enter a message to encrypt or decrypt: ");
    fgets(message, 100, stdin); // Get input from the user
    int length = strlen(message); // Get the length of the message
    char encrypted[length]; // An array to hold the encrypted message
    char decrypted[length]; // An array to hold the decrypted message
    int i;
    for (i = 0; i < length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (message[i] + key - 'a') % 26 + 'a'; // Encrypt lower-case letters
            decrypted[i] = (encrypted[i] - key - 'a' + 26) % 26 + 'a'; // Decrypt the encrypted message
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (message[i] + key - 'A') % 26 + 'A'; // Encrypt upper-case letters
            decrypted[i] = (encrypted[i] -key - 'A' + 26) % 26 + 'A'; // Decrypt the encrypted message
        }
        else {
            encrypted[i] = message[i]; // Copy non-alphabetic characters as is
            decrypted[i] = message[i];
        }
    }
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);
    return 0;
}
