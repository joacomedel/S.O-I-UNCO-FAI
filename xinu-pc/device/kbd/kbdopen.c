/* kbdopen.c  -  kbdopen */

#include <xinu.h>
#include <keyboard.h>

/*------------------------------------------------------------------------
 * kbdopen  -  Open the ps/2 keyboard device
 *------------------------------------------------------------------------
 */

devcall	kbdopen (
	 struct	dentry	*devptr,	/* Entry in device switch table	*/
	 char	*name,			/* Unused for a kbd */
	 char	*mode			/* Unused for a kbd */
	)
{
	/* No action -- just return the device descriptor */
	wait(semKbd);
	semKbd = getpid();


	return devptr->dvnum;
}
