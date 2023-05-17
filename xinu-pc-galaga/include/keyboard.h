
#define inportb(p)      inb(p)
#define outportb(p,v)   outb(p,v)

#define KEYBOARD_DATAREG 0x60  // :Data Register(Read\Write)
#define KEYBOARD_CMDREG 0x64   // :Command Register(Read\Write)
#define KEYBOARD_BFSIZE 10 //Size of keyboard buffer

extern unsigned char kblayout [128];  // { ... } Fill your layout yourself 

struct StBuffer
{
    unsigned char buffer [KEYBOARD_BFSIZE];
    int32 index;
    int32 finIndex;
    sid32 semInBf;
    //sid32 semBin;
};



