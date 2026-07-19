#include<stdio.h>
#include<stdlib.h>
#include "increment_pid.h"

//唯一定义实体
struct increment_pid pid2;

void PID_init2()
{
    pid2.SetSpeed=0.0;
    pid2.ActualSpeed=0.0;
    pid2.err=0.0;
    pid2.err_last=0.0;
    pid2.err_next=0.0;
    pid2.Kp=0.2;
    pid2.Ki=0.015;
    pid2.Kd=0.2;
}

float PID_realize2(float speed)
{
    pid2.SetSpeed=speed;
    pid2.err=pid2.SetSpeed-pid2.ActualSpeed;
    float incrementSpeed=pid2.Kp*(pid2.err-pid2.err_next)+pid2.Ki*pid2.err+pid2.Kd*(pid2.err-2*pid2.err_next+pid2.err_last);
    pid2.ActualSpeed+=incrementSpeed;
    pid2.err_last=pid2.err_next;
    pid2.err_next=pid2.err;
    return pid2.ActualSpeed;
}

