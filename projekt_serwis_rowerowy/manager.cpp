//manager.cpp
#include "manager.h"

Manager::Manager() : Employee() {}
Manager::Manager(const std::string& name, const std::string& login, const std::string& password, double salary, EmployeePosition employee_position) :
Employee(name,login,password,salary,employee_position){}

void Manager::fire_staff_member(std::vector<Employee*>* employees){
    std::string name;
    std::cout<<"Type staff member's name:\n";
    std::cin.ignore(256,'\n');
    std::getline(std::cin, name);
    for(int i = 0; i < employees->size(); i++){
        if((*employees)[i]->get_name() == name){
            delete (*employees)[i];
            employees->erase( employees->begin() + i );
            std::cout<<name<<" was fired :(\n";
        }
    }
}

void Manager::hire_employee(std::vector<Employee*>* employees){
    std::string name, login, password;
    double salary;
    EmployeePosition employee_position;
    int position;
    std::cout<<"Type employee's name:\n";
    std::cin.ignore(256,'\n');
    std::getline(std::cin, name);
    std::cout<<"Type employee's login:\n";
    std::getline(std::cin, login);
    std::cin.clear();
    std::cout<<"Type employee's password\n";
    std::cin>>password;
    std::cin.clear();
    std::cout<<"Type employee's salary\n";
    std::cin>>salary;
    while(std::cin.fail() || salary < 0){
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout<<"Wrong value. Try again: \n";
        std::cin>>salary;
    }
    std::cout<<"Type employee's position: (1. warehouseman, 2. adviser, 3.service_technician)\n";
    std::cin.clear();
    std::cin>>position;
    while(std::cin.fail() || position < 1 || position > 3){
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout<<"Wrong value. Try again: \n";
        std::cin>>position;
    }
    if(position == 1) employee_position = warehouseman;
    else if(position = 2) employee_position = adviser;
    else employee_position = service_technician;

    employees->push_back(new Employee(name, login, password, salary, employee_position));
}

void Manager::show_employee_list(std::vector<Employee*>* employees) const{
    for(auto e : *employees) std::cout<<e->get_name()<<" ["<<e->get_salary()<<"] - "<<EmployeePositionToString(e->get_employee_position())<<std::endl;
}

double Manager::pay_salary(std::vector<Employee*>* employees){
    std::string name;
    std::cout<<"Type employee's name:\n";
    std::cin.ignore(256,'\n');
    std::getline(std::cin, name);
    for(auto e : *employees){
        if(name == e->get_name()){
            std::cout<<"Employee's salary paid.\n";
            return e->get_salary();
        }
    }
    return 0;

}
