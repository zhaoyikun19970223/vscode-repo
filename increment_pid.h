#include<stdio.h>
#include<stdlib.h>

struct increment_pid
{
    float SetSpeed;            //定义设定值
    float ActualSpeed;        //定义实际值
    float err;                //定义偏差值
    float err_next;            //定义上一个偏差值
    float err_last;            //定义最上前的偏差值
    float Kp,Ki,Kd;            //定义比例、积分、微分系数
};

// 仅声明
extern struct increment_pid pid2;

void PID_init2();

float PID_realize2(float speed);

