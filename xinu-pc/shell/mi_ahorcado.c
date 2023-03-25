#include <xinu.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <tty.h>

int mi_ahorcado() {

	int32 c;
	char cadenaBuscar[] = {"hola"};
	int32 r = 1;
	char cadenaTemp[] = {"____"};
	int32 intento = 8;
	bool encontro = false;
	int32 aciertos = 0;



	/* Decirle al sistema que el modo input es RAW */
	//system ("/bin/stty raw");
    control(CONSOLE,ttyhandle_in)


	while(1) {
		printf("\r                                                          ");
	
		printf("\r %s   : ingrese una letra, quedan %d intentos . (0 para salir): ", cadenaTemp,intento);
		c = getchar();
		for(int i=0 ; i < strlen(cadenaBuscar); i++){
			if(cadenaTemp[i] == '_' && cadenaBuscar[i] == c){
				cadenaTemp[i] = cadenaBuscar[i];
				aciertos = aciertos + 1;
                encontro = true;
			}
		}

		if (!encontro){
            printf("INTENTO -1 - %d - %d",encontro ,aciertos);
			intento = intento - 1;
		}else{
            encontro = false;
        }

        if (c == '0' ){
			
			break;
		}
        if(aciertos == strlen(cadenaBuscar)){
			printf("\n Ganaste : la palabra era %s \n \n ",cadenaBuscar);
            break;
		}
		if(intento == 0){
			printf("\n Perdiste \n \n");
            break;
		}
		
	}
    
	//system ("/bin/stty sane erase ^H");
}