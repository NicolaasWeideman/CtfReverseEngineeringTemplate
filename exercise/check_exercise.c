#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void __attribute__ ((noinline)) encode(char *flag, long unsigned int flag_len, char **encoded_flag_out, long unsigned int *encoded_flag_len_out);
int compare(char *str1, long unsigned int str1_len, char *str2, long unsigned int str2_len)
{
    long unsigned int i;
    char g, f;
    int r = 0;
    i = 0;
    while (i < str1_len || i < str2_len) {
        if (i < str1_len) {
            g = str1[i];
        } else {
            g = 0;
        }
        if (i < str2_len) {
            f = str2[i];
        } else {
            f = 0;
        }
        r |= (g ^ f);
        i++;
    }
    return r;

}

void print_bytes(char *buf, long unsigned int buf_len)
{
    long unsigned int i;
    for (i = 0; i < buf_len; i++) {
        printf("\\x%02x", buf[i]);
    }
}

void check(char *str, char *correct)
{
    long unsigned int str_len = strlen(str);
    long unsigned int correct_len = strlen(correct);
    char *encoded_str;
    long unsigned int encoded_str_len;
    encode(str, str_len, &encoded_str, &encoded_str_len);
    if (compare(encoded_str, encoded_str_len, correct, correct_len) != 0) {
        printf("ERROR with string: %s\n", str);
        printf("  Encoded should be:  %s (", correct);
        print_bytes(correct, correct_len);
        printf(")\n");
        printf("  But instead, it is: %s (", encoded_str);
        print_bytes(encoded_str, encoded_str_len);
        printf(")\n");
    } else {
        printf("CORRECT: %s\n", str);
    }
}


int main(void)
{
    check("asdf", "nfqs");
    check("FLAG{check}", "SYNT{purpx}");
    check("123456", "123456");
    check("ThIs_iS_tHe_FlAg", "GuVf_vF_gUr_SyNt");
    return EXIT_SUCCESS;

}
