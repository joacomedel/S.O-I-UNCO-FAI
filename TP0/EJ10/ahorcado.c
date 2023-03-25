#include <stdio.h>
#include <stdlib.h>	/* para las funciones system y exit */
#include <string.h>


int main() {

	int c;
	char cadenaBuscar[] = {"hola"};
	int r = 1;
	char cadenaTemp[] = {"____"};
	int intento = 4;
	int encontro = 0;
	int aciertos = 0;



	/* Decirle al sistema que el modo input es RAW */
	system ("/bin/stty raw");



	while(1) {
		encontro = 0;
		printf("\r                                                          ");
	
		printf("\r %s   : ingrese una letra, quedan %i intentos . (0 para salir): ", cadenaTemp,intento);
		c = getchar();
		for(int i=0 ; i < strlen(cadenaBuscar); i++){
			if(cadenaBuscar[i] == c){
				cadenaTemp[i] = cadenaBuscar[i];
				aciertos++;
				encontro = 1;
			}
		}
		if (encontro == 0){
			intento --;
		}
		if (c == '0' ){
			
			break;
		}
		if(intento == 0){
			printf("Perdiste");
		}
		if(aciertos == strlen(cadenaBuscar)){
			printf("Ganaste");
		}
	}

	system ("/bin/stty sane erase ^H");
}

