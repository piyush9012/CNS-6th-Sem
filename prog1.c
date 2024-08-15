#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256
#define KEY 3

void encrypt(char *message) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char offset = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - offset + KEY) % 26 + offset;
        }
    }
} 
void decrypt(char *message) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char offset = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - offset - KEY + 26) % 26 + offset;
        }
    }
}

int main() {
    char message[MAX_LEN];

    printf("Enter the message to encrypt: ");
    fgets(message, MAX_LEN, stdin);
    message[strcspn(message, "\n")] = '\0';

    char encrypted[MAX_LEN];
    strcpy(encrypted, message);

    encrypt(encrypted);
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted);

    decrypt(encrypted);
    printf("Decrypted message: %s\n", encrypted);
    return 0;
}
