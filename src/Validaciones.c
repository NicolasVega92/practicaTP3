/*
 * Validaciones.c
 *
 *  Created on: 27 oct. 2020
 *      Author: Nico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Validaciones.h"

/*
* \brief Verifica una cadena como parametro para determinar si es nombre valido
* \param char cadena[], cadena a analizar
* \param limite indica la cantidad maxima del nombre
 * return (1) Es válido / (0) No es un nombre valido
 */
int itIsAValidName(char array[], int limite)
{
	int retorno = 1; //TODO OK
	int i=0;
	if(array[i]=='\0')
	{
		retorno = 0;
	}
	else
	{
		for(i = 0; i <= limite && array[i] != '\0'; i++)
		{
			if(isOnlyLettersAndSpace(array) == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada son letras
 * \param cadena Cadena de caracteres a ser analizada
 * \return 1 EXITO / (0) ERROR
 */
int isOnlyLettersAndSpace(char cadena[])
{
	int retorno = 1;
	int i=0;
	int flagSpace = FALSE;
	if(cadena[i]==' ')
	{
		retorno = 0;
	}
	else
	{
		for( ; cadena[i] != '\0'; i++)
		{
			if(flagSpace == TRUE)
			{
				if(cadena[i] == ' ')
				{
					retorno = 0;
					break;
				}
				else
				{
					flagSpace = FALSE;
				}
			}
			if((cadena[i] < 'A' || cadena[i] > 'Z') &&
				(cadena[i] < 'a' || cadena[i] > 'z') &&
				(cadena[i] != ' ') &&
				(cadena[i] < 'á' || cadena[i] > 'ú') &&
				(cadena[i] != 'é'))
			{
				retorno = 0;
				break;
			}
			if(cadena[i] == ' ')
			{
				flagSpace = TRUE;
			}

		}
	}
	return retorno;
}
/*
 *
 */
int esNumerica(char* array, int length)
{
	int retorno = -1;
	int i;
	if(array != NULL && length > 0)
	{
		retorno = 1;
		for(i=0; i < length && array[i] != '\0';i++)
		{
			if(i==0 && (array[i]=='+' || array[i]=='-'))
			{
				 continue;
			}
			if(array[i] < '0' || array[i] > '9')
			{
				retorno = 0;
				break;
			}
			//Continue
		}
		//BREAK
	}
	return retorno;
}




















