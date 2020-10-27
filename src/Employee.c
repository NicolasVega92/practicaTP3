/*
 * Employee.c
 *
 *  Created on: 25 oct. 2020
 *      Author: Nico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"
static int employee_generarIdNuevo(void);
/*
 *\brief 	Reserva un espacio de memoria para 1 Employee
 *\return 	La direccion de memoria de 1 Employee
 */
Employee* employee_new(void)
{
	return (Employee*) malloc(sizeof(Employee));
	/*
	Employee* auxiliarP;
	auxiliarP = (Employee*) malloc(sizeof(Employee));//Acabo de guardar la Dir. de Mem. de un employee
	return auxiliarP;
	*/
}
/*
 *\brief	Recibe por parametros datos y los agrega a una direccion de memoria Employee
 *\param	char name[]
 *\param	char lastName[]
 *\param	int id
 *\return	punteroEmployee, Devuelve el puntero al employee creado en la direccion de memoria
 */
Employee* employee_newParametros(char name[], char lastName[])
{
	Employee* punteroEmployee;
	punteroEmployee = employee_new();
	if(punteroEmployee != NULL)
	{
		strncpy(punteroEmployee->name,name, LONG_NAME);
		strncpy(punteroEmployee->lastName,lastName, LONG_NAME);
		punteroEmployee->id = employee_generarIdNuevo();
	}
	return punteroEmployee;
}
/*
 *
 */
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
/*
 *
 */
int employee_setNombre(Employee* this, char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(itIsAValidName(nombre, LONG_NAME))
		{
			strncpy(this->name,nombre, LONG_NAME);
			retorno = 0;
		}
	}
	return retorno;
}
/*
 *
 */
//Aca debe ponerse todo lo que se quiera modificar el campo nombre, ejemplo todo en mayus, todo en minus
int employee_getNombre(Employee* this, char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->name, LONG_NAME);
		retorno = 0;
	}
	return retorno;
}
/*
 *
 */
int employee_setIdTxt(Employee* this, char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id, LONG_ID))
		{
			retorno = 0;
			this->id = atoi(id);
		}
	}
	return retorno;
}
/*
 *
 */
int employee_setId(Employee* this, int id)
{
	int retorno = -1;
	if(this != NULL && id > 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}
/*
 *
 */
int employee_getIdTxt(Employee* this, char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d", this->id);
	}
	return retorno;
}


/*********************************************************************************************************/

/*
 * \brief 	Inicializa el array de punteros en las posiciones con NULL
 *			Cada elemento del array es un PUNTERO A UN ALUMNO
 * \param	Employee* arrayPunteros[], array de punteros
 * \param	int length, limite
 * \return 	-1 ERROR / 0 OK
 */
int employee_initArrayPunteros(Employee* arrayPunteros[], int length)
{
	int retorno = -1;
	int i;
	if(arrayPunteros != NULL && length > 0)
	{
		for(i = 0; i < length; i++)
		{
			arrayPunteros[i] = NULL;
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief 	Recorre el array de punteros buscando una posicion con NULL cargado y lo retorna como valor
 * \param	Employee* arrayPunteros[], array de punteros
 * \param	int length, limite
 * \return 	-1 ERROR verificacion / -2 no hay espacio libre / Numero de posicion con NULL cargado OK
 */
int employee_buscarLibreArrayPunteros(Employee* arrayPunteros[], int length)
{
	int retorno = -1;
	int i;
	if(arrayPunteros != NULL && length > 0)
	{
		retorno = -2;
		for(i = 0; i < length; i++)
		{
			if(arrayPunteros[i] == NULL)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/*
 * \brief 	Imprime los campos de la direccion de memoria que contiene cada posicion del array punteros
 * 			que sea != NULL
 * \param	Employee* arrayPunteros[], array de punteros
 * \param	int length, limite
 * \return 	-1 ERROR verificacion / 0 OK
 */
int employee_imprimirArrayPunteros(Employee* arrayPunteros[], int length)
{
	int retorno = -1;
	int i;
	if(arrayPunteros != NULL && length > 0)
	{
		printf("\n-----------LISTA ALUMNOS--------------\n");
		for(i = 0; i < length; i++)
		{
			if(arrayPunteros[i] != NULL)
			{
				printf(" Nombre: %s  - Apellido: %s - ID: %d \n",arrayPunteros[i]->name, arrayPunteros[i]->lastName, arrayPunteros[i]->id);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/*
 *\brief	Libera una posicion del array punteros utilizando la funcion FREE en el indice pasado como parametro
 *			luego marca ese indice con el valor NULL
 *\param 	Employee* arrayPuntero[]
 *\param 	int length
 *\param  	int indice
 *\return	-1 ERROR / 0 OK
 */
int employee_deleteIndiceArrayPuntero(Employee* arrayPuntero[], int length, int indice)
{
	int retorno = -1;
	if(arrayPuntero != NULL && indice >= 0 && length > 0 && arrayPuntero[indice] != NULL)
	{
		employee_delete(arrayPuntero[indice]); // sirve para que el malloc puede volver a pedir esta memoria
		arrayPuntero[indice] = NULL; //Nos aseguramos que el indice utilizado se pueda volver a utilizar
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief 	Recorre el array de punteros buscando una posicion con ID cargado y lo retorna como valor el indice
 * \param	Employee* arrayPunteros[], array de punteros
 * \param	int length, limite
 * \param   int id
 * \return 	-1 ERROR verificacion / -2 no hay coincidencia / Numero de posicion con id cargado OK
 */
int employee_buscarById(Employee* arrayPunteros[], int length, int id)
{
	int retorno = -1;
	int i;
	if(arrayPunteros != NULL && length > 0 && id > 0)
	{
		retorno = -2;
		for(i = 0; i < length; i++)
		{
			if(arrayPunteros[i] != NULL &&  arrayPunteros[i]->id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/*
 *\brief	Agrega al arrayPunteros los parametros pasados y los coloca en una posicion libre del array
 *\param	Employee* arrayPunteros[]
 *\param	int length
 *\param	char name[]
 *\param	char lastName[]
 *\param	int id
 *\return	-1 ERROR / 0 OK
 */
int employee_agregarAlArrayPunteros(Employee* arrayPunteros[], int length, char name[], char lastName[])
{
	int retorno = -1;
	int indiceLibre;
	if(arrayPunteros != NULL && length > 0 && name != NULL && lastName != NULL)
	{
		indiceLibre = employee_buscarLibreArrayPunteros(arrayPunteros, length);
		if(indiceLibre >= 0)
		{
			arrayPunteros[indiceLibre] = employee_newParametros(name, lastName);
		}
		retorno = 0;
		//retorno = indiceLibre; lugar en el que consiguio colocarlo
	}
	return retorno;
}
/*
 *
 */
int employee_deleteByIdArray(Employee* arrayPunteros[], int length, int id)
{
	int retorno = -1;
	int indiceBorrar;
	if(arrayPunteros != NULL && length > 0 && id > 0)
	{
		indiceBorrar = employee_buscarById(arrayPunteros, length, id);
		if(indiceBorrar >= 0)
		{
			employee_deleteIndiceArrayPuntero(arrayPunteros, length, indiceBorrar);
			retorno = 0;
		}
	}
	return retorno;
}
/*
 *	\brief Cada vez que es llamada devuelve un ID nuevo. Que nunca devolvio antes.
 */
static int employee_generarIdNuevo(void)
{
	static int id=0;
	id = id + 1;
	return id;
}
























