#include <xinu.h>
unsigned char tecla_actual;
unsigned char teclas[3];

#define BUTTON_A	0x24
#define BUTTON_RIGHT	0x1f
#define BUTTON_LEFT	0x1e

#define BUTTON_A_REL	0xa4 
#define BUTTON_RIGHT_REL	0x9f
#define BUTTON_LEFT_REL	0x9e

int32 proceso4 (void) {
    open(KEYBOARD,0,0);
    while (1)
    {
        tecla_actual = getc(KEYBOARD);
        if (tecla_actual == 0x01)
        {
            close(KEYBOARD);
        }
        char cadena[20];
        sprintf(cadena , "%x" ,tecla_actual);
        print_text_on_vga(10, 300, cadena);
        switch (tecla_actual)
        {
        case BUTTON_A : teclas[0] = 1; break;
        case BUTTON_LEFT : teclas[1] = 1; break;
        case BUTTON_RIGHT : teclas[2] = 1; break;
        case BUTTON_A_REL : teclas[0] = 0; break;
        case BUTTON_LEFT_REL : teclas[1] = 0; break;
        case BUTTON_RIGHT_REL : teclas[2] = 0; break;
        }
        
    }
    

}