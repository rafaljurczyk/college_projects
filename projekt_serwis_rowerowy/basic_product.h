//basic_product.h
#ifndef BASIC_PRODUCT_H
#define BASIC_PRODUCT_H
#include "date_class.h"
#include "enum.h"
#include <iostream>
#include <string>

//virtual class created so I can put all of the remaining products/bikes/services in one vector
class Basic_Product{
protected:
    std::string name;
    double price;
    double basic_price;
    std::string description;
public:
    Basic_Product(const std::string& name, const double price, const std::string& description);
    virtual void show_full_name() = 0;
    std::string get_name();
    double get_price() const;
    std::string get_description() const;
    ~Basic_Product();
    //void set_discount(double & discount_percentage);
    //void set_new_price(double & new_price);
    //void cancel_discount();
};

#endif