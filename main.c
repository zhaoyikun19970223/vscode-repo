#include<stdio.h>
#include<stdlib.h>
#include "position_pid.h"
#include "increment_pid.h"

int main(void)
{
    printf("Position PID begin! \n");
    PID_init1();
    int count1=0;
    while(count1<1000)
    {
        float speed1=PID_realize1(200.0);
        printf("%f\n",speed1);
        count1++;
    }

    printf("---------------------------\n");

    printf("Increment PID begin! \n");
    PID_init2();
    int count2=0;
    while(count2<1000)
    {
        float speed2=PID_realize2(200.0);
        printf("%f\n",speed2);
        count2++;
    }

    return 0;
}

