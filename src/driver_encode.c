#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encode.h"

int main(int argc, char *argv[])
{
    unsigned long i;
    char *flag;
    long unsigned int flag_len;
    char *encoded_flag;
    long unsigned int encoded_flag_len;
    if (argc < 2) {
        fprintf(stderr, "usage: %s flag\n", argv[0]);
        return EXIT_FAILURE;
    }
    flag = argv[1];
    flag_len = strlen(flag);
    encode(flag, flag_len, &encoded_flag, &encoded_flag_len);
    printf("-DENCODED_FLAG=\"");
    for (i = 0; i < encoded_flag_len; i++) {
        printf("\\x%02x", (unsigned char)encoded_flag[i]);
    }
    printf("\" -DENCODED_FLAG_LEN=%lu", encoded_flag_len);
    return EXIT_SUCCESS;
}
