#include <stdio.h>
struct student
{
    int roll;
    char firstName[50];
    double cgpa;
    char adress[100];
};
int main()
{
    struct student s[70];
    int i, n;
    printf("How many student in class :");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("\nEnter information of students%d:\n", i);
        printf("Enter roll: ");
        scanf("%d", &s[i].roll);
        printf("Enter first name: ");
        scanf("%s", s[i].firstName);
        printf("Enter CGPA: ");
        scanf("%lf", &s[i].cgpa);
        printf("Enter adress: ");
        scanf("%s", s[i].adress);
        printf("\n");
    }
    printf("\nDisplaying Information:\n\n");
    for (i = 1; i <= n; i++)
    {
        printf("Information of student%d:\n", i);
        printf("Roll: %d\n", s[i].roll);
        printf("First name: ");
        puts(s[i].firstName);
        printf("CGPA: %.2lf\n", s[i].cgpa);
        printf("Adress: ");
        puts(s[i].adress);
        printf("\n");
    }
    return 0;
}