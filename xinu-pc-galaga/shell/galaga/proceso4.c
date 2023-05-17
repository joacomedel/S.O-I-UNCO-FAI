#include <xinu.h>
unsigned char tecla_actual;
int32 proceso4 (void) {
    open(KEYBOARD,0,0);
    while (1)
    {
        tecla_actual = getc(KEYBOARD);
        if (tecla_actual == 0x01)
        {
            close(KEYBOARD);
        }
        
    }
    

}