#include<stdio.h>
#include<string.h>


char smallest_char(char str[], char c)
{
    for(int i = 0; i < strlen(str); i++){
        /* if the restrict bigger character is found, set result */
        if (str[i] == c){
            while(str[i++] != '\0'){ if (str[i] > c) return str[i]; }
        }
    }
    /* if the restrict bigger character is not found */
    return str[0];
}


void unit_test(char (*fptr)(char *, char), char result, char str[], char c){
    
    printf("Pass Test: %c, Input: [", result);
    
    for(int i = 0; i < strlen(str); i++){
        if(str[i+1] == '\0') { printf("%c", str[i]); }
        else { printf("%c, ", str[i]); }
    }
    
    printf("], %c. --- ", c);

    char your_result = fptr(str, c);
    if (result == your_result) { printf("Pass!\n"); }
    else { printf("Not Pass!, Your result: %c\n", your_result); }

}


int main()
{
    char str[] = "cfjpv";
    char str2[] = "aabceeffffggwzzz";
 
    unit_test(smallest_char, 'c', str, 'a');
    unit_test(smallest_char, 'f', str, 'c');
    unit_test(smallest_char, 'c', str, 'w');
    unit_test(smallest_char, 'p', str, 'j');
    unit_test(smallest_char, 'c', str, 'v');
    
    unit_test(smallest_char, 'b', str2, 'a');
    unit_test(smallest_char, 'a', str2, 'd');
    unit_test(smallest_char, 'g', str2, 'f');
    unit_test(smallest_char, 'e', str2, 'c');
    unit_test(smallest_char, 'a', str2, 'z');


    return 0;
}
