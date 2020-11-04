//bike.h
#ifndef BIKE_H
#define BIKE_H
#include "date_class.h"
#include "basic_product.h"
#include "product.h"
#include "enum.h"
#include <iostream>
#include <string>

//this is basicly example more advanced product
class Bike : public Product{
    Type type;
    double wheel_size;
public:
    Bike(const std::string& name, const double price, const std::string& description, const Type type, const double wheel_size);
    Bike(const std::string& name, const double price, const std::string& description, const Type type, const double wheel_size, const int quantity);
    virtual void show_full_name() override;
    double get_wheel_size() const;
    Type get_bike_type() const;
    ~Bike();
};

#endif