//interface.h
#ifndef INTERFACE_H
#define INTERFACE_H
#include "storage.h"
#include "people_database.h"
#include "person.h"
#include "client.h"
#include "employee.h"
#include "enum.h"
#include "manager.h"
#include<iostream>
#include<vector>

/*Class that is used to display text and some 'graphics' in console.
What it shows depends on who we're logged as.*/
class Interface{
    Storage* storage;
    PeopleDataBase* people_database;
    int choice;
public:
    /*It is called at a start of program and it loads our databases*/
    void load_interface();
    /*This is UI for default Anonymous Client that isn't signed.*/
    void show_client_interface(Client* client);
    /*This is UI for signed in Client.*/
    void show_logged_client_interface(Client *client);
    /*This is UI for signed in Employee.*/
    void show_employee_interface(Employee* employee);
    /*This is UI for signed in Manager.*/
    void show_manager_interface(Manager* manager);

    Interface();
    ~Interface();
};

#endif