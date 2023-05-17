#include <xinu.h>
#include <keyboard.h>
extern struct StBuffer stbuffer;
extern pid32 pidKbd;
unsigned char kbdgetc(){
    unsigned char c = SYSERR;
    if(pidKbd = getpid()){
    wait(stbuffer.semInBf);
    //wait(stbuffer.semBin);
    c = stbuffer.buffer[stbuffer.index];
    stbuffer.buffer[stbuffer.index] = 0;
    stbuffer.index = (stbuffer.index+1)%KEYBOARD_BFSIZE;
    //signal(stbuffer.semBin);
    }
    return c;
    
}