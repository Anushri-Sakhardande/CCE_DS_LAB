// STRING HANDLING
#include <stdio.h>
#include <stdlib.h>

// Function for length of string
int length(char str[])
{
    int len;
    for (len = 0; str[len] != '\0'; len++)
        ;
    return len;
}

// Function for string concatenation
void concatenate(char str1[], char str2[])
{
    int i;
    int len1 = length(str1);
    int len2 = length(str2);
    for (i = 0; i < len2; i++)
    {
        str1[i + len1] = str2[i];
    }
    str1[len1+len2]='\0';
}

// Function for string comparison
int compare(char str1[], char str2[])
{
    int i, difference = 0;
    for (i = 0; str1[i] != '\0' &&  str2[i] != '\0'; i++)
    {
        if (str1[i] != str2[i])
        {
            difference = str1[i] - str2[i];
            break;
        }
    }
    return difference;
}

// Function for string insertion
void insert(char str1[], char str2[], int location)
{
    int i;
    int len1 = length(str1);
    int len2 = length(str2);
    for (i = len1 - 1; i >= location; i--)
    {
        str1[i + len2] = str1[i];
    }
    for (i = 0; i < len2; i++)
    {
        str1[location + i] = str2[i];
    }
    str1[len1+len2]='\0';
}

// Function for string deletion
int deletion(char str1[], char str2[])
{
    int i, j = 0, location, found = 0;
    int len1 = length(str1);
    int len2 = length(str2);
    for (i = 0; i <= len1 - len2; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (str1[i + j] != str2[j])
            {
                break;
            }
        }
        if (j == len2)
        {
            location = i;
            found = 1;
            break;
        }
    }
    //printf("%d%d", found, location);
    if (found == 1)
    {
        for (i = 0; i <= len1-location-len2-1; i++)
        {
            str1[location + i] = str1[location + len2 + i];
        }
        str1[len1-len2]='\0';
    }
    else
    {
        printf("Not Present");
    }
    return found;
}

int main()
{
    char str1[30];
    char str2[30];
    int loc_insert;
    char choice;

    //choose the string handling function required
    printf("Enter l for length\n");
    printf("Enter c for concatenation\n");
    printf("Enter p for compare\n");
    printf("Enter i for insert\n");
    printf("Enter d for deletion\n");
    scanf("%c",&choice);
    
    // Input the required values
    printf("Enter a string:");
    scanf(" %[^\n]s", str1);
    
    switch(choice){
        case 'l':
                printf("Length of the string is:%d",length(str1));
                break;
        case 'c':
                printf("Enter a string");
                scanf("%s", str2);
                concatenate(str1,str2);
                printf("Concatenated strings:%s",str1);
                break;
        case 'p':
                printf("Enter a string");
                scanf("%s", str2);
                printf("String Comparison:%d",compare(str1,str2));
                break;
        case 'i':
                printf("Enter a string");
                scanf("%s", str2);
                printf("Enter location to insert string");
                scanf("%d", &loc_insert);
                insert(str1,str2,loc_insert);
                printf("Inserted string:%s",str1);
                break;
        case 'd':
                printf("Enter a string");
                scanf("%s", str2);
                int found = deletion(str1,str2);
                if(found)
                {
                    printf("Deleted string:%s",str1);
                }
                break;
        default:
                printf("Incorrect Input");
    }
    
    return 0;
}