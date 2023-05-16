#include <xinu.h>

extern int galaga();
extern int32 proceso2(void);
pid32 pid1;
pid32 pid2;
pid32 pid3;

shellcmd proceso3(){
    pid1 = create(galaga,1024,20,"proceso1",0);
    pid2 = create(proceso2,1024,20,"proceso2",0);
    pid3 = currpid;
    resume(pid1);
    resume(pid2);

    receive();
    kill(pid1);
    kill(pid2);
    
}