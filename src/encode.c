#include <stdlib.h>

void __attribute__ ((noinline)) encode(char *guess, long unsigned int guess_len, char **encoded_guess_out, long unsigned int *encoded_guess_len_out)
{
    long unsigned int encoded_guess_len = guess_len; /* CHANGE THIS */
    char *encoded_guess = malloc(encoded_guess_len * sizeof (char));

    long unsigned int i;
    for (i = 0; i < guess_len; i++) {
        encoded_guess[i] = guess[i]; /* CHANGE THIS */
    }

    *encoded_guess_out = encoded_guess;
    *encoded_guess_len_out = encoded_guess_len;

}
