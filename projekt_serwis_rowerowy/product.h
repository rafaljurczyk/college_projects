//products.h
#ifndef PRODUCT_H
#define PRODUCT_H
#include "date_class.h"
#include "basic_product.h"
#include "enum.h"
#include <iostream>
#include <string>

//base product class for little stuff like tube or handlebar
class Product : public Basic_Product{
    int quantity;
public:
    Product(const std::string& name, const double price, const std::string& description);
    Product(const std::string& name, const double price, const std::string& description, const int quantity);
    /*Add amount we pass to our product/bike quantity*/
    void add_quantity(int amount);
    /*Subtract amount we pass to our product/bike quantity*/
    void subtract_quantity(int amount);
    int get_quantity() const;
    virtual void show_full_name() override;
    ~Product();
};

#endif