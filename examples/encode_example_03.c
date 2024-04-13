
#include <stdlib.h>

void __attribute__ ((noinline)) encode(char *guess, long unsigned int guess_len, char **encoded_guess_out, long unsigned int *encoded_guess_len_out)
{
    long unsigned int encoded_guess_len = guess_len;
    char *encoded_guess = malloc(guess_len * sizeof (char));

    long unsigned int i;
    for (i = 0; i < guess_len; i++) {
        encoded_guess[i] = guess[i] ^ 0x42;
    }

    *encoded_guess_out = encoded_guess;
    *encoded_guess_len_out = encoded_guess_len;

}
