#include <stdlib.h>

/* Monoalphabetic substitution cipher */
char map[] = {'\x40', '\xbd', '\x0d', '\xc3', '\x37', '\x61', '\x8c', '\x12', '\x72', '\x88', '\x8f', '\x18', '\x5d', '\x4a', '\xb8', '\xcf', '\xd5', '\x0b', '\x7e', '\xc7', '\x5c', '\xc8', '\xd2', '\xdc', '\x66', '\xd1', '\x29', '\x6a', '\x3a', '\x11', '\x01', '\x19', '\x31', '\xa2', '\x4b', '\x2e', '\xe8', '\xca', '\xbf', '\x59', '\xa4', '\xf3', '\x90', '\x15', '\x3e', '\xd4', '\x7b', '\xe5', '\xfc', '\x46', '\xe6', '\x48', '\x1a', '\x16', '\xda', '\xa3', '\xeb', '\x7f', '\x64', '\x14', '\x2f', '\x22', '\xce', '\x08', '\x70', '\x8b', '\xd9', '\x6c', '\x1b', '\xfa', '\x97', '\x0c', '\x1e', '\xaa', '\x6f', '\x02', '\x7d', '\xd6', '\x9a', '\x4c', '\x3f', '\x51', '\x85', '\x44', '\x20', '\xdd', '\xcb', '\xbb', '\x84', '\x17', '\xf1', '\xc0', '\x8d', '\xb2', '\x10', '\xe4', '\xc9', '\xe7', '\xf5', '\xfd', '\x28', '\x13', '\x5a', '\x2b', '\xa9', '\xaf', '\x8a', '\xea', '\x7a', '\x49', '\x4e', '\x24', '\x69', '\x68', '\x50', '\xa8', '\x58', '\x0e', '\xb9', '\x7c', '\x94', '\xe9', '\x2d', '\xc2', '\x2a', '\x6e', '\x25', '\x9c', '\xb1', '\x3b', '\x4f', '\x4d', '\xf2', '\x34', '\x35', '\x79', '\x04', '\x57', '\x71', '\x09', '\xee', '\x8e', '\xa1', '\x63', '\xe0', '\xdb', '\x03', '\x53', '\x55', '\xd7', '\x1c', '\xf0', '\x33', '\x32', '\x95', '\xac', '\x39', '\xa5', '\x91', '\x86', '\xad', '\x30', '\xc6', '\xc5', '\xf9', '\x6d', '\x99', '\x42', '\x0a', '\xe2', '\x60', '\xf8', '\xd3', '\x1f', '\x36', '\x2c', '\xb3', '\x80', '\x96', '\xf6', '\x47', '\xe3', '\x23', '\xe1', '\x5b', '\xba', '\xd0', '\x65', '\xed', '\x75', '\xbc', '\xae', '\x9f', '\x00', '\x67', '\x92', '\x73', '\x62', '\xfb', '\x26', '\x9b', '\x06', '\xde', '\x0f', '\x54', '\xb0', '\x81', '\x45', '\xb6', '\xab', '\xdf', '\xbe', '\x74', '\x76', '\x9e', '\xfe', '\x1d', '\xa7', '\x07', '\x56', '\xb5', '\x38', '\x52', '\xc4', '\x5f', '\x05', '\x9d', '\xef', '\x3d', '\x5e', '\x98', '\xb4', '\x77', '\x83', '\x6b', '\x87', '\xcd', '\xa6', '\x78', '\x41', '\xf7', '\x3c', '\x27', '\x43', '\xa0', '\xd8', '\x21', '\x93', '\xcc', '\xc1', '\xf4', '\xec', '\xb7', '\x82', '\x89', '\xff'};

void __attribute__ ((noinline)) encode(char *guess, long unsigned int guess_len, char **encoded_guess_out, long unsigned int *encoded_guess_len_out)
{
    long unsigned int encoded_guess_len = guess_len;
    char *encoded_guess = malloc(encoded_guess_len * sizeof (char));

    long unsigned int i;
    for (i = 0; i < guess_len; i++) {
        encoded_guess[i] = (char)map[(int)guess[i]];
    }

    *encoded_guess_out = encoded_guess;
    *encoded_guess_len_out = encoded_guess_len;

}
