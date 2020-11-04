//enum.h
#ifndef ENUM_H
#define ENUM_H
#include<iostream>

/*Types of bikes in store*/
enum Type{ mountain, city, universal };

/*Avaible employee positions*/
enum EmployeePosition { warehouseman, adviser, service_technician, manager };

std::string TypeToString(const Type type);

std::string EmployeePositionToString(const EmployeePosition employee_position);

EmployeePosition StringToEmployeePosition(const std::string& employee_position);

Type StringToType(const std::string& type);

#endif  
