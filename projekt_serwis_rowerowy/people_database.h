//people_database.h
#ifndef PEOPLE_DATABASE_H
#define PEOPLE_DATABASE_H
#include "person.h"
#include "client.h"
#include "employee.h"
#include "manager.h"
#include "enum.h"
#include <iostream>
#include <vector>
#include <fstream>

/*Class that represent whole users database.*/
class PeopleDataBase{
    std::vector<Client*> clients;
    std::vector<Employee*> employees;
    std::vector<Manager*> managers;
public:
    /*Add new client to database*/
    void add_client();
    void show_clients() const;
    /*Add new employee to database*/
    void add_employee(Employee* employee);
    void show_employee_list() const;
    /*Add new manager to database. I made it that it is only one manager in this store but if you want expand it everything is set up.*/
    void add_manager(Manager* manager);
    void show_managers() const;
    std::vector<Client*> get_clients();
    std::vector<Employee*>* get_employees();
    std::vector<Manager*> get_managers();
    /*Display login form for client. If we exit it without signing in, it return Anonymous User which equals to displaying not logged Client UI.*/
    Client* client_login_form(Client* client);
    /*Display login form for employee. If we exit it without signing in, it return Anonymous User which equals to displaying not logged Client UI.*/
    Employee* employee_login_form();
    /*Display login form for manager. If we exit it without signing in, it return Anonymous User which equals to displaying not logged Client UI.*/
    Manager* manager_login_form();
    /*load every client/employee/manager to our class that represent the databse*/
    void load_users();
    /*save every client/employee/manager in our txt file*/
    void save_users();
    ~PeopleDataBase();
};

#endif