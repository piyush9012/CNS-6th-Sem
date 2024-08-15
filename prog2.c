#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            int offset = toupper(plaintext[i]) - 'A';
            ciphertext[i] = key[offset];
            if (islower(plaintext[i])) {
                ciphertext[i] = tolower(ciphertext[i]);
            }
        }
        else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len] = '\0';
} 

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        if (isalpha(ciphertext[i])) {
            int offset = toupper(ciphertext[i]);
            for (int j = 0; j < 26; j++) {
                if (key[j] == offset) {
                    plaintext[i] = 'A' + j;
                    if (islower(ciphertext[i])) {
                        plaintext[i] = tolower(plaintext[i]);
                    }
                    break;
                }
            }
        }
        else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[len] = '\0';
}

int main()
{
    char plaintext[100];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char ciphertext[100];
    char decrypted[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Plaintext: %s\n", plaintext);

    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
