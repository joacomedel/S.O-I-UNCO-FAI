#include <xinu.h>


shellcmd  mi_ahorcado	(int32 n, char *param[] )
{
	int32 c;
	
	char cadenaBuscar[] = "hola";
	int32 r = 1;
	char cadenaTemp[] = {"____"};
	int32 longCadena = strlen(cadenaBuscar);
	int32 intento = longCadena;
	int encontro = 0;
	int32 aciertos = 0;

	/* Decirle al sistema que el modo input es RAW */
	// system ("/bin/stty raw");
	control(CONSOLE, TC_MODER, 0, 0);

	while (1)
	{
		printf("\r                                                          ");

		printf("\r %s   : ingrese una letra, quedan %d intentos . (0 para salir): ", cadenaTemp, intento);
		c = getchar();
		for (int i = 0; i < strlen(cadenaBuscar); i++)
		{
			if (cadenaTemp[i] == '_' && cadenaBuscar[i] == c)
			{
				cadenaTemp[i] = cadenaBuscar[i];
				aciertos = aciertos + 1;
				encontro = 1;
			}
		}

		if (encontro == 0)
		{
			intento = intento - 1;
		}
		else
		{
			encontro = 0;
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