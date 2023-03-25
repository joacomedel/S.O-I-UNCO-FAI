#include <xinu.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int mi_ahorcado() {

	int32 c;
	char cadenaBuscar[] = {"hola"};
	int32 r = 1;
	char cadenaTemp[] = {"____"};
	int32 longCadena = strlen(cadenaBuscar);
	int32 intento = longCadena;
	bool encontro = false;
	int32 aciertos = 0;



	/* Decirle al sistema que el modo input es RAW */
	//system ("/bin/stty raw");
    control(CONSOLE,TC_MODER,0,0);


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
        if(aciertos == longCadena){
			printf("\n Ganaste : la palabra era %s \n \n ",cadenaBuscar);
            break;
		}
		if(intento == 0){
			printf("\n Perdiste \n \n");
            break;
		}
		
	}
    control(CONSOLE,TC_MODEC,0,0);
	//system ("/bin/stty sane erase ^H");
}