#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encode.h"

int __attribute__ ((noinline)) check_encoded_guess(char *encoded_guess, long unsigned int encoded_guess_len);

/*
 * Encode the guess and compare it against the encoded flag
 * This should should return 1 if and only if guess is the flag
 *
 * */
int __attribute__ ((noinline)) check_flag(char *guess)
{
    int r;
    long unsigned int guess_len = strlen(guess);
    char *encoded_guess;
    long unsigned int encoded_guess_len;
    encode(guess, guess_len, &encoded_guess, &encoded_guess_len);
    r = check_encoded_guess(encoded_guess, encoded_guess_len);
    free(encoded_guess);
    return r == 0;
   
}

/*
 * Compare the bytes of the encoded guess and encoded flag
 * It will return  0 if all bytes are equal
 * It will return -1 if any bytes are different
 */
int __attribute__ ((noinline)) check_encoded_guess(char *encoded_guess, long unsigned int encoded_guess_len)
{
    long unsigned int i;
    if (encoded_guess_len != ENCODED_FLAG_LEN) {
        return -1;
    }
    for (i = 0; i < ENCODED_FLAG_LEN; i++) {
        if (encoded_guess[i] != ENCODED_FLAG[i]) {
            return -1;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    char *flag_guess;
    if (argc < 2) {
        fprintf(stderr, "usage: %s guess\n", argv[0]);
        return EXIT_FAILURE;
    }
    flag_guess = argv[1];
    if (check_flag(flag_guess)) {
        printf("Correct: %s\n", flag_guess);
    } else {
        printf("Incorrect\n");
    }
    return EXIT_SUCCESS;
}
