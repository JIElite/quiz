#include <stdio.h>
#include <string.h>

#include "unit_test.h"


void unit_test(test_function fptr, char result, char str[], char c)
{

    printf("Pass Test: %c, Input: [", result);

    for(int i = 0; i < strlen(str); i++) {
        if(str[i+1] == '\0') printf("%c", str[i]);
        else printf("%c, ", str[i]);
    }

    printf("], %c. --- ", c);
    char your_result = fptr(str, c);

    if (result == your_result) printf("Pass!\n");
    else printf("Not Pass!, Your result: %c\n", your_result);
}


