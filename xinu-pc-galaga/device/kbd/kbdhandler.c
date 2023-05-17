/* source: https://forum.osdev.org/viewtopic.php?t=10247 */

/* kbdhandler.c - kbdhandler */

#include <xinu.h>
#include <keyboard.h>

extern struct StBuffer stbuffer;

//unsigned char tecla_actual;

unsigned char get_scancode()
{
    unsigned char inputdata;
    inputdata = inportb(KEYBOARD_DATAREG);
    return inputdata;
}


/*------------------------------------------------------------------------
 *  kbdhandler  -  Handle an interrupt for the keyboard device
 *------------------------------------------------------------------------
 */
void kbdhandler(void)
{
	char t[80];
	unsigned char scancode; 
	unsigned int shift_key = 0;
	int i = 10;

	scancode = get_scancode();
	if((stbuffer.finIndex+1)%KEYBOARD_BFSIZE == stbuffer.index){
        //SI ESTA LLENA
    }else{
        //SI TIENE ESPACIO
        stbuffer.buffer[stbuffer.finIndex] = scancode;
        stbuffer.finIndex = (stbuffer.finIndex+1)%KEYBOARD_BFSIZE;
        signal(stbuffer.semInBf);
    }
	//tecla_actual = scancode;
	

	if(scancode == 0x2A) {
		shift_key = 1;//Shift key is pressed
	} else if(scancode & 0xAA) {
		shift_key = 0;//Shift Key is not pressed
	} else {          
		if (scancode & 0x80) {
			int shiftaltctrl = 1;//Put anything to see what special keys were pressed
		} else {  
		}     
	}
}

