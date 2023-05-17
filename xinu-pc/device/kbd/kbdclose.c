/* kbdclose.c  -  kbdclose */

#include <xinu.h>
#include <keyboard.h>

/*------------------------------------------------------------------------
 * kbdclose  -  Close the keyboard device
 *------------------------------------------------------------------------
 */
devcall	kbdclose (
	  struct dentry	*devptr		/* Entry in device switch table	*/
	)
{
	if (semKbd == getpid())
	{
		signal(semKbd);
	}
	

	return OK;
}
