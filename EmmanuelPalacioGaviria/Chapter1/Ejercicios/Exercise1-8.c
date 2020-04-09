/**
 *              Ejercicios del libro programming C
 *              Write a program to count blanks, tabs, and newlines.
 * Haremos dos soluciones una con for y el otro con while para mirar las diferencias.
 */

#include <stdio.h>

int main(void)
{
	// Declaramos las variables, pero no las definimos (ya que definir es almacenar y declara es darle la propiedad de la variable)
	int nt;        // La variable nt es el nuemero de tabuladores que entraran a la libreria estandar.
	int nl;        // La variable nl es el numero de nuevas lineas
	int ns;        // La variable ns es el numero de espacios
	int c;         // Almecenaremos los caracteres que getchar nos ira pasando cada vez que se llama

	for(nl = 0, nt = 0, ns = 0; (c = getchar()) != EOF;){   // Como podmeos ver inicializamos las variables para que no tengas contenido basura y utilizamos el operador coma
		if (c == '\n')
			nl++;
		else if(c == '\t')
			nt++;
		else if(c == ' ')
			ns++;
	}

	printf("Numero de lineas: %d\nNumero de tabuladores: %d\nNumero de espacios: %d\n", nl, nt, ns);
	return (0);
}
/* La diferencia entre utilizar foy y while no es ninguna cuando nos referimos a la funcionaludad de cada una, ya que hacen lo mismo
   Una diferencia estetica es que el for contiene la inicializacion, la condicion y el incremento en una sola linea de codigo y por tanto es 
   mas comodo para el que vaya a leer el codio, tambien introducimos el operador coma (,) esta se puede ver en el for, antes de la primea ;
   y antes del while en el segundo codigo*/
void VersionWhile(void)
{
	int nt, nl, ns, c;

	nt = nl = ns = 0;
	while((c = getchar()) != EOF)
	{
                if (c == '\n')
                        nl++;
                else if(c == '\t')
                        nt++;
		else if(c == ' ')
                        ns++;
	}
        printf("Numero de lineas: %d\nNumero de tabuladores: %d\nNumero de espacios: %d\n", nl, nt, ns);
	return ;  // como la funcions retorna void, es decir nada nos podemos permitir colocar esto, creo que lo retorna es nada o contenido basuca.
}
