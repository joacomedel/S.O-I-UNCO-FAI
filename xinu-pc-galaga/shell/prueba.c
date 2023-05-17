#include <xinu.h>
#include <keyboard.h>
shellcmd prueba(){
extern struct StBuffer stbuffer;
while (1)
{
    /*char cadena [20];
    open(KEYBOARD,0,0);
    sprintf(cadena,"TECLA : %d",getc(KEYBOARD));
    close(KEYBOARD);
    print_text_on_vga(10, 300, cadena);
    printf("andando");*/


    //printf("%d",kbdgetc());

    open(KEYBOARD,0,0);
    printf("%d",getc(KEYBOARD));
    close(KEYBOARD);
}
}