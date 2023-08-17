//STRING HANDLING
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
char *concatenate(char str1[], char str2[])
{
    int i;
    int len1 = length(str1);
    int len2 = length(str2);
    for (i = 0; i < len2; i++)
    {
        str1[i + len1] = str2[i];
    }
    return str1;
}

// Function for string comparison
int compare(char str1[], char str2[])
{
    int i, difference = 0;
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
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
char *insert(char str1[], char str2[], int location)
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
    return str1;
}

// Function for string deletion
char *deletion(char str1[], char str2[])
{
    int i, j = 0, location, found = 0;
    int len1 = length(str1);
    int len2 = length(str2);
    for (i = 0; i < len1-len2; i++)
    {
        for(j=0; j<len2; j++)
        {
            if(str1[i+j]!=str2[j])
            {
                break;
            }
        }
        if(j==len2)
        {
            location = i;
            found=1;
            break;
        }
    }
    printf("%d%d", found, location);
    if (found == 1)
    {
        for (i = 0; i <= len2; i++)
        {
            str1[location + i] = str1[location + len2 + i];
        }
        str1[location + len2] = '\0';
        return str1;
    }
    else
    {
        return "Not Present";
    }
}

int main()
{
    char str[30];
    char sub[30];
    int loc_insert;
    // Input the required values
    printf("Enter a string");
    scanf("%[^\n]s", str);
    printf("Enter a string");
    scanf("%s", sub);
    printf("Enter location to insert string");
    scanf("%d", &loc_insert);

    // String handling
    printf("Length of the string:%d\n", length(str));
    printf("Joining the strings:%s\n", concatenate(str, sub));
    printf("Comparing the strings:%d\n", compare(str, sub));
    printf("String after insertion:%s\n", insert(str, sub, loc_insert));
    printf("String after deletion:%s\n", deletion(str, sub));
    return 0;
}
