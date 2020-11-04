//client.cpp
#include "client.h"

Client::Client() : Person("Anonymous User") {}
Client::Client(const std::string& name, const std::string& login, const std::string& password) : Person(name){
    if(login.length() < 3)
        throw std::logic_error("Your name's too short.");
    else if(login.length() > 20)
        throw std::logic_error("Your name's too long.");
    if(password.length() < 3)
        throw std::logic_error("Your password's too short.");
    this->login = login;
    this->password = password;
}
Client::Client(const std::string& name, const std::string& login, const std::string& password, Date& date) : Person(name, date){
    if(login.length() < 3)
        throw std::logic_error("Your name's too short.");
    else if(login.length() > 20)
        throw std::logic_error("Your name's too long.");
    if(password.length() < 3)
        throw std::logic_error("Your password's too short.");
    this->login = login;
    this->password = password;
}

std::string Client::get_login(){
    return this->login;
}

std::string Client::get_password(){
    return this->password;
}

void Client::add_event(Storage& storage){
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
    storage.add_event(new Event(name, description, tmp_date, false));
    delete tmp_date;
    
}

