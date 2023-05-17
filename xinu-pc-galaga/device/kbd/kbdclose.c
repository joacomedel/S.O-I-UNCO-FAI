/* kbdclose.c  -  kbdclose */

#include <xinu.h>
#include <keyboard.h>

/*------------------------------------------------------------------------
 * kbdclose  -  Close the keyboard device
 *------------------------------------------------------------------------
 */
extern sid32 semKbd;
extern pid32 pidKbd;
devcall	kbdclose (
	  struct dentry	*devptr		/* Entry in device switch table	*/
	)
{
	
	if (pidKbd = getpid())
	{
		signal(semKbd);
	}
	
}
