/*
 ============================================================================
 Name        : 15_PracticaTp3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"
#include "Validaciones.h"

int main(void) {
	setbuf(stdout,NULL);

	Employee* arrayPunterosEmployee[QTY_ALUMNO];

	if(employee_initArrayPunteros(arrayPunterosEmployee, QTY_ALUMNO)==0)
	{
		printf("array init OK\n");
		if(employee_agregarAlArrayPunteros(arrayPunterosEmployee, QTY_ALUMNO, "Juan", "Rodriguez")==0)
		{
			printf("Alta ok\n");
		}
		if(employee_agregarAlArrayPunteros(arrayPunterosEmployee, QTY_ALUMNO, "Fede", "Perez")==0)
		{
			printf("Alta ok\n");
		}
		employee_imprimirArrayPunteros(arrayPunterosEmployee, QTY_ALUMNO);

		if(employee_deleteByIdArray(arrayPunterosEmployee, QTY_ALUMNO, 2)==0)
		{
			printf("\nBorrado\n");
		}
		employee_imprimirArrayPunteros(arrayPunterosEmployee, QTY_ALUMNO);
	}

	return EXIT_SUCCESS;
}
