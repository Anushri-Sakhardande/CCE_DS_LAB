//TIME

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int hour;
    int min;
    int sec;
}time;

//function to add times
time addition(time t1, time t2)
{
     time added;
    int addSeconds;
    addSeconds = (t1.hour+t2.hour)*3600+(t1.min+t2.min)*60+(t1.sec+t2.sec);
    added.hour = addSeconds/3600;
    added.min = (addSeconds%3600)/60;
    added.sec = (addSeconds%60);
    return added;
}

//function to subtract times
 time difference( time t1, time t2)
{
     time diff;
    int diffSeconds;
    diffSeconds = abs((t1.hour-t2.hour)*3600+(t1.min-t2.min)*60+(t1.sec-t2.sec));
    diff.hour = diffSeconds/3600;
    diff.min = (diffSeconds%3600)/60;
    diff.sec = (diffSeconds%60);
    return diff;
}

//read the time
void time_read( time *t)
{
    printf("Enter the time in hour mins seconds format\n");
    scanf("%d",&t->hour);
    scanf("%d",&t->min);
    scanf("%d",&t->sec);
}

//display the time
void time_display( time t)
{
    printf("%d:%d:%d\n",t.hour,t.min,t.sec);
}

int main()
{
     time t1,t2;
    time_read(&t1);
    time_read(&t2);
    printf("Time 1\n");
    time_display(t1);
    printf("Time 2\n");
    time_display(t2);
     time add = addition(t1,t2);
     time diff = difference(t1,t2);
    printf("The sum of times is\n");
    time_display(add);
    printf("The difference of times is\n");
    time_display(diff);
}
