#include <stdio.h>
#include <stdlib.h>

struct Student{
    float grade1, grade2, grade3;
};
int main(){
    int n;
    float biggestavg = 0, sum = 0, avg = 0;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    int vector[n];
    struct Student *s;
    s = (struct Student *)malloc(n * sizeof(struct Student));
    for(int i = 0; i < n; i++){
        printf("Enter the grade 1 of student %d: ", i + 1);
        scanf("%f", &s[i].grade1);
        printf("Enter the grade 2 of student %d: ", i + 1);
        scanf("%f", &s[i].grade2);
        printf("Enter the grade 3 of student %d: ", i + 1);
        scanf("%f", &s[i].grade3);
        avg = (s[i].grade1 + s[i].grade2 + s[i].grade3) / 3;
        if(avg > biggestavg){
            biggestavg = avg;
        }
    }
    for(int i = 0; i < n; i++){
        avg = (s[i].grade1 + s[i].grade2 + s[i].grade3) / 3;
        if(avg == biggestavg){
            printf("The student with the biggest average is student %d\n", i + 1);
        }
    }
    free(s);
    return 0;
}