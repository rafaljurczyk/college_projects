//manager.h
#ifndef MANAGER_H
#define MANAGER_H
#include "person.h"
#include "employee.h"

/*Class representing Manager of our store. He is just a employee with more power.*/
class Manager : public Employee{
public:
    Manager();
    Manager(const std::string& name, const std::string& login, const std::string& password, double salary, EmployeePosition employee_position);
    /*Deletes employee from employee_list*/
    void fire_staff_member(std::vector<Employee*>* employees);
    /*Display all employees*/
    void show_employee_list(std::vector<Employee*>* employees) const;
    /*Add new employee to database*/
    void hire_employee(std::vector<Employee*>* employees);
    /*Checks if employee we're looking for exists and if he does it returns his salary as double*/
    double pay_salary(std::vector<Employee*>* employees);
};

#endif