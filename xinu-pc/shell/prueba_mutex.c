/* mut.c - mut, operar, incrementar */
#include <xinu.h>
void operar(void), incrementar(void);
unsigned char x = 0;
mtx32 mutex;

/*------------------------------------------------------------------------
 * mut -- programa con regiones criticas
 *------------------------------------------------------------------------
 */
shellcmd prueba_mutex(void)
{
    mutex = mutex_init;
    int i;
    resume(create(operar, 1024, 20, "process 1", 0));
    resume(create(incrementar, 1024, 20, "process 2", 0));
    sleep(4);
}
/*------------------------------------------------------------------------
 * operar x e y
 *------------------------------------------------------------------------
 */
void operar(void)
{
    mutex_lock(mutex);
    int y = 0;
    mutex_unlock(mutex);
    printf("Si no existen mensajes de ERROR entonces todo va OK! \n");
    while (1)
    {
        mutex_lock(mutex);
        /* si x es multiplo de 10 */
        if ((x % 10) == 0)
        {
            y = x * 2; /* como y es el doble de x entonces
                        * y es multiplo de 10 tambien
                        */
            /* si y no es multiplo de 10 entonces hubo un error */
            if ((y % 10) != 0)
                printf("\r ERROR!! y=%d, x=%d \r", y, x);
        }
        mutex_unlock(mutex);
    }
}
/*------------------------------------------------------------------------
 * incrementar x
 *------------------------------------------------------------------------
 */
void incrementar(void)
{
    mutex_lock(mutex);
    while (1)
    {
        x = x + 1;
    }
    mutex_unlock(mutex);
}