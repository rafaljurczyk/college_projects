//product_class.cpp
#include "product.h"


Product::Product(const std::string& name, const double price, const std::string& description) : Basic_Product(name, price, description){
    this->quantity = 0;
}

Product::Product(const std::string& name, const double price, const std::string& description, const int quantity) : Basic_Product(name, price, description){
    this->quantity = quantity;
}

void Product::add_quantity(int ammount){
    this->quantity += ammount;
}

void Product::subtract_quantity(int ammount){
    this->quantity -= ammount;
}

int Product::get_quantity() const{
    return this->quantity;
}

void Product::show_full_name(){
    std::cout<<this->name<<"["<<this->quantity<<"] Cost: "<< this->get_price()<<"\n";
}

Product::~Product(){
}