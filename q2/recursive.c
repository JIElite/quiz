#include<stdio.h>
#include<string.h>


 char find_smallest(char *str, char c, char result, int i){
    if (str[i] != '\0'){
        if (str[i] == c) {
            while(str[i++] != '\0'){
                if (str[i] > c) {
                    result = str[i];
                    return result;
                }
            }
        }

        return find_smallest(str, c, result, i+1);
    }
    return result;
}


char smallest_char_rev(char str[], char c)
{   
    if ( *str != '\0') return find_smallest(str, c, str[0], 0);
    return *str;
}


void unit_test(char (*fptr)(char *, char), char result, char str[], char c){
    
    printf("Pass Test: %c, Input: [", result);
    
    for(int i = 0; i < strlen(str); i++){
        if(str[i+1] == '\0') printf("%c", str[i]);
        else printf("%c, ", str[i]);
    }
    
    printf("], %c. --- ", c);
    char your_result = fptr(str, c);

    if (result == your_result) printf("Pass!\n");
    else printf("Not Pass!, Your result: %c\n", your_result);
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
    unit_test(smallest_char_rev, 'a', str2, 'd');
    unit_test(smallest_char_rev, 'g', str2, 'f');
    unit_test(smallest_char_rev, 'e', str2, 'c');
  
    return 0;
}
