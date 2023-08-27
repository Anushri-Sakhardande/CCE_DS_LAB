//STUDENT

#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[30];
    int rollno;
    float grade;
};
typedef struct student stud;


//read the information of students
void read(stud *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the name,roll no and grade of student %d",i+1);
        scanf("%s",(p+i)->name);
        scanf("%d",&(p+i)->rollno);
        scanf("%f",&(p+i)->grade);
    }
}

//display the sorted information
void display( stud *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Roll no:%d\n",(p+i)->rollno);
        printf("Name:%s\n",(p+i)->name);
        printf("Grade:%0.2f\n",(p+i)->grade);
        printf("\n");
    }
}

//sort roll no wise
void sort(stud *p,int n)
{
    stud temp;
    int i,j,selected;
    for (i = 0; i < n - 1; i++)
    {
        selected = i;
        for (j = i + 1; j < n; j++)
        {
            if ((p+selected)->rollno > (p+j)->rollno)
            {
                selected = j;
            }
        }
        if (selected != i)
        {
            temp = *(p+i);
            *(p+i) = *(p+selected);
            *(p+selected) = temp;
        }
    }
}

int main()
{
    int n;
    stud list[10],*ptr;
    ptr = list;
    printf("Enter the number of students");
    scanf("%d",&n);
    read(ptr,n);
    sort(ptr,n);
    printf("sorted List");
    display(ptr,n);
    return 0;
}
