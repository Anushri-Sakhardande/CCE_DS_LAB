#include "charstack_attempt.h"
#include <string.h>

int pmain()
{
    char palin[30];
    element e;
    printf("Enter a word:");
    scanf("%s",palin);
    for(i=0;i<strlen(palin);i++)
    {
        e.key = palin[i];
        charPush(e);
    }
    for(i=0;i<strlen(palin);i++)
    {
        e = charPop();
        if(e.key != palin[i])
        {
            printf("Not palindrome");
            return 0;
        }
    }
    printf("Palindrome");
    return 0;
}
