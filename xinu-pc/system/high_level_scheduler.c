#include <xinu.h>
    int32 pidHlsh;
    int32 prioHlsh;
    void funct(int32 pid_p , int32 ms_p);

devcall high_level_scheduler (int32 pid_a , int32 ms_a ,int32 pid_b , int32 ms_b ,int32 pid_c , int32 ms_c){

    pidHlsh = getpid();
    prioHlsh = getprio(pidHlsh);
    while (1)
    {   
        funct(pid_a,ms_a);
        funct(pid_b,ms_b);
        funct(pid_c,ms_c);
    }
    
    
}
void funct(int32 pid_p , int32 ms_p){
        int32 prio_a = getprio(pid_p);
        chprio(pid_p , prioHlsh-1);
        sleepms(ms_p);
        chprio(pid_p,prio_a);
    }
