//employee.cpp
#include "employee.h"

Employee::Employee() : Person("Anonymous User") {}
Employee::Employee(const std::string& name, const std::string& login, const std::string& password, const double salary, const EmployeePosition employee_position) : Person(name){
    if(login.length() < 3) 
        throw std::logic_error("Your name's too short.");
    else if(login.length() > 20)
        throw std::logic_error("Your name's too long.");
    if(password.length() < 3)
        throw std::logic_error("Your password's too short.");
    //check if price is a double
    this->login = login;
    this->password = password;
    this->salary = salary;
    this->employee_position = employee_position;
}

EmployeePosition Employee::get_employee_position() const{
    return this->employee_position;
}

double Employee::get_salary() const{
    return this->salary;
}


std::string Employee::get_login() const{
    return this->login;
}

std::string Employee::get_password() const{
    return this->password;
}

void Employee::add_event(Storage& storage){
        std::string name, description;
    int day, month, year;
    std::cin.ignore(256,'\n');
    std::cout<<"Type you event name:\n";
    std::getline(std::cin, name);
    std::cout<<"Type your event description:\n";
    std::getline(std::cin, description);
    std::cout<<"Type the year it takes place:\n";
    std::cin.clear();
    std::cin>>year;
    while(std::cin.fail() || year<2000 || year>3000){
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout<<"Wrong value. Try again: \n";
        std::cin>>year;
    }
    std::cout<<"Type the month it takes place:\n";
    std::cin>>month;
    while(std::cin.fail() || month<0 || month>12){
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout<<"Wrong value. Try again: \n";
        std::cin>>month;
    }    
    std::cout<<"Type the day it takes place:\n";
    std::cin>>day;
    while(std::cin.fail() || day<0 || (month==2 && day>28) || ((month==7 || month==8) && day>31) || (month%2 == 0 && day > 30) || day > 31){
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout<<"Wrong value. Try again: \n";
        std::cin>>day;
    }
    Date* tmp_date = new Date(day,month,year);
    storage.add_event(new Event(name, description, tmp_date, true));
    delete tmp_date;
}

void Employee::approve_event(Storage& storage){
    std::string name;
    std::cout<<"Type the name of event you want to approve:\n";
    std::cin.ignore(256,'\n');
    std::getline(std::cin, name);
    storage.approve_event(name);
}

Employee::~Employee(){}