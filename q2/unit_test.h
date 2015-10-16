#ifndef UNIT_TEST
#define UNIT_TEST

typedef char (*test_function)(char *, char);
void unit_test(char (*fptr)(char *, char), char result, char *str, char c);

#endif


