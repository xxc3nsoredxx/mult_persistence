#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gmp.h>

#define BASE 10

unsigned int persistence (const mpz_t n) {
    mpz_t step;
    mpz_t mult;
    char *str = NULL;
    char temp[] = {
        0x00, 0x00
    };
    unsigned int count = 0;

    mpz_init_set_str(step, "1", BASE);
    mpz_init(mult);
    str = mpz_get_str(str, BASE, n);

    printf("%s\n", str);
    if (strlen(str) > 1) {
        size_t cx;
        for (cx = 0; cx < strlen(str); cx++) {
            strncpy(temp, (str + cx), 1);
            mpz_set_str(mult, temp, BASE);
            mpz_mul(step, step, mult);
        }
        count = 1 + persistence(step);
    }

    mpz_clear(step);
    return count;
}

int main () {
    mpz_t in;
    unsigned int steps;

    mpz_init(in);

    while (1) {
        printf("Enter number (negative number to quit): ");
        gmp_scanf(" %Zd", in);

        if (mpz_sgn(in) < 0) {
            break;
        }

        steps = persistence(in);
        printf("Steps: %u\n", steps);
    }

    mpz_clear(in);
    return 0;
}
