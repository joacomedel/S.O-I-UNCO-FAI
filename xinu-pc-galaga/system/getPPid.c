#include <xinu.h>

/*------------------------------------------------------------------------
 *  getpid  -  Return the ID of the currently executing process
 *------------------------------------------------------------------------
 */
pid32	getPPid(void)
{
	return ((&proctab[getpid()])->prparent);
}