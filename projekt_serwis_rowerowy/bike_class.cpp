//bike_class.cpp
#include "bike.h"
#include "date_class.h"
#include "enum.h"

Bike::Bike(const std::string& name, const double price, const std::string& description, const Type type, const double wheel_size) : Product(name, price, description){
    this->type = type;
    this->wheel_size = wheel_size; 
}

Bike::Bike(const std::string& name, const double price, const std::string& description, const Type type, const double wheel_size, const int quantity) : Product(name, price, description, quantity){
    this->type = type;
    this->wheel_size = wheel_size; 
}

void Bike::show_full_name(){
    std::cout<<this->get_name()<<" "<<this->wheel_size<<"\' ["<<this->get_quantity()<<"] Cost: "<< this->get_price()<<"\n";
}

double Bike::get_wheel_size() const{
    return this->wheel_size;
}

Type Bike::get_bike_type() const{
    return this->type;
}

Bike::~Bike(){}