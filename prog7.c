#include <stdio.h>
#include <math.h>

long long int power(long long int a, long long int b, long long int P) {
    if (b == 1) return a;
    else return (((long long int)pow(a, b)) % P);
}

int main() { 
    long long int P, G, x, a, b, y, ka, kb;

    printf("Enter the value of P (prime number): ");
    scanf("%lld", &P);

    printf("Enter the value of G (primitive root for P): ");
    scanf("%lld", &G);

    printf("Enter the private key for Alice (a): ");
    scanf("%lld", &a);

    printf("Enter the private key for Bob (b): ");
    scanf("%lld", &b);

    printf("\n");

    printf("The value of P : %lld\n", P);
    printf("The value of G : %lld\n\n", G);
    printf("The private key a for Alice : %lld\n", a);
    printf("The private key b for Bob : %lld\n\n", b);

    x = power(G, a, P);
    y = power(G, b, P);

    ka = power(y, a, P);
    kb = power(x, b, P);

    printf("Secret key for Alice: %lld\n", ka);
    printf("Secret key for Bob: %lld\n", kb);

    return 0;
}
