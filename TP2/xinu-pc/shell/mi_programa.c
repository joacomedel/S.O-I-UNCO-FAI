#include <xinu.h>
void repetirC(char);

shellcmd mi_programa() {
int32 pidA = 0;
int32 pidB = 0;
printf("Inicio programa 1 repetidamente va a imprimir A\n");
pidA = create(repetirC,1024,20,"repetir A",1,'A');
resume(pidA);
printf("Inicio programa 2 repetidamente va a imprimir B\n");
pidB = create(repetirC,1024,20,"repetir B",1,'B');
resume(pidB);
sleep(10);
kill(pidA);
kill(pidB);
printf("TERMINO");
}
void repetirC(char c){
    while (1)
    {
        putc(CONSOLE,c);
        sleep(2);
    }
    printf("\n"); 
}
