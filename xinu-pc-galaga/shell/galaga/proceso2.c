#include <xinu.h>

int32 proceso2(void){
    int32 msg;
    int32 vidas = 3;
    int32 puntaje = 0;
    char cadena[30];
    while (1)
    {
        printf("ARRANCA");
        sprintf(cadena,"Vidas : %d Puntaje : %d",vidas,puntaje);
        print_text_on_vga(300, 40, cadena);
        msg = receive();
        printf("RECIBE MENSAJE");
        if(msg == -1){
            vidas--;
        }else{
            puntaje++;
        }
    }
    

}