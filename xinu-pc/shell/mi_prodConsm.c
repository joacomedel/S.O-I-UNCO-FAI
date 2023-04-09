#include <xinu.h>

void consumidor();
void productor();
int32 n = 0;
sid32 semaforo;
mtx32 mutex2;
shellcmd mi_prodConsm(){
    semaforo = semcreate(0);
    mutex2 = mutex_init();
    resume(create(consumidor,1024,20,"consumidor",0));
    resume(create(productor,1024,20,"productor",0));
}
void productor(){
    mutex_lock(mutex2);
    int32 i;
    for (i = 1; i < 2000; i++)
    {
        n++; 
    }
    signal(semaforo);
    mutex_unlock(mutex2);
}
void consumidor(){
    wait(semaforo);
    mutex_lock(mutex2);
    int32 i;
    for (i = 1; i <= 2000; i++)
    {
        printf("El valor de n es %d \n" ,n);
    }
    mutex_unlock(mutex2);
    signal(semaforo);
}