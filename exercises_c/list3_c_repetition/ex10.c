#include<stdio.h>

int main()
{
    int n, more18 = 0, less18 = 0;
    printf("Enter a number of ages to be insert: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        int age;
        printf("Enter the %d age: ", i);
        scanf("%d", &age);

        if(age >= 18)
        {
            more18++;
        }
        else
        {
            less18++;
        }
    }
    printf("The number of people more than 18 years old is %d and the number of people less than 18 years old is %d", more18, less18);

    return 0;
}