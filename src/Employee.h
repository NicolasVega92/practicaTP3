/*
 * Employee.h
 *
 *  Created on: 25 oct. 2020
 *      Author: Nico
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
	#include "utn.h"
	#include "Validaciones.h"
	#define QTY_ALUMNO 100
	#define LONG_ID 10
	typedef struct
	{
		int id;
		char name[LONG_NAME];
		char lastName[LONG_NAME];
	}Employee;
	Employee* employee_new(void);
	Employee* employee_newParametros(char name[], char lastName[]);
	void employee_delete(Employee* this); //Puntero de contexto

	/****************************************************************************************/

	int employee_initArrayPunteros(Employee* arrayPunteros[], int length);
	int employee_buscarLibreArrayPunteros(Employee* arrayPunteros[], int length);
	int employee_imprimirArrayPunteros(Employee* arrayPunteros[], int length);
	int employee_deleteIndiceArrayPuntero(Employee* arrayPuntero[], int length, int indice);
	int employee_buscarById(Employee* arrayPunteros[], int length, int id);
	int employee_agregarAlArrayPunteros(Employee* arrayPunteros[], int length, char name[], char lastName[]);
	int employee_deleteByIdArray(Employee* arrayPunteros[], int length, int id);


#endif /* EMPLOYEE_H_ */
