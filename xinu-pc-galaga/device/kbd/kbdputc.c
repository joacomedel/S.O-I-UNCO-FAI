#include <xinu.h>
#include <keyboard.h>
extern struct StBuffer stbuffer;
extern pid32 pidKbd;
devcall kbdputc(char c){
    if(pidKbd = getpid()){
    //wait(stbuffer.semBin);
    if((stbuffer.finIndex+1)%KEYBOARD_BFSIZE == stbuffer.index){
        //SI ESTA LLENA
    }else{
        //SI TIENE ESPACIO
        stbuffer.buffer[stbuffer.finIndex] = c;
        stbuffer.finIndex = (stbuffer.finIndex+1)%KEYBOARD_BFSIZE;
        signal(stbuffer.semInBf);
    }
    //signal(stbuffer.semBin);
    }
   
}