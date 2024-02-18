#include <stdio.h>
void encrypt(char* message, int key) {
    int i = 0;
    while (message[i] != '\0') {
        // Shift the character by the key
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        }
        i++;
    }
}
// Function to decrypt a string using a Caesar cipher
void decrypt(char* message, int key) {
    // Decryption is just the reverse of encryption
    encrypt(message, 26 - key);
}

int main() {
    char message[1000];
    int key;
    int choice;
    printf("Chose 1 for encryption and decryption:");
    scanf("%d", &choice);

    printf("Enter a message to encrypt:\n ");
    fgets(message, 1000, stdin);

    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

}
