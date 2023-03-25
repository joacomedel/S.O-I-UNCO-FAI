#include <xinu.h>
void repetirA(void), repetirB(void);

mi_programa() {
int32 pidA = 0;
int32 pidB = 0;
printf("Inicio programa 1 repetidamente va a imprimir A\n");
pidA = create(repetirA,1024,20,"repetir A",0);
resume(pidA);
printf("Inicio programa 2 repetidamente va a imprimir B\n");
pidB = create(repetirB,1024,20,"repetir B",0);
resume(pidB);
sleep(10);
kill(pidA);
kill(pidB);
printf("TERMINO");
}
void repetirA(void){
    while (1)
    {
        putc(CONSOLE, 'A');
        sleep(2);
    }
    printf("\n"); 
}
void repetirB(void){
    while (1)
    {
        putc(CONSOLE, 'B');
        sleep(2);
    }
    printf("\n"); 
}