//people.cpp
#include "person.h"

Person::Person(std::string name){
    if(name.length() < 3)
        throw std::logic_error("Your name's too short.");
    this->name = name;
    
}
Person::Person(const std::string& name, Date& date){
    if(name.length() < 3)
        throw std::logic_error("Your name's too short.");
    this->name = name;
    this->registration_date = date;
}

std::string Person::get_name(){
    return this->name;
}

Date Person::get_registration_date(){
    return this->registration_date;
}

void Person::show_registration_date(){
    std::cout<<"This account was created "<<this->registration_date.get_day()<<"."<<this->registration_date.get_month()<<"."<<this->registration_date.get_year()<<"r\n";
}

void Person::buy_a_product_or_bike(Storage& storage){
    std::string item;
    std::cout<<"Type your desired product/bike name.\n";
    std::cin.ignore(256,'\n');
    std::getline(std::cin, item);
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout<<"Wrong value. Try again: \n";
            std::getline(std::cin, item);
    }
    storage.check_in_storage(item);
}


void Person::order_a_service(Storage& storage){
    std::string service;
    std::cout<<"Type your desired product/bike name.\n";
    std::cin.ignore(256,'\n');
    std::getline(std::cin, service);
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout<<"Wrong value. Try again: \n";
        std::getline(std::cin, service);
    }
    if(storage.order_a_service(service)){
        this->ordered_services.push_back(service);
    }
}

void Person::show_ordered_services(){
    std::cout<<"Your ordered services:\n";
    for(auto s : this->ordered_services) std::cout<<s<<std::endl;
}

Person::~Person(){
    ordered_services.clear();
}