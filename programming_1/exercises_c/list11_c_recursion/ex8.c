#include <stdio.h>
#include <string.h>

int f_palindrome(char *str, int start, int end)
{
    if (start >= end) {
        return 1;
    }
    if (str[start] != str[end]) {
        return 0;
    }
    return f_palindrome(str, start + 1, end - 1);
}

void main()
{
    char str[10];
    printf("Enter a string");
    gets(str)
    int n = strlen(str);

    int result = f_palindrome(str, 0, n - 1);
    if (result) {
        printf("The string is a palindrome\n");
    }
    else {
        printf("The string is not a palindrome\n");
    }
}