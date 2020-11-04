//employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "storage.h"
#include "person.h"
#include "enum.h"

class Employee : public Person{
    std::string login;
    std::string password;
    EmployeePosition employee_position;
    double salary;

public:
    Employee();
    Employee(const std::string& name, const std::string& login, const std::string& password, const double salary, const EmployeePosition employee_position);
    EmployeePosition get_employee_position() const;
    double get_salary() const;
    /*As employee/manager you can approve event added by client. By approving event it can be displayed in event list.*/
    void approve_event(Storage& storage);
    std::string get_login() const;
    std::string get_password() const;
    /*As employee/manager you can add event that is already approved.*/
    virtual void add_event(Storage& storage) override;
    ~Employee();
};


#endif