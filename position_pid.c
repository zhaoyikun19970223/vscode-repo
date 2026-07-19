#include<stdio.h>
#include<stdlib.h>
#include "position_pid.h"

//唯一定义实体
struct position_pid pid1;

void PID_init1()
{
    printf("PID_init begin \n");
    pid1.SetSpeed=0.0;
    pid1.ActualSpeed=0.0;
    pid1.err=0.0;
    pid1.err_last=0.0;
    pid1.voltage=0.0;
    pid1.integral=0.0;
    pid1.Kp=0.2;
    pid1.Ki=0.015;
    pid1.Kd=0.2;
    printf("PID_init end \n");
}

float PID_realize1(float speed)
{
    pid1.SetSpeed=speed;
    pid1.err=pid1.SetSpeed-pid1.ActualSpeed;
    pid1.integral+=pid1.err;
    pid1.voltage=pid1.Kp*pid1.err+pid1.Ki*pid1.integral+pid1.Kd*(pid1.err-pid1.err_last);
    pid1.err_last=pid1.err;
    pid1.ActualSpeed=pid1.voltage*1.0;
    return pid1.ActualSpeed;
}
