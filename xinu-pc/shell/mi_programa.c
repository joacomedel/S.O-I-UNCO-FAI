#include <xinu.h>
void repetirA(void), repetirB(void);

mi_programa() {
printf("Inicio programa 1 repetidamente va a imprimir A\n");
resume(create(repetirA,1024,20,"repetir A",0));
printf("Inicio programa 2 repetidamente va a imprimir B\n");
resume(create(repetirB,1024,20,"repetir B",0));
}
void repetirA(void){
    while (1)
    {
        putc(CONSOLE, 'A');
        sleep(20);
    }
    printf("\n"); 
}
void repetirB(void){
    while (1)
    {
        putc(CONSOLE, 'B');
        sleep(20);
    }
    printf("\n"); 
}