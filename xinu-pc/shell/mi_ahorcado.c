#include <xinu.h>

shellcmd mi_ahorcado(int32 n, char *param[])
{
	int32 c;

	char cadenaBuscar[] = "ahora"; // Palabra a buscar , si se edita , hay q editar cadenaTemp
	char cadenaTemp[] = {"_____"}; // CadenaTemp tiene q tener la misma cantidad de caracteres q cadenaBuscar
	int32 longCadena = strlen(cadenaBuscar);
	int32 intento = longCadena;
	int32 aciertos = 0; //contador para saber la cantidad de aciertos
	int32 letraEncontrada = 0; //boolean para ver si se encontro una letra

	/* Decirle al sistema que el modo input es RAW */
	// system ("/bin/stty raw");
	control(CONSOLE, TC_MODER, 0, 0);

	while (1)
	{
		letraEncontrada = 0;
		printf("\r                                                          ");

		printf("\r %s   : ingrese una letra, quedan %d intentos . (0 para salir): ", cadenaTemp, intento);
		c = getchar();
		

		for (int i = 0; i < strlen(cadenaBuscar); i++)
		{
			if (cadenaBuscar[i] == c)
			{
				if (cadenaTemp[i] == '_')
				{
					cadenaTemp[i] = cadenaBuscar[i];
					aciertos = aciertos + 1;
				}
				letraEncontrada = 1;
			}
		}

		if (letraEncontrada == 0) // Si no se encontró la letra
		{
			intento = intento - 1;
		}

		if (c == '0')
		{
			break;
		}
		if (aciertos == longCadena)
		{
			printf("\n Ganaste : la palabra era %s \n \n ", cadenaBuscar);
			break;
		}
		if (intento == 0)
		{
			printf("\n Perdiste \n \n");
			break;
		}
	}
	control(CONSOLE, TC_MODEC, 0, 0);
	// system ("/bin/stty sane erase ^H");
}