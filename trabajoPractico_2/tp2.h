#ifndef TP2_H_INCLUDED
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utn.h"

#define MAX_EMPLOYEES 1000
#define true 1
#define false 0

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

void initEmployees(Employee* employeeList, int length);
int nextEmptySlot(Employee* employeeList);
int generateID (void);
int addEmployees (Employee* employeesList, int eLength);
int removeEmployee (Employee* employeesList, int eLength);
int sortEmployees(Employee* employeesList, int eLength);
void printEmployees (Employee* employeesList, int eLength);
void modifyEmployeeInfo(Employee* employeesList, int eLength);
void averageSalary (Employee* employeesList, int eLength);

#endif // TP2_H_INCLUDED
