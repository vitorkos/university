#include<stdio.h>

f_bmi(float height, float weight, float bmi)
{
    bmi = weight / (height * height);
}

f_classification(float bmi)
{
    if(bmi < 18.5)
    {
        printf("you are underweight");
    }
    else if(bmi >= 18.5 && bmi < 25)
    {
        printf("you are normal");
    }
    else if(bmi >= 25 && bmi < 30)
    {
        printf("you are overweight");
    }
    else if(bmi >= 30)
    {
        printf("you are obese");
    }
}

int main()
{
    float height, weight, bmi;
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);

    f_bmi(height, weight, bmi);
    f_classification(bmi);

    return 0;
}
