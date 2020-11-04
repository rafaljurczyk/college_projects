// basic_product_class.cpp
#include "product.h"

Basic_Product::Basic_Product(const std::string& name, const double price, const std::string& description){
    this->name = name;
    this->description = description;
    try{
        if (price < 0.0f)
            throw std::logic_error("za niska cena");
        this->price = price;
        this->basic_price = price;
    } catch (std::exception& e){
        std::cerr << e.what() << '\n';
    }
}

std::string Basic_Product::get_name(){
    return this->name;
}


double Basic_Product::get_price() const{
    return this->price;
}

std::string Basic_Product::get_description() const{
    return this->description;
}



/*
void Basic_Product::set_discount(double & discount_percantage){
    try{
        if(discount_percantage < 0 || discount_percantage > 100)
            throw std::logic_error("nieprawidłowy procent zniżki");
        this->price *= (discount_percantage/100);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}


void Basic_Product::cancel_discount(){
    this->price = this->basic_price;
}

void Basic_Product::set_new_price(double & new_price){
    try{
        if (new_price < 0.0f)
            throw std::logic_error("za niska cena");
        this->price = new_price;
        this->basic_price = new_price;
    } catch (std::exception& e){
        std::cerr << e.what() << '\n';
    }
}
*/

Basic_Product::~Basic_Product(){
}
