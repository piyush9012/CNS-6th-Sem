
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int modExp(int base, int exponent, int mod) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exponent = exponent / 2;
    }
    return result;
}

void generateKeys(int p, int q, int *n, int *e, int *d) {
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    *e = 2;
    while (*e < phi) {
        if (gcd(*e, phi) == 1) break;
        else (*e)++;
    }
    int k = 2;
    while (1) {
        *d = (1 + (k * phi)) / *e;
        if ((*d * *e) % phi == 1) break;
        else k++;
    }
}

void encrypt(char *message, int e, int n, int *encrypted) {
    int i;
    for (i = 0; message[i] != '\0'; ++i) {
        encrypted[i] = modExp(message[i], e, n);
    }
    encrypted[i] = -1;
}

void decrypt(int *encrypted, int d, int n, char *decrypted) {
    int i;
    for (i = 0; encrypted[i] != -1; ++i) {
        decrypted[i] = modExp(encrypted[i], d, n);
    }
    decrypted[i] = '\0';
}

int main() {
    int p, q, e;
    int n, d;
    char message[100];
    int encrypted[100];
    char decrypted[100];

    printf("Enter the first prime number (p): ");
    scanf("%d", &p);
    printf("Enter the second prime number (q): ");
    scanf("%d", &q);
    printf("Enter the public exponent (e): ");
    scanf("%d", &e);

    generateKeys(p, q, &n, &e, &d);

    printf("Enter the message to be encrypted: ");
    scanf(" %[^\n]", message);

    encrypt(message, e, n, encrypted);
    printf("Encrypted message: ");
    for (int i = 0; encrypted[i] != -1; ++i) {
        printf("%d ", encrypted[i]);
    }
    printf("\n");

    decrypt(encrypted, d, n, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}
