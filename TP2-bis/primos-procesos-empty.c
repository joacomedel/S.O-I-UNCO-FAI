
/* Padre crea dos hijos */

#include   <stdio.h>
#include   <unistd.h>
#include   <sys/types.h>
#include   <sys/wait.h>



#define MAX 500000
int encontrar_primos(int from, int to)
 {
        int retorna = 0;
         int i, n, primo;
         printf( "\n   " );

          for ( i = from ; i <= to ; i++ ) {
                  primo = 1;
                  n = 2;

                   while ( n <= i / 2 && primo ) {
                           if ( i % n == 0 )
                                   primo = 0;

                            n++;
                   }

                   if ( primo ){
                        //printf( "%d \n", i );
                        retorna++;
                   }
          }
          return retorna;
 }
int   main(void)
{
      int pid;
      int pid2;
      int wstatus;
      int total = 0;

      pid = fork();
      if (pid == 0) {
         printf("Proceso hijo porque pid es %i\n", pid);
         total = encontrar_primos(0,MAX/2);

      } else {

          printf("Proceso padre porque pid es %i \n", pid);

          pid2 = fork();
          if (pid2 == 0) {
                  printf("Proceso hijo porque pid es %i \n", pid2);
                  total = encontrar_primos(MAX/2,MAX);
          } else
                  printf("Proceso padre porque pid es %i \n", pid2);
                  /* esperamos a los hijos */
                

      }

      
        waitpid(pid, &wstatus, 0);
        waitpid(pid2, &wstatus, 0);
        printf("Total : %i \n", total);
      return 0;
}

