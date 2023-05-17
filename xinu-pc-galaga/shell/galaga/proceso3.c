#include <xinu.h>

extern int galaga();
extern int32 proceso2(void);
extern int32 proceso4(void);
pid32 pid1;
pid32 pid2;
pid32 pid3;
pid32 pid4;

shellcmd proceso3(){
    pid1 = create(galaga,1024,20,"proceso1",0);
    pid2 = create(proceso2,1024,20,"proceso2",0);
    pid3 = currpid;
    pid4 = create(proceso4,1024,20,"proceso4",0);
    resume(pid1);
    resume(pid2);
    resume(pid4);

    receive();
    kill(pid1);
    kill(pid2);
    kill(pid4);
    
}