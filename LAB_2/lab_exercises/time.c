//TIME

#include <stdio.h>
#include <stdlib.h>

struct time
{
    int hour;
    int minute;
    int second;
};

//function to add times
struct time addition(struct time time1,struct time time2)
{
    struct time added;
    int addSeconds;
    addSeconds = (time1.hour+time2.hour)*3600+(time1.minute+time2.minute)*60+(time1.second+time2.second);
    added.hour = addSeconds/3600;
    added.minute = (addSeconds%3600)/60;
    added.second = (addSeconds%60);
    return added;
}

//function to subtract times
struct time difference(struct time time1,struct time time2)
{
    struct time diff;
    int diffSeconds;
    diffSeconds = (time1.hour-time2.hour)*3600+(time1.minute-time2.minute)*60+(time1.second-time2.second);
    diff.hour = diffSeconds/3600;
    diff.minute = (diffSeconds%3600)/60;
    diff.second = (diffSeconds%60);
    return diff;
}

//read the time
void time_read(struct time *t)
{
    printf("Enter the time in hour minutes seconds format\n");
    scanf("%d",&t->hour);
    scanf("%d",&t->minute);
    scanf("%d",&t->second);
}

//display the time
void time_display(struct time t)
{
    printf("%d:%d:%d\n",t.hour,t.minute,t.second);
}

int main()
{
    struct time time1,time2;
    time_read(&time1);
    time_read(&time2);
    printf("Time 1\n");
    time_display(time1);
    printf("Time 2\n");
    time_display(time2);
    struct time add = addition(time1,time2);
    struct time diff = difference(time1,time2);
    printf("The sum of times is\n");
    time_display(add);
    printf("The difference of times is\n");
    time_display(diff);
}
