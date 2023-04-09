#include <xinu.h>

void consumidor();
void productor();
int32 n = 0;
shellcmd mi_prodConsm(){
    resume(create(consumidor,1024,20,"consumidor",0));
    resume(create(productor,1024,20,"producotor",0));
    

}
void consumidor(){
    int32 i;
    for (i = 0; i < 2000; i++)
    {
        printf("El valor de n es %d " ,n);
    }

}
void productor(){
    int32 i;
    for (i = 0; i < 2000; i++)
    {
        n++;
    }
}