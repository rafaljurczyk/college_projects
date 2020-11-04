//interface.cpp
#include "interface.h"
#include <iomanip>

 Interface::Interface()
 {
     this->storage = new Storage();
     this->people_database = new PeopleDataBase();
 }
 
 Interface::~Interface()
 {
     delete this->storage;
     delete this->people_database;
 }


void Interface::show_client_interface(Client* client){
    std::cout<<"\n##############################################\n";
    std::cout<<"####   ####    ###    #### ### ### ####   ####\n";
    std::cout<<"### ### ### ###### ### ### ### ### ### ### ###\n";
    std::cout<<"#### ###### ###### ### ### ### ### #### ######\n";
    std::cout<<"###### ####    ###    #### ### ### ###### ####\n";
    std::cout<<"## #### ### ###### # ###### # #### ## #### ###\n";
    std::cout<<"####   ####    ### ##  ##### ##### ####   ####\n";
    std::cout<<"##############################################\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"## Currently logged: "<<client->get_name()<<std::setw(26-client->get_name().length())<<"##\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##############################################\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##  1. Show what's in the store.            ##\n";
    std::cout<<"##  2. Show avaible services.               ##\n";
    std::cout<<"##  3. Show upcoming events.                ##\n";
    std::cout<<"##  4. Login as Client.                     ##\n";
    std::cout<<"##  5. Register as Client.                  ##\n";
    std::cout<<"##  6. Exit Store.                          ##\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##------------------------------------------##\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##  7. Login as Employee.                   ##\n";
    std::cout<<"##  8. Login as Manager.                    ##\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##############################################\n";
    while(true){
        std::cin>>this->choice;
        while(std::cin.fail() || choice<0 || choice>8){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cout<<"Wrong value. Try again: \n";
            std::cin>>choice;
        }
        std::system("clear");
        if(choice==1){
            this->storage->show_storage();
            show_client_interface(client);
        }
        else if(choice==2){
            this->storage->show_services();
            show_client_interface(client);
        }
        else if(choice==3){
            this->storage->show_events();
            show_client_interface(client);
        }
        else if(choice==4){
            client = this->people_database->client_login_form(client);
            if(client->get_name() == "Anonymous User")
                show_client_interface(client);
            else{
                show_logged_client_interface(client);
            }
        }
        else if(choice==5){
            this->people_database->add_client();
            show_client_interface(client);
        }
        else if(choice==6){
            delete client;
            this->storage->save_storage();
            this->people_database->save_users();
            delete this;
            exit(0);
        }
        else if(choice==7){
            Employee* temp = this->people_database->employee_login_form();
            if(temp->get_name() == "Anonymous User"){
                delete temp;
                show_client_interface(client);
            } 
            else{
                show_employee_interface(temp);
                delete temp;
            }
        }
        else if(choice==8){
            Manager* temp = this->people_database->manager_login_form();
            if(temp->get_name() == "Anonymous User"){
                delete temp;
                show_client_interface(client);
            }
            else{
                show_manager_interface(temp);
                delete temp;
            }
        }
    }
}

void Interface::show_logged_client_interface(Client* client){
    std::cout<<"\n##############################################\n";
    std::cout<<"####   ####    ###    #### ### ### ####   ####\n";
    std::cout<<"### ### ### ###### ### ### ### ### ### ### ###\n";
    std::cout<<"#### ###### ###### ### ### ### ### #### ######\n";
    std::cout<<"###### ####    ###    #### ### ### ###### ####\n";
    std::cout<<"## #### ### ###### # ###### # #### ## #### ###\n";
    std::cout<<"####   ####    ### ##  ##### ##### ####   ####\n";
    std::cout<<"##############################################\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"## Currently logged: "<<client->get_name()<<std::setw(26-client->get_name().length())<<"##\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##############################################\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##  1. Show what's in the store.            ##\n";
    std::cout<<"##  2. Show avaible services.               ##\n";
    std::cout<<"##  3. Buy a product/bike.                  ##\n";
    std::cout<<"##  4. Order a service.                     ##\n";
    std::cout<<"##  5. Show upcoming events.                ##\n";
    std::cout<<"##  6. Add an event.                        ##\n";
    std::cout<<"##  7. Show ordered services.               ##\n";
    std::cout<<"##  8. Log Out.                             ##\n";
    std::cout<<"##  9. Exit Store.                          ##\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##############################################\n";
    while(true){
        std::cin>>this->choice;
        while(std::cin.fail() || choice<0 || choice>9){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cout<<"Wrong value. Try again: \n";
            std::cin>>choice;
        }
        std::system("clear");
        if(choice==1){
            this->storage->show_storage();
            show_logged_client_interface(client);
        }
        else if(choice==2){
            this->storage->show_services();
            show_logged_client_interface(client);
        }
        else if(choice==3){
            client->buy_a_product_or_bike(*(this->storage));
            show_logged_client_interface(client);
        }
        else if(choice==4){
            client->order_a_service(*(this->storage));
            show_logged_client_interface(client);
        }
        else if(choice==5){
            this->storage->show_events();
            show_logged_client_interface(client);
        }
        else if(choice==6){
            client->add_event(*(this->storage));
            show_logged_client_interface(client);
        }
        else if(choice==7){
            client->show_ordered_services();
            show_logged_client_interface(client);
        }
        else if(choice==8){
            show_client_interface(new Client);
        }
        else if(choice==9){
            this->storage->save_storage();
            this->people_database->save_users();
            delete this;
            exit(0);
        }
    }
}

void Interface::show_employee_interface(Employee* employee){
    std::cout<<"\n##############################################\n";
    std::cout<<"####   ####    ###    #### ### ### ####   ####\n";
    std::cout<<"### ### ### ###### ### ### ### ### ### ### ###\n";
    std::cout<<"#### ###### ###### ### ### ### ### #### ######\n";
    std::cout<<"###### ####    ###    #### ### ### ###### ####\n";
    std::cout<<"## #### ### ###### # ###### # #### ## #### ###\n";
    std::cout<<"####   ####    ### ##  ##### ##### ####   ####\n";
    std::cout<<"##############################################\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"## Currently logged: "<<employee->get_name()<<std::setw(26-employee->get_name().length())<<"##\n";
    std::cout<<"## Employee position: "<<EmployeePositionToString(employee->get_employee_position())<<std::setw(25-EmployeePositionToString(employee->get_employee_position()).length())<<"##\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##############################################\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##  1. Show what's in the store.            ##\n";
    std::cout<<"##  2. Show avaible services.               ##\n";
    std::cout<<"##  3. Buy a product                        ##\n";
    std::cout<<"##  4. Order a service                      ##\n";
    std::cout<<"##  5. Show upcoming events.                ##\n";
    std::cout<<"##  6. Show unapproved events.              ##\n";
    std::cout<<"##  7. Add an event                         ##\n";
    std::cout<<"##  8. Approve an event                     ##\n";
    std::cout<<"##  9. Show ordered services.               ##\n";
    std::cout<<"##  10. Log Out.                            ##\n";
    std::cout<<"##  11. Exit Store.                         ##\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##############################################\n";
    while(true){
        std::cin>>this->choice;
        while(std::cin.fail() || choice<0 || choice>11){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cout<<"Wrong value. Try again: \n";
            std::cin>>choice;
        }
        std::system("clear");
        if(choice==1){
            this->storage->show_storage();
            show_employee_interface(employee);
        }
        else if(choice==2){
            this->storage->show_services();
            show_employee_interface(employee);
        }
        else if(choice==3){
            employee->buy_a_product_or_bike(*(this->storage));
            show_employee_interface(employee);
        }
        else if(choice==4){
            employee->order_a_service(*(this->storage));
            show_employee_interface(employee);
        }
        else if(choice==5){
            this->storage->show_events();
            show_employee_interface(employee);
        }
        else if(choice==6){
            this->storage->show_unapproved_events();
            show_employee_interface(employee);
        }
        else if(choice==7){
            employee->add_event(*(this->storage));
            show_employee_interface(employee);
        }
        else if(choice==8){
            employee->approve_event(*(this->storage));
            show_employee_interface(employee);
        }
         
        else if(choice==10){
            show_client_interface(new Client);
        }
        else if(choice==11){
            this->storage->save_storage();
            this->people_database->save_users();
            delete this;
            exit(0);
        }
    }
}

void Interface::show_manager_interface(Manager* manager){
    std::cout<<"\n##############################################\n";
    std::cout<<"####   ####    ###    #### ### ### ####   ####\n";
    std::cout<<"### ### ### ###### ### ### ### ### ### ### ###\n";
    std::cout<<"#### ###### ###### ### ### ### ### #### ######\n";
    std::cout<<"###### ####    ###    #### ### ### ###### ####\n";
    std::cout<<"## #### ### ###### # ###### # #### ## #### ###\n";
    std::cout<<"####   ####    ### ##  ##### ##### ####   ####\n";
    std::cout<<"##############################################\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"## Currently logged: "<<manager->get_name()<<std::setw(26-manager->get_name().length())<<"##\n";
    std::cout<<"## Employee position: "<<EmployeePositionToString(manager->get_employee_position())<<std::setw(25-EmployeePositionToString(manager->get_employee_position()).length())<<"##\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##############################################\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##  1. Show what's in the store.            ##\n";
    std::cout<<"##  2. Show avaible services.               ##\n";
    std::cout<<"##  3. Buy a product                        ##\n";
    std::cout<<"##  4. Order a service                      ##\n";
    std::cout<<"##  5. Show upcoming events.                ##\n";
    std::cout<<"##  6. Show unapproved events.              ##\n";
    std::cout<<"##  7. Add an event                         ##\n";
    std::cout<<"##  8. Approve an event                     ##\n";
    std::cout<<"##  9. Show employee list                   ##\n";
    std::cout<<"##  10. Pay salary                          ##\n";
    std::cout<<"##  11. Hire new employee                   ##\n";
    std::cout<<"##  12. Fire employee                       ##\n";
    std::cout<<"##  13. Log Out.                            ##\n";
    std::cout<<"##  14. Exit Store.                         ##\n";
    std::cout<<"##                                          ##\n";
    std::cout<<"##############################################\n";
    while(true){
        std::cin>>this->choice;
        while(std::cin.fail() || choice<0 || choice>14){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cout<<"Wrong value. Try again: \n";
            std::cin>>choice;
        }
        std::system("clear");
        if(choice==1){
            this->storage->show_storage();
            show_manager_interface(manager);
        }
        else if(choice==2){
            this->storage->show_services();
            show_manager_interface(manager);
        }
        else if(choice==3){
            manager->buy_a_product_or_bike(*(this->storage));
            show_manager_interface(manager);
        }
        else if(choice==4){
            manager->order_a_service(*(this->storage));
            show_manager_interface(manager);
        }
        else if(choice==5){
            this->storage->show_events();
            show_manager_interface(manager);
        }
        else if(choice==6){
            this->storage->show_unapproved_events();
            show_manager_interface(manager);
        }
        else if(choice==7){
            manager->add_event(*(this->storage));
            show_manager_interface(manager);
        }
        else if(choice==8){
            manager->approve_event(*(this->storage));
            show_manager_interface(manager);
        }
        else if(choice==9){
            std::vector<Employee*>* tmp = this->people_database->get_employees();
            manager->show_employee_list(tmp);
            show_manager_interface(manager);
        }
        else if(choice==10){
            std::vector<Employee*>* tmp = this->people_database->get_employees();
            this->storage->set_balance(manager->pay_salary(tmp) + this->storage->get_balance());
            show_manager_interface(manager);
        }
        else if(choice==11){
            std::vector<Employee*>* tmp = this->people_database->get_employees();
            manager->hire_employee(tmp);
            show_manager_interface(manager);
        }
        else if(choice==12){
            std::vector<Employee*>* tmp = this->people_database->get_employees();
            manager->fire_staff_member(tmp);
            show_manager_interface(manager);
        }
        else if(choice==13){
            show_client_interface(new Client);
        }
        else if(choice==14){
            this->storage->save_storage();
            this->people_database->save_users();
            delete this;
            exit(0);
        }
    }
}

void Interface::load_interface(){
    this->people_database->load_users();
    this->storage->load_storage();
}
