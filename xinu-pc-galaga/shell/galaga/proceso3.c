#include <xinu.h>

extern int galaga();
extern int32 proceso2(void);
extern int32 proceso4(void);
pid32 pid1;
pid32 pid2;
pid32 pid3;
pid32 pid4;
sid32 semCerro;

shellcmd proceso3(){
    printf("arranca galaga");
    semCerro = semcreate(0);
    pid1 = create(galaga,1024,20,"proceso1",0);
    pid2 = create(proceso2,1024,20,"proceso2",0);
    pid3 = currpid;
    pid4 = create(proceso4,1024,20,"proceso4",0);
    resume(pid4);
    resume(pid2);
    resume(pid1);
    

    receive(); //viene de proceso 1
    kill(pid1);
    kill(pid2);
    wait(semCerro); //Tengo q usar semaforos porque se me pueden
    //desincronizar y perder el send del proceso 4 ;
    //Solo cierro el proceso 4 cuando me aviso q cerro el device 
    kill(pid4);
    printf("termino Proceso 3");
    
    
}