//people_database.cpp
#include "people_database.h"

std::vector<Client*> PeopleDataBase::get_clients(){
    return this->clients;
}

std::vector<Employee*>* PeopleDataBase::get_employees(){
    return &this->employees;
}

std::vector<Manager*> PeopleDataBase::get_managers(){
    return this->managers;
}

void PeopleDataBase::add_client(){
    std::string name, login, password;
    bool stop = false;
    while(!stop){
        std::cin.ignore(256,'\n');
        std::cout<<"Type your name:\n";
        std::getline(std::cin, name);
        if(name.length() < 3 || name.length() > 20 || name == "Anonymous User"){
            std::cout<<"Your name is too short/long or you tried to type incorrect name.\n";
        }
        else{
            if(this->clients.size() == 0) stop=true;
            for(auto c : this->clients){
                if(name == c->get_name()){
                    std::cout<<"This name is already taken!\n";
                }
                else stop=true;
            }
        }
    }
    stop = false;
    while(!stop){
        std::cout<<"Type your login:\n";
        std::getline(std::cin, login);
        if(login.length() < 3 || login.length() > 20){
            std::cout<<"Your login is too short/long.\n";
        }
        else{
            if(this->clients.size() == 0) stop=true;
            for(auto c : this->clients){
                if(login == c->get_login()){
                    std::cout<<"This login is already taken!\n";
                }
                else stop=true;
            }
        }
    }
    stop = false;
    std::cout<<"Type your password: \n";
    while(!stop){
        std::cin>>password;
        if(password.length() < 3){
            std::cout<<"Your password is too short.\n";
        }
        else stop = true;
    }
    this->clients.push_back(new Client(name,login,password));
}

Client* PeopleDataBase::client_login_form(Client* client){
    std::string login, password;
    int ch;
    std::cout<<"############# CLIENT LOGIN FORM ##############\n";
    std::cout<<" =LOGIN= :  ";
    std::cin.ignore(256,'\n');
    while(std::getline(std::cin, login)){
        for(auto c : this->clients){
            if(c->get_login() == login){
                std::cout<<" =PASSWORD= :  ";
                std::cin>>password;
                while(true){
                    if(c->get_password()==password){
                        delete(client);
                        return c;
                    }
                    else{
                        std::cout<<"Wrong password.\n1.Try again\n2.Exit\n";
                        std::cin>>ch;
                        while(std::cin.fail() || ch<0 || ch>2){
                            std::cin.clear();
                            std::cin.ignore(256,'\n');
                            std::cout<<"Wrong value. Try again: \n";
                            std::cin>>ch;
                        }
                        if(ch==1){
                        std::system("clear");
                        std::cout<<" =PASSWORD= :  ";
                        std::cin>>password;
                        }
                        else if(ch==2) return client;
                    }
                }
            }
        }
        std::cout<<"There is no user with this login.\n1.Try again\n2.Return\n";
        std::cin>>ch;
        while(std::cin.fail() || ch<0 || ch>2){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cout<<"Wrong value. Try again: \n";
            std::cin>>ch;
        }
        if(ch == 2)
            return client;
        else{
            std::system("clear");
            std::cout<<" =LOGIN= :  ";
        }
    }
    return client;
}

Employee* PeopleDataBase::employee_login_form(){
    std::string login, password;
    int ch;
    std::cout<<"############# EMPLOYEE LOGIN FORM ############\n";
    std::cout<<" =LOGIN= :  ";
    std::cin.ignore(256,'\n');
    while(std::getline(std::cin, login)){
        for(auto e : this->employees){
            if(e->get_login() == login){
                std::cout<<" =PASSWORD= :  ";
                std::cin>>password;
                while(true){
                    if(e->get_password()==password){
                        return e;
                    }
                    else{
                        std::cout<<"Wrong password.\n1.Try again\n2.Exit\n";
                        std::cin>>ch;
                        while(std::cin.fail() || ch<0 || ch>2){
                            std::cin.clear();
                            std::cin.ignore(256,'\n');
                            std::cout<<"Wrong value. Try again: \n";
                            std::cin>>ch;
                        }
                        if(ch==1){
                        std::system("clear");
                        std::cout<<" =PASSWORD= :  ";
                        std::cin>>password;
                        }
                        else if(ch==2) return new Employee;
                    }
                }
            }
        }
        std::cout<<"There is no user with this login.\n1.Try again\n2.Return\n";
        std::cin>>ch;
        while(std::cin.fail() || ch<0 || ch>2){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cout<<"Wrong value. Try again: \n";
            std::cin>>ch;
        }
        if(ch == 2)
            return new Employee;
        else{
            std::system("clear");
            std::cout<<" =LOGIN= :  ";
        }
    }
    return new Employee;
}

Manager* PeopleDataBase::manager_login_form(){
    std::string login, password;
    int ch;
    std::cout<<"############# MANAGER LOGIN FORM #############\n";
    std::cout<<" =LOGIN= :  ";
    std::cin.ignore(256,'\n');
    while(std::getline(std::cin, login)){
        for(auto m : this->managers){
            if(m->get_login() == login){
                std::cout<<" =PASSWORD= :  ";
                std::cin>>password;
                while(true){
                    if(m->get_password()==password){
                        return m;
                    }
                    else{
                        std::cout<<"Wrong password.\n1.Try again\n2.Exit\n";
                        std::cin>>ch;
                        while(std::cin.fail() || ch<0 || ch>2){
                            std::cin.clear();
                            std::cin.ignore(256,'\n');
                            std::cout<<"Wrong value. Try again: \n";
                            std::cin>>ch;
                        }
                        if(ch==1){
                        std::system("clear");
                        std::cout<<" =PASSWORD= :  ";
                        std::cin>>password;
                        }
                        else if(ch==2) return new Manager;
                    }
                }
            }
        }
        std::cout<<"There is no user with this login.\n1.Try again\n2.Return\n";
        std::cin>>ch;
        while(std::cin.fail() || ch<0 || ch>2){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cout<<"Wrong value. Try again: \n";
            std::cin>>ch;
        }
        if(ch == 2)
            return new Manager;
        else{
            std::system("clear");
            std::cout<<" =LOGIN= :  ";
        }
    }
    return new Manager;
}

void PeopleDataBase::show_clients() const{
    for(auto c : this->clients) std::cout<<c->get_name()<<" <-\n";
}

void PeopleDataBase::add_employee(Employee* employee){
    this->employees.push_back(employee);
}

void PeopleDataBase::show_employee_list() const{
    for(auto e : this->employees) std::cout<<e->get_name()<<" ["<<e->get_salary()<<"] - "<<EmployeePositionToString(e->get_employee_position())<<std::endl;
}

void PeopleDataBase::add_manager(Manager* manager){
    this->managers.push_back(manager);
}

void PeopleDataBase::show_managers() const{
    for(auto m : this->managers) std::cout<<m->get_name()<<" - "<<EmployeePositionToString(m->get_employee_position())<<std::endl;
}

void PeopleDataBase::load_users(){
    std::string file_name = "users.txt";
    std::string name, login, password, salary_string;
    EmployeePosition employee_position;
    Date date;
    double salary;
    std::string day, month, year;
    std::string person_type, employee_position_string;

    std::fstream file;
    file.open(file_name, std::ios::in);
    if(file.good()){
        while(!file.eof()){
            if(std::getline(file, person_type)){
                if(person_type == "CLIENT"){
                    std::getline(file, name, ';');
                    std::getline(file, login, ';');
                    std::getline(file, password, ';');
                    std::getline(file, day, ';');
                    std::getline(file, month, ';');
                    std::getline(file, year);
                    date = Date(atoi(day.c_str()), atoi(month.c_str()), atoi(year.c_str()));
                    this->clients.push_back(new Client(name, login, password, date));
                }
                else if(person_type == "EMPLOYEE" || person_type == "MANAGER"){
                    std::getline(file, name, ';');
                    std::getline(file, login, ';');
                    std::getline(file, password, ';');
                    std::getline(file, day, ';');
                    std::getline(file, month, ';');
                    std::getline(file, year, ';');
                    std::getline(file, salary_string, ';');
                    std::getline(file, employee_position_string);
                    date = Date(atoi(day.c_str()), atoi(month.c_str()), atoi(year.c_str()));
                    salary = std::stod(salary_string);
                    employee_position = StringToEmployeePosition(employee_position_string);
                    if(employee_position == manager) this->managers.push_back(new Manager(name, login, password, salary, employee_position));
                    else this->employees.push_back(new Employee(name, login, password, salary, employee_position));
                }
            }
        }
        file.close();
    }
    else std::cout<<"Wrong file name.\n";
}

void PeopleDataBase::save_users(){
    std::string file_name = "users.txt";
    std::fstream file;
    file.open(file_name, std::ios::out | std::ios::trunc | std::ios::ate);
    if(file.good() == true){
        for(auto c : clients){
            file<<"CLIENT\n"<<c->get_name()<<';'<<c->get_login()<<';'<<c->get_password()<<';'<<std::to_string(c->get_registration_date().get_day())<<';'<<std::to_string(c->get_registration_date().get_month())<<';'<<std::to_string(c->get_registration_date().get_year())<<'\n';
        }
        for(auto e : employees){
            file<<"EMPLOYEE\n"<<e->get_name()<<';'<<e->get_login()<<';'<<e->get_password()<<';'<<std::to_string(e->get_registration_date().get_day())<<';'<<std::to_string(e->get_registration_date().get_month())<<';'<<std::to_string(e->get_registration_date().get_year())<<';'<<std::to_string(e->get_salary())<<';'<<EmployeePositionToString(e->get_employee_position())<<'\n';
        }
        for(auto m : managers){
            file<<"EMPLOYEE\n"<<m->get_name()<<';'<<m->get_login()<<';'<<m->get_password()<<';'<<std::to_string(m->get_registration_date().get_day())<<';'<<std::to_string(m->get_registration_date().get_month())<<';'<<std::to_string(m->get_registration_date().get_year())<<';'<<std::to_string(m->get_salary())<<';'<<EmployeePositionToString(m->get_employee_position())<<'\n';
        }
        file.close();
    }
}

PeopleDataBase::~PeopleDataBase(){
    if(clients.empty() != true){
        for(int i = 0; i < clients.size(); i++) delete clients[i];
        clients.clear();
        clients.shrink_to_fit();
    }

    if(employees.empty() != true){
        for(int i = 0; i < employees.size(); i++) delete employees[i];
        employees.clear();
        employees.shrink_to_fit();
    }

    if(managers.empty() != true){
        for(int i = 0; i < managers.size(); i++) delete managers[i];
        managers.clear();
        managers.shrink_to_fit();
    }
}