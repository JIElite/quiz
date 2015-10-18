#include<stdio.h>
#include<string.h>

#include "unit_test.h"

char find_smallest(char *str, char c, char result)
{
    if (*str) {
        if (*str > c) return *str;
        else return find_smallest(str+1, c, result);
    }
    return result;
}


char smallest_char_rev(char str[], char c)
{
    if ( *str != '\0') return find_smallest(str, c, str[0]);
    return *str;
}


int main()
{
    char str[] = "cfjpv";
    char str2[] = "aabceeffffggwzzz";

    unit_test(smallest_char_rev, 'c', str, 'a');
    unit_test(smallest_char_rev, 'f', str, 'c');
    unit_test(smallest_char_rev, 'c', str, 'w');
    unit_test(smallest_char_rev, 'p', str, 'j');
    unit_test(smallest_char_rev, 'c', str, 'v');

    unit_test(smallest_char_rev, 'b', str2, 'a');
    unit_test(smallest_char_rev, 'e', str2, 'd');
    unit_test(smallest_char_rev, 'g', str2, 'f');
    unit_test(smallest_char_rev, 'e', str2, 'c');

    return 0;
}
