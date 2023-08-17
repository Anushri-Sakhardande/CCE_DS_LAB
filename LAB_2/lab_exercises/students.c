//STUDENT

#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[30];
    int rollno;
    float grade;
};

//read the information of students
void read(struct student *p,int n)
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
void display(struct student *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Roll no:%d\n",(p+i)->rollno);
        printf("%s\n",(p+i)->name);
        printf("%0.2f\n",(p+i)->grade);
        printf("\n");
    }
}

//sort roll no wise
void sort(struct student *p,int n)
{
    struct student temp;
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

int students_main()
{
    int n;
    struct student list[10],*ptr;
    ptr = list;
    printf("Enter the number of students");
    scanf("%d",&n);
    read(ptr,n);
    sort(ptr,n);
    display(ptr,n);
    return 0;
}
