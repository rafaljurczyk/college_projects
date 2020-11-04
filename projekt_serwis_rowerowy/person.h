// people.h
#ifndef PERSON_H
#define PERSON_H
#include "date_class.h"
#include "storage.h"
#include<iostream>

/*Base class for all clients/employees/managers*/
class Person{
    std::string name;
    Date registration_date;
    std::vector<std::string> ordered_services;
public:
    Person(std::string name);
    Person(const std::string& name, Date& date);
    void buy_a_product_or_bike(Storage& storage);
    void order_a_service(Storage& storage);
    std::string get_name();
    void show_registration_date();
    void show_ordered_services();
    Date get_registration_date();
    virtual void add_event(Storage& storage) = 0;
    ~Person();
};

#endif