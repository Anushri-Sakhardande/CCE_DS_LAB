#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[40];
    int rollno;
    float grade;
    char branch[40];
};

int main()
{
    FILE *ptr;
    ptr = fopen("C:\Users\anush\OneDrive\Documents\ACADEMICS\SEM3\DS LAB\LAB_2\additional\records.txt","w");

    return 0;
}
